#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

//////////////////        ���ͼ������    ////////////////////////////


void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	// drawContours�����ĵ�����������ʾҪ���Ƶ���������������Ǹ�����ʾ��ȫ������������
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);    // ����ÿ��ͼ���������������
		cout << area << endl;
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);  // ����������ܳ����ڶ���������ʾ�Ƿ���
			// һ������������Ӧһ�¶�Ϊ  vector<vector<Point>>
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);  // �ö���ν���ԭ������������������ʾ���ƾ���
			cout << conPoly[i].size() << endl;   // ��ʱ��ͨ��conploy�Ĵ�Сȷ���м����߽��

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

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);   // ������Ե����
			boundRect[i] = boundingRect(conPoly[i]);   //  ��һ�����ο��ÿһ������Ȧ����
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}
void main() {
	
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// ͼ��Ԥ����
	cvtColor(img, imgGray, COLOR_BGR2GRAY);  // ���ɫת�Ҷ�ͼ
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0); // ��˹�˲�ģ�����м�ѡ����˴�С
	Canny(imgBlur, imgCanny, 25, 75); //canny���ӱ�Ե���

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	// ʶ����
	getContours(imgDil, img);

	imshow("img1", img);
	//imshow("img2", imgGray);
	//imshow("img3", imgBlur);
	//imshow("img4", imgCanny);
	//imshow("img5", imgDil);
	waitKey(0);

}