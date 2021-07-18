#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


////////////////////////     ÈËÁ³Ê¶±ð      /////////////////////
void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	string facename = "Resources/haarcascade_frontalface_default.xml";
	CascadeClassifier faceCascade;
	faceCascade.load(facename);
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 3);

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}
	imshow("image", img);
	waitKey(0); 
}
