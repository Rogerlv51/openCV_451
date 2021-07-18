#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

//////////////////        检测图像轮廓    ////////////////////////////


void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	// drawContours函数的第三个参数表示要绘制的轮廓个数，如果是负数表示把全部轮廓画出来
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);    // 计算每个图像轮廓所包含面积
		cout << area << endl;
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);  // 计算各轮廓周长，第二个参数表示是否封闭
			// 一二参数的类型应一致都为  vector<vector<Point>>
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);  // 用多边形近似原轮廓，第三个参数表示近似精度
			cout << conPoly[i].size() << endl;   // 此时可通过conploy的大小确定有几个边界点

			int objCor = (int)conPoly[i].size();

			if (objCor == 3) { objectType = "Tri"; }
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}   
			else if (objCor > 4) { objectType = "Circle"; }

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);   // 画出边缘轮廓
			boundRect[i] = boundingRect(conPoly[i]);   //  用一个矩形框把每一个轮廓圈出来
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}
void main() {
	
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// 图像预处理
	cvtColor(img, imgGray, COLOR_BGR2GRAY);  // 真彩色转灰度图
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0); // 高斯滤波模糊，中间选卷积核大小
	Canny(imgBlur, imgCanny, 25, 75); //canny算子边缘检测

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	// 识别处理
	getContours(imgDil, img);

	imshow("img1", img);
	//imshow("img2", imgGray);
	//imshow("img3", imgBlur);
	//imshow("img4", imgCanny);
	//imshow("img5", imgDil);
	waitKey(0);

}