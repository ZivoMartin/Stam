S_DIR=src
B_DIR=build

S_FILES=$(S_DIR)/main.cpp $(S_DIR)/Application.cpp $(S_DIR)/Entity.cpp
EXEC=$(B_DIR)/stam

CC=g++
CFLAGS=-Wall `sdl2-config --cflags` `pkg-config --cflags SDL2_image`
LDFLAGS=`sdl2-config --libs` `pkg-config --libs SDL2_image`

all: build_run


$(EXEC): $(S_FILES)
	mkdir -p $(B_DIR)
	$(CC) $(CFLAGS) $(S_FILES) -o $(EXEC) $(LDFLAGS)


build_run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(B_DIR)/*
