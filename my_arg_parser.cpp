#include "my_arg_parser.h"


int parse_arguments(int argc, char** argv, myConfig &config){
    // TODO: take to attention name of files in quotes
//    bool in_quotes = false;
    int i = 1;
    bool only_files = false;
    std::set<char> sorting_methods = {'U', 'S', 't', 'D', 's'};

    for(i = 1; i < argc; i++){
            size_t len = strlen(argv[i]);
            if (strncmp(argv[i], "-", 1) == 0){
                if (len == 2){
                    switch(argv[i][1]){
                        case 'l':
                            config.detailed_info = true;
                            break;
                        case 'r':
                            config.reversed_order = true;
                            break;
                        case 'F':
                            config.specify_type = true;
                            break;
                        case 'R':
                            config.iter_recursively = true;
                            break;
                        case '-':
                            only_files = true;
                            break;
                        default:
                            std::cerr << "Unknown option: " << argv[i][1] << std::endl;
                            return -1;
                    }
                    if (only_files)
                        break;
                } else if (strncmp(argv[i], "--sort", 6) == 0){
                    for (int j = 6; j < len; j++){
                        if (sorting_methods.find(argv[i][j]) != sorting_methods.end()){
                            config.sorting.emplace_back(argv[i][j]);
                        } else{
                            std::cerr << "Unknown sorting method: " << argv[i][j] << std::endl;
                            return -2;
                        }
                    }
                } else{
                    std::cerr << "Unknown option: " << argv[i] << std::endl;
                    return -3;
                }
            } else{
                // TODO: take to attention names in quotes
               config.objects.emplace_back(argv[i]);
            }
    }

    // all further arguments are files or directories
    for (; i < argc; i++){
        // TODO: take to attention names in quotes
        config.objects.emplace_back(argv[i]);
    }

    return 0;
}