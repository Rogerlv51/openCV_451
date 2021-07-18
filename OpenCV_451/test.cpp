#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void main()
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	imshow("img", img);
	/*  分离成三通道分别显示  */
	vector<Mat> planes;
	split(img, planes);
	imshow("B", planes[0]);
	imshow("G", planes[1]);
	imshow("R", planes[2]);

	waitKey(0);
}