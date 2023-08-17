#include "toy.h"

using namespace std;
using namespace cv;

int main()
{
	Mat oimg = imread("E:\\programs\\toyOfPicture\\source\\img\\test3.png");

	LiteMatrix kernal(3, 3);
	//kernal.initMH33(0);
	kernal.matrix = {
		{0.25,0,-0.25},
		{0.5,0,-0.5},
		{0.25,0,-0.25}
	};
	Mat img;
	cvtColor(oimg, img, COLOR_BGR2GRAY);
	imshow("origin", img);
	Mat img2 = Mat::zeros(Size(img.cols, img.rows), CV_8UC3);
	Convolution331(img, kernal, img2);
	imshow("convolutioned", img2);

	waitKey(0);
	destroyAllWindows();
	return 0;
}
