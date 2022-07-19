//
//  main.cpp
//  ImageResizer
//
//  Created by Archer Gardiner-Sheridan on 18/7/2022.
//

#include <iostream>
#include <sstream>

#define cimg_display 0
#define cimg_use_png  1
#define cimg_use_jpeg 1

#include "CImg.h"

using namespace cimg_library;

bool USING_DIRECTORY = false;
int FILE_COUNT = 0;
std::string SINGLE_FILENAME = "";

int main(int argc, const char * argv[]) {
    
    int width = 0;
    int height = 0;
    
    std::cout << "Welcome to Image Resizer\n";
    
    // get program args
    for (int i = 1; i < argc; i++){
        std::string arg = argv[i];
        
        if (arg == "-d"){
            if (argv[i+1] != NULL){
                std::string directory = argv[i+1];
                std::cout << "Operating on directory: " + directory << std::endl;
                USING_DIRECTORY = true;
            }
        } else if (arg == "-f"){
            if (argv[i+1] != NULL){
                std::string filename = argv[i+1];
                USING_DIRECTORY = false;
                FILE_COUNT = 1;
                SINGLE_FILENAME = filename;
            }
        }
        
        if (arg == "-w"){
            if (argv[i+1] != NULL){
                std::stringstream sWidth(argv[i+1]);
                
                sWidth >> width;
                std::cout << "Applying width: " + std::to_string(width) << std::endl;
            }
        }
        
        if (arg == "-h"){
            if (argv[i+1] != NULL){
                std::stringstream sHeight(argv[i+1]);
                sHeight >> height;
                std::cout << "Applying height: " + std::to_string(height) << std::endl;
            }
        }
    }
    
    if (USING_DIRECTORY){
        // get all files from directory
        for(int i = 0; i < FILE_COUNT; i++){
            
        }
        
        std::cout << "Directory operation completed" << std::endl;
        
    } else {
        std::cout << "Operating on file: " + SINGLE_FILENAME << std::endl;
        
        int size = SINGLE_FILENAME.length();
        char filename_array[size + 1];
        strcpy(filename_array, SINGLE_FILENAME.c_str());
        CImg<unsigned char> image(filename_array);
        
        image.resize(width, height);
        image.save(filename_array);
        std::cout << "File operation completed" << std::endl;
    }
    
    return 0;
}
