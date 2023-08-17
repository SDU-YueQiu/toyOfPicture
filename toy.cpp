//
// Created by Yue_Qiu on 2023/8/16.
//
#include "toy.h"

using namespace std;
using namespace cv;

LiteMatrix::LiteMatrix(int row, int col)
{
	this->row = row;
	this->col = col;
	this->matrix = vector<vector<double>>(row, vector<double>(col, 0));
}

LiteMatrix::LiteMatrix(vector<vector<double>> matrix)
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

void Convolution(cv::Mat& img, const LiteMatrix& kernal)
{
	int div[9][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			Vec3f bgr = { 0,0,0 };
			for (int k = 0; k < 9; k++)
			{
				int kx = div[k][0] + 1, ky = div[k][1] + 1;
				int ix = i + div[k][0], iy = j + div[k][1];
				if (ix < 0 || ix >= img.rows || iy < 0 || iy >= img.cols)
					continue;
				for (int t = 0; t < 3; t++)
					bgr[t] += img.at<Vec3b>(ix, iy)[t] * kernal.matrix[kx][ky];
			}
			for (int t = 0; t < 3; t++)
				img.at<Vec3b>(i, j)[t] = bgr[t];
		}
	}
}

void Convolution331(cv::Mat& img, const LiteMatrix& kernal, Mat& img2)
{
	int div[9][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			int g = 0;
			for (int k = 0; k < 9; k++)
			{
				int kx = div[k][0] + 1, ky = div[k][1] + 1;
				int ix = i + div[k][0], iy = j + div[k][1];
				if (ix < 0 || ix >= img.rows || iy < 0 || iy >= img.cols)
					continue;
				g += img.at<uchar>(ix, iy) * kernal.matrix[kx][ky];
			}
			if (g > 0)
				img2.at<Vec3b>(i, j)[0] = g;
			else
				img2.at<Vec3b>(i, j)[2] = -g;
		}
	}
}

void LiteMatrix::initMH33(double centernum)
{
	double othernum = (1 - centernum) / 8;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
				this->matrix[i][j] = centernum;
			else
				this->matrix[i][j] = othernum;
		}
}

void LiteMatrix::initNum(double num)
{
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++)
			this->matrix[i][j] = num;
}
