#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


/*               ͼƬ�޸ĳߴ缰ͼƬ�ü�                  */


void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize1, imgResize2, imgCrop;

	cout << img.size() << endl;  //�鿴ͼƬ��С

	resize(img, imgResize1, Size(640, 480)); // �涨������ֵ�޸ĳߴ�
	resize(img, imgResize2, Size(), 0.5, 0.5);  // ������������ţ�����
	Rect roi(100, 100, 300, 250);  //�ȶ���һ���ü�����㼰�ü�������С(x,y,size)
	imgCrop = img(roi);

	imshow("img1", img);
	imshow("img2", imgResize1);
	imshow("img3", imgResize2);
	imshow("img4", imgCrop);

	waitKey(0);

}