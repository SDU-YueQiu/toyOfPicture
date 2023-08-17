//
// Created by Yue_Qiu on 2023/8/16.
//
#include "toy.h"

using namespace std;

LiteMatrix::LiteMatrix(int row, int col)
{
    this->row = row;
    this->col = col;
    this->matrix = vector<vector<int>>(row, vector<int>(col, 0));
}

LiteMatrix::LiteMatrix(vector<vector<int>> matrix)
{
    this->row = matrix.size();
    this->col = matrix[0].size();
    this->matrix = matrix;
}

void LiteMatrix::CinInit()
{
    puts("Please input the matrix:\n");
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->col; j++)
            cin >> this->matrix[i][j];
}
