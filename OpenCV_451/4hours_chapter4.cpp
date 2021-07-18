#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


////////////// Draw Shapes and Text �Լ���ͼ���������//////////////////////
void main() {
	// ����һ��������8UC3��ʾ3ͨ���޷���������ֵ��0-255���ȼ�
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255)); //���̺�3ͨ��255���ϳɰ�ɫ
	// ��Բ������ΪԲ�ģ��뾶���ȣ���ɫ�ȵ�
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	// �����Σ�ȡ�������꼴����������
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	// ���ߣ�����յ㣬���
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
	// ����ı���Ϣ����㣬���壬���ִ�С�����
	putText(img, "Roger's workshop", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.85, Scalar(0, 69, 255), 2);

	imshow("img", img);
	waitKey(0);




}