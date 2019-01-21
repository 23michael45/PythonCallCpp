#include <stdio.h>
#include <iostream>
#include "utils.h"


using namespace std;


int main(int argc,char *argv[])
{
    printf("Python Call C++\n");
    
    cv::Mat srcImage = cv::imread("1.jpg");
    cv::imshow("bitwise_add",srcImage);
    cv::waitKey(0);
    return 0;
}

