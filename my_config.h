#ifndef MYLS_MYCONFIG_H
#define MYLS_MYCONFIG_H

#include <iostream>
#include <vector>
#include <string>


struct myConfig{
    // -h, --help | Help option
    bool help = false;
    // -l | detailed information
    bool detailed_info = false;
    // --sort | sorting by
    std::vector<char> sorting;
    // -r | reversed order of sorting
    bool reversed_order = false;
    // -F | specify type of file
    bool specify_type = false;
    // -R | iterate in directories recursively
    bool iter_recursively = false;
    // vector of files or directories
    std::vector<std::string> objects;
};

void help_option();

#endif //MYLS_MYCONFIG_H
