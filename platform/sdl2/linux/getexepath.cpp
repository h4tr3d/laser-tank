#include <unistd.h>

int getexepath(char *exepath)
{
    ssize_t count = readlink( "/proc/self/exe", exepath, 1024);
    return count > 0 ? count : -1;
}
