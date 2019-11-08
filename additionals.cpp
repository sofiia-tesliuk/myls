#include "additionals.h"


void convert_time(unsigned long seconds, char *date_string, char *time_string){
    time_t curr_time;
    tm * curr_tm;

    time(&curr_time);
    curr_tm = localtime(&curr_time);

    strftime(date_string, 50, "%d-%d-%Y", curr_tm);
    strftime(time_string, 50, "%T", curr_tm);
}