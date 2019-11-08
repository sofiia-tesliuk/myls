#ifndef MYLS_ADDITIONALS_H
#define MYLS_ADDITIONALS_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "boost/filesystem.hpp"


void convert_time(unsigned long seconds, char *date_string, char *time_string);

int directory_contents(std::string &path, std::vector<std::string> &contents);

bool is_wildcard(std::string path);

int wildcard_matching(std::string wildcard, std::vector<std::string> &matched_objects);

#endif //MYLS_ADDITIONALS_H
