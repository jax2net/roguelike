CC=g++
LIBS=-lSDL2main -lSDL2
W=-Wall
EXEC=game
INCLUDES=-I/usr/include/SDL2

make: main.cpp draw.cpp framebuffer.cpp helper.cpp movement.cpp player.cpp
	$(CC) $(W) $(INCLUDES) $(LIBS) main.cpp draw.cpp framebuffer.cpp helper.cpp movement.cpp player.cpp -o $(EXEC)
