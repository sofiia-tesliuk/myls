#include "comparartors.h"


int bySize(const myStat& a, const myStat& b){
    if (a.fileStat.st_size < b.fileStat.st_size)
        return -1;
    else if (a.fileStat.st_size > b.fileStat.st_size)
        return 1;
    return 0;
}

int byTimeOfLastModification(const myStat& a, const myStat& b){
    if (a.fileStat.st_mtimespec.tv_sec < b.fileStat.st_mtimespec.tv_sec)
        return -1;
    else if (a.fileStat.st_mtimespec.tv_sec > b.fileStat.st_mtimespec.tv_sec)
        return 1;
    return 0;
}

int byName(const myStat& a, const myStat& b){
    return a.filename.compare(b.filename);
}

int directoriesFirst(const myStat& a, const myStat& b){
    if (S_ISDIR(a.fileStat.st_mode)){
        if (S_ISDIR(b.fileStat.st_mode)){
            return 0;
        } else
            return -1;
    }
    return 1;
}

int specialFilesSeparately(const myStat& a, const myStat& b){
    if (S_ISREG(a.fileStat.st_mode)){
        if (S_ISREG(b.fileStat.st_mode)){
            return 0;
        } else{
            return -1;
        }
    }
    return 1;
}


std::set<myStat> build_set_with_comparator(myConfig &config){
    std::function<bool(const myStat& a, const myStat& b)> x1 = [](const myStat& a, const myStat& b) -> bool{return byName(a, b) < 0;};
    for(auto c: config.sorting){
        switch(c){
            case 'S':{
                std::function<bool(const myStat& a, const myStat& b)> x1 = [&x1](const myStat& a, const myStat& b) ->
                        bool{if (bySize(a, b) == 0) return x1(a, b); else return bySize(a, b) < 0;};
                break;
            }
            case 't':{
                std::function<bool(const myStat& a, const myStat& b)> x1 = [&x1](const myStat& a, const myStat& b) ->
                        bool{if (byTimeOfLastModification(a, b) == 0) return x1(a, b); else return byTimeOfLastModification(a, b) < 0;};
                break;
            }
            case 'N':{
                std::function<bool(const myStat& a, const myStat& b)> x1 = [&x1](const myStat& a, const myStat& b) ->
                        bool{if (byName(a, b) == 0) return x1(a, b); else return byName(a, b) < 0;};
                break;
            }
            case 'D':{
                std::function<bool(const myStat& a, const myStat& b)> x1 = [&x1](const myStat& a, const myStat& b) ->
                        bool{if (directoriesFirst(a, b) == 0) return x1(a, b); else return directoriesFirst(a, b) < 0;};
                break;
            }
            case 's':{
                std::function<bool(const myStat& a, const myStat& b)> x1 = [&x1](const myStat& a, const myStat& b) ->
                        bool{if (specialFilesSeparately(a, b) == 0) return x1(a, b); else return specialFilesSeparately(a, b) < 0;};
                break;
            }
            default:
                std::cerr << "Unrecognized sorting option." << std::endl;
                break;
        }
    }
    std::set<myStat, bool(const myStat& a, const myStat& b)> newSet(&x1);
    return newSet;
}
