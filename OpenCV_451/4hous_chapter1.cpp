#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


/*   ////     ����ͼƬ���      ////
void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("image", img);
	waitKey(0); //�ӳ����޳�ʱ��
}
*/




/*      /////      ������Ƶ����           ////
void main() {
	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;
	while(true){
		cap.read(img);
		imshow("image", img);
		waitKey(50);  //��λ�Ǻ��룬50���벥��һ֡����
	}
	
}
*/

/*                  ///������ͷ����///

void main() {
	VideoCapture cap(0);   //0Ĭ����ϵͳ����ͷID
	Mat img;
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}

*/
