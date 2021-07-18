#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


///////      ��ͼƬ���б���͸�Ӵ���        ////// 
void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Mat matrix1, imgWarp1, imgWarp2, matrix2;
	float w = 250, h = 350; //����Ŀ��ͼƬ�ĳ����С
	// ԭ��Ҫ�任�Ķ�����θ�Ŀ����ȱ�ʶ����
	Point2f src1[4] = { {529,142},{771,190},{405,395},{674,457} };//������,�������������¼
	Point2f dst1[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix1 = getPerspectiveTransform(src1, dst1); // �ȵõ�͸�ӱ任��Ӧ����
	warpPerspective(img, imgWarp1, matrix1, Size(w,h)); // ���б任

	for (int i = 0; i < 4; i++) {
			circle(img, src1[i], 10, Scalar(0, 0, 255), FILLED); 
			// �����ԭͼ��Ե4������
	}

	Point2f src2[4] = { {62,323},{339,277},{88,637},{402,576}};
	Point2f dst2[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix2 = getPerspectiveTransform(src2, dst2);
	warpPerspective(img, imgWarp2, matrix2, Size(w, h));

	for (int j = 0; j < 4; j++) {
		circle(img, src2[j], 10, Scalar(0, 0, 255), FILLED);
		// �����ԭͼ��Ե4������
	}

	
	imshow("imgsrc", img);
	imshow("img1", imgWarp1);
	imshow("img2", imgWarp2);
	waitKey(0);
}