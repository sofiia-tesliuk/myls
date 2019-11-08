#include "additionals.h"


void convert_time(unsigned long seconds, char *date_string, char *time_string){
    time_t curr_time;
    tm * curr_tm;

    time(&curr_time);
    curr_tm = localtime(&curr_time);

    strftime(date_string, 12, "%Y-%m-%d", curr_tm);
    strftime(time_string, 10, "%T", curr_tm);
}


int directory_contents(std::string &path, std::vector<std::string> &contents){
    if (boost::filesystem::is_directory(path)){
        boost::filesystem::directory_iterator end_itr;

        for (boost::filesystem::directory_iterator itr(path); itr != end_itr; ++itr){
            contents.emplace_back(itr->path().string());
        }
    } else{
        std::cerr << "Given path is not directory: " << path << std::endl;
        return -1;
    }
    return 0;
}