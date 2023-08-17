#include "toy.h"

using namespace std;
using namespace cv;

int main()
{
	Mat oimg = imread("E:\\programs\\toyOfPicture\\source\\img\\test.png");

	LiteMatrix kernal(3, 3);
	//kernal.initMH33(-1);
	kernal.matrix = {
		{-1,-1,0},
		{-1,0,1},
		{0,1,1}
	};
	Mat img;
	cvtColor(oimg, img, COLOR_BGR2GRAY);
	Mat img2 = Mat::zeros(Size(img.cols, img.rows), CV_8UC1);
	imshow("origin", oimg);
	Convolution331gray(img, kernal, img2);
	imshow("convolutioned", img2);
	
	/*imshow("origin", oimg);
	Convolution(oimg, kernal);
	imshow("convolutioned", oimg);*/
	waitKey(0);
	destroyAllWindows();
	return 0;
}
