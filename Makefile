
CXX ?= g++

CXXFLAGS += -std=c++11 `pkg-config --cflags sdl2 SDL2_ttf`
LDFLAGS  += -lm `pkg-config --libs sdl2 SDL2_ttf`

SRC = linux/func.cpp \
      linux/kosFile.cpp \
      linux/kosSyst.cpp

SRC += LaserTank.cpp \
       image.cpp \
       render.cpp

OBJ = $(SRC:.cpp=.o)

EXE = LaserTank

all : $(EXE)

$(EXE) : $(OBJ)
	$(CXX) -o $(EXE) $(OBJ) $(LDFLAGS) 

clean:
	rm -f $(EXE) $(OBJ)
