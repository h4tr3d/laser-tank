#include <stdint.h>
#include <string.h>
#include <mach-o/dyld.h>

int getexepath(char *exepath)
{
    char path[1024];
    uint32_t size = sizeof(path);
    if(_NSGetExecutablePath(path, &size) == 0) {
        memcpy(exepath, path, size);
    }
    return size > 0 ? size : -1;
}

