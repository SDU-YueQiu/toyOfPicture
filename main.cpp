#include "toy.h"

using namespace std;
using namespace cv;

int main()
{
	Mat oimg = imread("E:\\programs\\toyOfPicture\\source\\img\\lina.jpg");
	imshow("input", oimg);
	imshow("output", toCrt(oimg));
	//waitKey(0);
	imwrite("E:\\programs\\toyOfPicture\\source\\img\\lina2.jpg", toCrt(oimg));
	destroyAllWindows();
	return 0;
}
