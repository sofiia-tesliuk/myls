#include "io_manager.h"


int IOManager::read_buffer(int fd, char* buffer, ssize_t size, int* status){
    ssize_t read_bytes = 0;
    while (read_bytes < size){
        ssize_t read_now = read(fd, buffer + read_bytes, size - read_bytes);
        if (read_now == -1){
            if (errno == EINTR)
                continue;
            else{
                *status = errno;
                return EXIT_FAILURE;
            }
        } else
            read_bytes += read_now;
    }
    return EXIT_SUCCESS;
}

int IOManager::write_buffer(int fd, const char* buffer, ssize_t size, int* status){
    ssize_t written_bytes = 0;
    while (written_bytes < size){
        ssize_t written_now = write(fd, buffer + written_bytes, size - written_bytes);
        if (written_now == -1){
            if (errno == EINTR)
                continue;
            else{
                *status = errno;
                return EXIT_FAILURE;
            }
        } else
            written_bytes += written_now;
    }
    return EXIT_SUCCESS;
}
