CC = g++
OUT = spacer

SRC = $(shell find src -name '*.cpp')
OBJ = $(patsubst %.cpp, %.o, $(SRC))

CFLAGS = -Iinclude
CFLAGS += -Llib
CFLAGS += `pkg-config --static --libs glfw3`
CFLAGS += -lfreeimage
CFLAGS += -llowg

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	-find src -type f -name '*.o' -delete
	-rm $(OUT)

