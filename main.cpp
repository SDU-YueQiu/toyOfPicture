#include "toy.h"

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("E:\\programs\\vsprograms\\ConsoleApplication1\\source\\img\\test.png");
	namedWindow("test", WINDOW_AUTOSIZE);
	imshow("test", img);

	waitKey(0);
	destroyAllWindows();
	return 0;
}
