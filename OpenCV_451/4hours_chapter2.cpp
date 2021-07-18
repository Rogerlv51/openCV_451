#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


// 图像基础处理
void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);  // 真彩色转灰度图
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0); // 高斯滤波模糊，中间选卷积核大小
	Canny(imgBlur, imgCanny, 25, 75); //canny算子边缘检测

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);    //先膨胀后腐蚀

 	imshow("image1", img);
	imshow("image2", imgGray);
	imshow("image3", imgBlur);
	imshow("image4", imgCanny);
	imshow("image5", imgDil);
	imshow("image6", imgErode);
	waitKey(0); //延迟无限长时间
}