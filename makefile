csrc = $(wildcard src/*.cpp)
ccsrc = $(wildcard ./*.cpp)
DEPENDS = $(csrc:.cpp=.d)
obj = $(csrc:.c=.o) $(ccsrc:.cc=.o)
PROGRAM = glutapp

CC       = g++
<<<<<<< HEAD
CFLAGS   = -w $(OPTFLAGS)
=======
CFLAGS   = -w $(OPTFLAGS) -ISOIL/includes -std=c++11 -pthread
>>>>>>> 8386071ca906b9ad5d4453c6d26404a8918b8187

LDFLAGS = $(libgl) -lpng -lz -lm

ifeq ($(shell uname -s), Darwin)
	LDFLAGS = -framework GLUT -framework OpenGL
else
	LDFLAGS = -lGL -lglut
endif

all: $(PROGRAM)

$(PROGRAM):$(obj)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

%.d: %.cpp
	$(CC) -MM $(CFLAGS) $< > $@



ifneq ($(MAKECMDGOALS),clean)
-include $(DEPENDS)
endif