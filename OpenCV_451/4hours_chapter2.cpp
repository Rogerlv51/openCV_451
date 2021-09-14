#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


// ͼ���������
void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);  // ���ɫת�Ҷ�ͼ
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0); // ��˹�˲�ģ�����м�ѡ����˴�С
	Canny(imgBlur, imgCanny, 25, 75); //canny���ӱ�Ե���

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);    //�����ͺ�ʴ

 	imshow("image1", img);
	imshow("image2", imgGray);
	imshow("image3", imgBlur);
	imshow("image4", imgCanny);
	imshow("image5", imgDil);
	imshow("image6", imgErode);
	waitKey(0); //�ӳ����޳�ʱ��
}