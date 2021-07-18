#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


/*               图片修改尺寸及图片裁剪                  */


void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize1, imgResize2, imgCrop;

	cout << img.size() << endl;  //查看图片大小

	resize(img, imgResize1, Size(640, 480)); // 规定长宽数值修改尺寸
	resize(img, imgResize2, Size(), 0.5, 0.5);  // 按长宽比例缩放，常用
	Rect roi(100, 100, 300, 250);  //先定义一个裁剪的起点及裁剪画幅大小(x,y,size)
	imgCrop = img(roi);

	imshow("img1", img);
	imshow("img2", imgResize1);
	imshow("img3", imgResize2);
	imshow("img4", imgCrop);

	waitKey(0);

}