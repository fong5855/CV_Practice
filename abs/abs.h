// abs.h: 標準系統之 include 檔案的 include 檔案，
// 或專案專屬的 Include 檔案。
#pragma once
#ifndef AbsRead_H
#define AbsRead_H

#include <stdio.h>
#include <iostream>
#include <fstream>

#define READ_ERROR -1

class Abs
{
public:
  float* read(char* path);
};

#endif // !AbsRead_H