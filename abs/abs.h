﻿#pragma once
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