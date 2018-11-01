csrc = $(wildcard src/*.cpp)
ccsrc = $(wildcard ./*.cpp)
DEPENDS = $(csrc:.cpp=.d)
obj = $(csrc:.c=.o) $(ccsrc:.cc=.o)
PROGRAM = glutapp

CC       = g++
CFLAGS   = -w $(OPTFLAGS)

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