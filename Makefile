CC=g++

imageresizer: main.cpp
	$(CC) -std=gnu++17 -o imageresizer main.cpp -I/opt/homebrew/include/ -L/opt/homebrew/lib -lpng -ljpeg -ltiff -lz
