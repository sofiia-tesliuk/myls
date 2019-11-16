#ifndef MYLS_COMPARARTORS_H
#define MYLS_COMPARARTORS_H


#include "additionals.h"
#include <iostream>
#include <set>
#include <sys/stat.h>

#include "my_config.h"


// 0 -- a == b
// -1 -- a < b
// 1 -- a > b
int bySize(const myStat& a, const myStat& b);

int byTimeOfLastModification(const myStat& a, const myStat& b);

int byName(const myStat& a, const myStat& b);

int directoriesFirst(const myStat& a, const myStat& b);

int specialFilesSeparately(const myStat& a, const myStat& b);

std::set<myStat> build_set_with_comparator(myConfig &config);

#endif //MYLS_COMPARARTORS_H
