# ImageResizer
A simple C++ program to resize image files. Supports PNG, JPEG and TIFF file formats. 

# How to use
Currently supports four flags:
| Flag | Description |
|------|-------------|
| -f | Path of the file you want to resize. Either this or ``` -d ``` are required. |
| -d | Directory containing files you want to resize. Will resize all files in the directory. Either this or ``` -f ``` are required. |
| -w | New image width. This is a required flag. |
| -h | New image height. This is a required flag. |

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
- [x] Implement "-d" flag for changing the size of a directory of image files
