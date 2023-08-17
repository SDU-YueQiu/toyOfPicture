//
// Created by Yue_Qiu on 2023/8/16.
//

#ifndef TOYOFPICTURE_TOY_H
#define TOYOFPICTURE_TOY_H

#include "iostream"
#include "vector"
#include "opencv2/opencv.hpp"

class LiteMatrix
{
public:
    std::vector<std::vector<int>> matrix;
    int row;
    int col;
    LiteMatrix(int row, int col);
    LiteMatrix(std::vector<std::vector<int>> matrix);
    void CinInit();
};



#endif//TOYOFPICTURE_TOY_H
