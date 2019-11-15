#ifndef MYLS_COMPARARTORS_H
#define MYLS_COMPARARTORS_H


#include "additionals.h"
//
//std::cout << "\tU -- unsorted." << std::endl;
//std::cout << "\tS -- by size." << std::endl;
//std::cout << "\tt -- by time of last modification." << std::endl;
//std::cout << "\tN -- by name (default option)." << std::endl;
//std::cout << "\tD -- directories first." << std::endl;
//std::cout << "\ts -- specific files separately." << std::endl;
//std::cout << "-r -- reversed order of sorted option." << std::endl;
//std::cout << "-F -- specify type of special files." << std::endl;
//std::cout << "-R -- bypass directories recursively." << std::endl;

bool bySize(const myStat& a, const myStat& b);
bool byTimeOfLastModification(const myStat& a, const myStat& b);
bool byName(const myStat& a, const myStat& b);
bool directoriesFirst(const myStat& a, const myStat& b);
bool specialFilesSeparately(const myStat& a, const myStat& b);



#endif //MYLS_COMPARARTORS_H
