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
	std::vector<std::vector<double>> matrix;
	int row;
	int col;
	LiteMatrix(int row = 0, int col = 0);
	LiteMatrix(std::vector<std::vector<double>> matrix);
	void CinInit();
	void initMH33(double centernum);
	void initNum(double num);
};

void Convolution(cv::Mat& img, const LiteMatrix& kernal);
void Convolution331(cv::Mat& img, const LiteMatrix& kernal, cv::Mat& img2);
void Convolution331gray(cv::Mat& img, const LiteMatrix& kernal, cv::Mat& img2);
cv::Mat toCrt(cv::Mat & img);

#endif//TOYOFPICTURE_TOY_H
