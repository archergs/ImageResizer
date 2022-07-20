# ImageResizer
A simple C++ program to resize image files. Supports PNG, JPEG and TIFF file formats. 

# How to use
Currently supports three (mandatory) flags:
| Flag | Description |
|------|-------------|
| -f | Directory of the file you want to resize |
| -w | New image width |
| -h | New image height |

# Building
## macOS
``` 
brew install libpng libjpeg libtiff cimg
make 
```

## Linux
``` 
sudo apt update && sudo apt upgrade 
sudo apt install build-essentials zlib1g-dev libpng-dev libjpeg-dev libtiff-dev cimg-dev 
g++ -o imageresizer main.cpp -lpng -ljpeg -ltiff -lz 
```

## Windows
Support is coming soon

# To-do
- [ ] Support Linux and Windows in the Makefile
- [ ] Implement "-d" flag for changing the size of a directory of image files
