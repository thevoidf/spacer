CC = g++
OUT = spacer

SRC = $(shell find src -name '*.cpp')
OBJ = $(patsubst %.cpp, %.o, $(SRC))

CFLAGS = -Iinclude
CFLAGS += -I/usr/include/freetype2
CFLAGS += -Llib
CFLAGS += `pkg-config --static --libs glfw3`
CFLAGS += -llowg
CFLAGS += -lfreeimage
CFLAGS += -lfreetype
CFLAGS += -lfreetype-gl

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	-find src -type f -name '*.o' -delete
	-rm $(OUT)

