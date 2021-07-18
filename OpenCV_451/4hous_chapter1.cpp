#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


/*   ////     导入图片输出      ////
void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("image", img);
	waitKey(0); //延迟无限长时间
}
*/




/*      /////      导入视频操作           ////
void main() {
	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;
	while(true){
		cap.read(img);
		imshow("image", img);
		waitKey(50);  //单位是毫秒，50毫秒播放一帧画面
	}
	
}
*/

/*                  ///打开摄像头操作///

void main() {
	VideoCapture cap(0);   //0默认是系统摄像头ID
	Mat img;
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}

*/
