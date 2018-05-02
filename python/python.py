from ctypes import *
from numpy.ctypeslib import ndpointer
import sys
import numpy as np
import time


# generate by visual studio
# lib = windll.LoadLibrary("ReadAbs_Dll.dll")
# generate by cmake
lib = windll.LoadLibrary("ABSLIB.dll")

class ABS:
    """ A wrapper of c++ class
    member function:
        read(path) : read a abs file and return its (f,x,y,z) value
            args:
                path: path of the abs file

            return: (f,x,y,z)
                f: a flag indicates whether the point is valid
                x: coordinate in x axis, if f is 0, the value will be -99999 representing a NULL point
                y: coordinate in y axis, if f is 0, the value will be -99999 representing a NULL point
                z: coordinate in z axis, if f is 0, the value will be -99999 representing a NULL point

    """
    def __init__(self):
        self.ABS_obj = lib.abs_new()
        lib.abs_read.restype = ndpointer(dtype=c_float, shape=(4, 480, 640))

    def read(self, path):
        self.fxyz = lib.abs_read(self.ABS_obj, path.encode())
        return self.fxyz[0], self.fxyz[1], self.fxyz[2], self.fxyz[3]  


def demo():
    # read example
    test = ABS()
    abs_path ="./../90021d257.abs" 
    start_time = time.time()
    f,x,y,z = test.read(abs_path)
    end_time = time.time()
    print("read file used time = ", end_time-start_time)
    
    message = "----------------------------"
    print(message)
    message = "You can see the (f,x,y,z) are 480 * 640 array"
    print(message)
    print("the shape of f ", f.shape)
    print("the shape if z ", z.shape)

    message = "but not evey point are valid"
    print(message)
    print("if f is ", f[0][0])
    print("the x,y,z will be ", x[0][0], y[0][0], z[0][0])
    
    print("You should handle the NULL points first")


if __name__ == "__main__":
    demo()