#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


////////////// Draw Shapes and Text 自己画图和添加文字//////////////////////
void main() {
	// 创建一个画布，8UC3表示3通道无符号整型数值即0-255亮度级
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255)); //蓝绿红3通道255即合成白色
	// 画圆，参数为圆心，半径长度，颜色等等
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	// 画矩形，取两点坐标即可左上右下
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	// 画线，起点终点，厚度
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
	// 添加文本信息，起点，字体，文字大小，厚度
	putText(img, "Roger's workshop", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.85, Scalar(0, 69, 255), 2);

	imshow("img", img);
	waitKey(0);




}