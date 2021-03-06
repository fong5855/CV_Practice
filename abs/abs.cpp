﻿#include<iostream>
#include<fstream>
#include "abs.h"

#define IMG_SIZE (480*640)

float* Abs::read(char* path)
{
  float* fxyz = new float[IMG_SIZE];

  std::ifstream file(path);
  if (!file.is_open())
  {
    std::cout << "Can not open file" << path << std::endl;
    fxyz[0] = READ_ERROR;
    return fxyz;
  }

  // locate a small size
  char *lines = new char[200];
  // int row = 0, col = 0;
  int row = 0, col = 0;
  // line 1
  file >> row;
  file.getline(lines, 200);
  // line 2
  file >> col;
  file.getline(lines, 200);
  // line 3
  file.getline(lines, 200);

  int len = row * col;

  delete[] lines;
  delete[] fxyz;
  /*
  fxyz contain 4 informations of each pixel
  1. f: if f value is 0, the x,z,y is unknown value.
  2. x, y, z: the 3D points.
  if correspondance f is 0, the value will be 999
  */
  fxyz = new float[len * 4];

  for (int i = 0; i < len * 4; i++)
  {
    file >> fxyz[i];
  }
  file.close();

  return fxyz;
}

// for python use
extern "C" {
  __declspec(dllexport) Abs* abs_new() { return new Abs(); }
  __declspec(dllexport) float* abs_read(Abs* foo, char* path) { return foo->read(path); }
}
