# Look up SDL2 and add the include directory to our include path
find_package(SDL2     REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

set(PLATFORM_SRC
    platform/sdl2/main.cpp
    platform/sdl2/func.cpp
    platform/sdl2/kosFile.cpp
    platform/sdl2/kosSyst.cpp)

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    list(APPEND PLATFORM_SRC platform/sdl2/linux/getexepath.cpp)
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    list(APPEND PLATFORM_SRC platform/sdl2/macosx/getexepath.cpp)
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    list(APPEND PLATFORM_SRC platform/sdl2/windows/getexepath.cpp)
endif()


set(PLATFORM_LIBS ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} m)
