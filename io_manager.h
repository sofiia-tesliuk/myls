#ifndef MYLS_IO_MANAGER_H
#define MYLS_IO_MANAGER_H

#include <iostream>
//#include <iomanip>
//#include <fcntl.h>
#include <unistd.h>


class IOManager{
public:
    int read_buffer(int fd, char* buffer, ssize_t size, int* status);

    int write_buffer(int fd, const char* buffer, ssize_t size, int* status);
};

#endif //MYLS_IO_MANAGER_H
