cmake_minimum_required(VERSION 2.8)
project(LaserTank)

# Use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${LaserTank_SOURCE_DIR}/cmake")

# Bump up warning levels appropriately for clang, gcc & msvc
# Also set debug/optimization flags depending on the build type. IDE users choose this when
# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()


if (${CMAKE_SYSTEM_NAME} MATCHES "Linux" OR
    ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR
    ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    include("${LaserTank_SOURCE_DIR}/platform/sdl2/platform.cmake")
endif()

add_executable(LaserTank
    ${PLATFORM_SRC}
    LaserTank.cpp
    image.cpp
    render.cpp)

target_link_libraries(LaserTank ${PLATFORM_LIBS})