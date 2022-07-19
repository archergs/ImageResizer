CC=g++

imageresizer: main.cpp
	$(CC) -o imageresizer main.cpp -I/opt/homebrew/include/ -L/opt/homebrew/lib -lpng -ljpeg -lz
