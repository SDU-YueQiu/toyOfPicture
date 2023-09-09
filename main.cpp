#include "toy.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "algorithm"

using namespace std;
using namespace cv;

double mmax = -1, mmin = 1e10;
double step;

inline int getBlue(double x)
{
	return ceil((x - mmin) / step);
}

int main()
{
	ifstream fin("E:\\programs\\toyOfPicture\\source\\txt\\data.txt");
	LiteMatrix data(251, 201);

	for (int i = 0; i < 251; i++)
		for (int j = 0; j < 201; j++)
		{
			fin >> data.matrix[i][j];
			mmax = max(mmax, data.matrix[i][j]);
			mmin = min(mmin, data.matrix[i][j]);
		}
	int defStep = 200;
	step = (mmax - mmin) / defStep;

	int beishu = 4;

	Mat img(251 * beishu, 201 * beishu, CV_8UC3);

	for (int i = 0; i < beishu * 251; i++)
		for (int j = 0; j < beishu * 201; j++)
		{
			img.at<Vec3b>(i, j)[1] = 50;
			img.at<Vec3b>(i, j)[0] = defStep - getBlue(data.matrix[i / beishu][j / beishu]);
			img.at<Vec3b>(i, j)[2] = 50;
		}

	imshow("img", img);
	//imwrite("E:\\programs\\toyOfPicture\\source\\img\\data.jpg", img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
