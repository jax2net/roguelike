CC=g++
LIBS=-lSDL2
W=-Wall
EXEC=game
INCLUDES=-L/usr/include/SDL2/

make: main.cpp draw.cpp framebuffer.cpp helper.cpp movement.cpp player.cpp
	$(CC) $(W) main.cpp draw.cpp framebuffer.cpp helper.cpp movement.cpp player.cpp -o $(EXEC) $(INCLUDES) -LSDL2main $(LIBS)
