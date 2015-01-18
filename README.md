# laser-tank
Port of the Laser Tank game to Linux initially written for KolibriOS: http://habrahabr.ru/post/248001

# Build

**Depends:**
- SDL2
- SDL2_ttf
- C++ Compiler with C++11 support
- cmake

On Ubuntu Trusty (14.04) or Mint 17.x:
```
sudo apt-get install libsdl2-dev libsdl2-ttf-dev cmake g++
```

On OpenSUSE:
```
sudo yast2 -i libSDL2-devel libSDL2_ttf-devel cmake gcc-c++
```

On MacOS X with brew:
```
brew install cmake sdl2 sdl2_image sdl2_ttf
```


Create directory for build:
```
mkdir build
cd build
cmake ..
make -j8
```

Copy resources near executable (or make links):
```
cp ../data.lvl ../data01.pak ../data02.pak ../DejaVuSans.ttf .
```

Run game:
```
./LaserTank
```

Enjoy!

# Issues

- Blink on tank moving
- Not clean code

In any case game ported for fun and merge requests welcomed ;-)
