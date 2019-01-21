#pragma once
#include <iostream>

#include <opencv2/opencv.hpp>
#include <pybind11/pybind11.h>
#include <Python.h>


namespace py = pybind11;
using namespace cv;

//extern "C"
//{
#if !defined(USE_DLL) // inside DLL
#   define PYM_API   __declspec(dllexport)
#else // outside DLL
#   define PYM_API   __declspec(dllimport)
#endif 

//void initpym();


int addnum(int i, int j);
cv::Mat GetImage(std::string fn);
//}