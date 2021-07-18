#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/////////////////////   进行颜色分割，提取颜色区域   ////////////////////

void main() {

	String path = "Resources/lambo.png";
	Mat img = imread(path);
	Mat imgHSV, mask;
	int hmin = 0, smin = 110, vmin = 153;
	int hmax = 19, smax = 240, vmax = 255;

	// HSV颜色模型，色调（H），饱和度（S），透明度（V）
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	// 建立一个滑动轨迹窗，可以更好地筛选出自己想要的颜色区域
	namedWindow("Trackbars", (200, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true)
	{	
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);   //把HSV限制在范围内建立蒙版
		imshow("img", img);
		imshow("imgHSV", imgHSV);
		imshow("imgMask", mask);
		waitKey(1);

	}

	
}