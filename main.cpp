#include <iostream>
#include <map>

#include <boost/filesystem.hpp>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "my_config.h"
#include "my_arg_parser.h"
#include "additionals.h"


void print_object(myConfig &config, std::string &objectname, struct stat &object_stat){
    // Object is a directory
    if (S_ISDIR(object_stat.st_mode)){
        std::cout << "/";
    } else if (config.specify_type){
        if ((object_stat.st_mode & S_IEXEC) != 0){
            // Object is executable
            std::cout << "*";
        } else if(S_ISLNK(object_stat.st_mode)){
            // Object is symbolic link
            std::cout << "@";
        } else if(S_ISSOCK(object_stat.st_mode)){
            // Object is socket
            std::cout << "=";
            // TODO: check if NAMED CHANEL
        } else if (!S_ISREG(object_stat.st_mode)){
            // Others
            std::cout << "?";
        }
    }
    // name
    std::cout << objectname << "\t";
    if (config.detailed_info){
        // size, date and time of last modification
        char date_string[20];
        char time_string[20];
        convert_time(static_cast<unsigned long>(object_stat.st_mtimespec.tv_sec), date_string, time_string);
        std::cout << object_stat.st_size << "\t" << date_string << " " << time_string << std::endl;
    }
}

void process_objects(myConfig &config, std::vector<std::string> &objects){
    std::map<std::string, struct stat> object_info;

    for (auto &object: objects){
        if (boost::filesystem::exists(object)){
            struct stat object_stat;
            if (stat(object.c_str(), &object_stat) == 0){
                print_object(config, object, object_stat);
                object_info.insert(std::pair<std::string, struct stat>(object, object_stat));
            } else{
                std::cerr << "Unable to get stat: " << object << std::endl;
                std::cout << errno << std::endl;
            }
        } else{
            std::cerr << "File does not exists: " << object << std::endl;
        }
    }

    // TODO: sorting


}

void process_directory(myConfig &config, std::string &path, struct stat &dir_stat){
    if (!config.detailed_info){
        std::cout << std::endl;
    }
    std::vector<std::string> contents;
    directory_contents(path, contents);
    print_object(config, path, dir_stat);
    if (!config.detailed_info){
        std::cout << std::endl;
    }
    process_objects(config, contents);
}

void process_wildcard(){
    // TODO: get names of files, which satisfies wildcard
    // TODO: process files
}


int main(int argc, char** argv){
    myConfig config;
    if (parse_arguments(argc, argv, config) != 0){
        std::cerr << "Unable to parse arguments properly." << std::endl;
        return -1;
    }

    if (config.help){
        help_option();
        return 0;
    }

    for (auto &object: config.objects){
        // TODO: check for wildcard and process_objects
        if (boost::filesystem::exists(object)){
            struct stat object_stat;
            if (stat(object.c_str(), &object_stat) == 0){
                if (boost::filesystem::is_directory(object)){
                    process_directory(config, object, object_stat);
                }else{
                    print_object(config, object, object_stat);
                }
            } else{
                std::cerr << "Unable to get stat of: " << object << std::endl;
            }
        } else{
            std::cerr << "File does not exists: " << object << std::endl;
        }
    }
    return 0;
}