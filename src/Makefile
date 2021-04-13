CC=g++
LIBS=-lSDL2
W=-Wall
EXEC=game
LINKER=-lSDL2main -lSDL2
INCLUDES=-I/usr/include/SDL2

make: main.cpp draw.cpp framebuffer.cpp helper.cpp movement.cpp player.cpp
	$(CC) $(W) $(INCLUDES) $(LINKER) $(LIBS) main.cpp draw.cpp framebuffer.cpp helper.cpp movement.cpp player.cpp -o $(EXEC)
