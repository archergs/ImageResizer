//
//  main.cpp
//  ImageResizer
//
//  Created by Archer Gardiner-Sheridan on 18/7/2022.
//

#include <filesystem>
#include <iostream>
#include <sstream>

#define cimg_display 0
#define cimg_use_png 1
#define cimg_use_jpeg 1
#define cimg_use_tiff 1

#include "CImg.h"

using namespace cimg_library;
using namespace std;

bool USING_DIRECTORY = false;
int FILE_COUNT = 0;

void resize_operation(string path, int width, int height) {
  int size = path.length();
  char filename_array[size + 1];
  strcpy(filename_array, path.c_str());
  CImg<unsigned char> image(filename_array);

  image.resize(width, height);
  image.save(filename_array);
}

int main(int argc, const char* argv[]) {
  int width = -1;
  int height = -1;
  string single_filename = "";
  string directory = "";

  cout << "Welcome to Image Resizer\n";

  // get program args
  for (int i = 1; i < argc; i++) {
    string arg = argv[i];

    if (arg == "-d") {
      if (argv[i + 1] != NULL) {
        directory = argv[i + 1];
        cout << "Operating on directory: " + directory << endl;
        USING_DIRECTORY = true;
      }
    } else if (arg == "-f") {
      if (argv[i + 1] != NULL) {
        string filename = argv[i + 1];
        USING_DIRECTORY = false;
        FILE_COUNT = 1;
        single_filename = filename;
      }
    }

    if (arg == "-w") {
      if (argv[i + 1] != NULL) {
        stringstream sWidth(argv[i + 1]);

        sWidth >> width;
        cout << "Applying width: " + to_string(width) << endl;
      }
    }

    if (arg == "-h") {
      if (argv[i + 1] != NULL) {
        stringstream sHeight(argv[i + 1]);
        sHeight >> height;
        cout << "Applying height: " + to_string(height) << endl;
      }
    }
  }

  if (height <= -1 || width <= -1 ||
      (single_filename == "" && USING_DIRECTORY == false)) {
    cout << "Invalid arguments" << endl;
    return 0;
  }

  if (USING_DIRECTORY) {
    // get all files from directory
    for (const auto& entry : filesystem::directory_iterator(directory)) {
      string filepath = entry.path();
      cout << "Operating on file: " << filepath << endl;
      resize_operation(filepath, width, height);
    }

    cout << "Directory operation completed" << endl;

  } else {
    cout << "Operating on file: " + single_filename << endl;
    resize_operation(single_filename, width, height);
    cout << "File operation completed" << endl;
  }

  return 0;
}
