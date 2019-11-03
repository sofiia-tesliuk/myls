#include <iostream>
#include "my_config.h"
#include "my_arg_parser.h"

int main(int argc, char** argv){
    myConfig config;
    if (parse_arguments(argc, argv, config) != 0){
        std::cerr << "Unable to parse arguments properly." << std::endl;
        return -1;
    }

    if (config.help){
        std::cout << "List files and directories in specified order." << std::endl;
        std::cout << "Usage: myls [path|mask] [-l] [-h|--help] [--sort=U|S|t|X|D|s] [-r]" << std::endl;
        std::cout << "-l -- print detailed information about each file / directory." << std::endl;
        std::cout << "-h|--help -- help screen." << std::endl;
        std::cout << "--sort -- sorting option." << std::endl;
        std::cout << "\tU -- unsorted." << std::endl;
        std::cout << "\tS -- by size." << std::endl;
        std::cout << "\tt -- by time of last modification." << std::endl;
        std::cout << "\tN -- by name (default option)." << std::endl;
        std::cout << "\tD -- directories first." << std::endl;
        std::cout << "\ts -- specific files separately." << std::endl;
        std::cout << "-r -- reversed order of sorted option." << std::endl;
        std::cout << "-F -- specify type of special files." << std::endl;
        std::cout << "-R -- bypass directories recursively." << std::endl;
        return 0;
    }

    // TODO: check if each passed file in arguments exists
    // TODO: get info about each file
    // TODO: sort and print files


    return 0;
}