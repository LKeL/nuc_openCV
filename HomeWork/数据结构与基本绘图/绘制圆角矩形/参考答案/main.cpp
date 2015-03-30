#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define WINDOW_NAME "【程序窗口】"
#define ANGLE 20

void ShowHelpText();
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawRectangle(cv::Mat& img, cv::Rect box, int angle);
void DrawLine(Mat img, Point start, Point end);


Rect g_rectangle;
bool g_bDrawingBox = false;//是否进行绘制
RNG g_rng(12345);

int main(int argc, char** argv) {


	// 显示帮助界面
	ShowHelpText();

	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	g_rectangle = Rect(-1, -1, 0, 0);
	srcImage = Scalar::all(0);


	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);

	while (1){
		srcImage.copyTo(tempImage);//拷贝源图到临时变量
		if (g_bDrawingBox) DrawRectangle(tempImage, g_rectangle, ANGLE);//当进行绘制的标识符为真，则进行绘制
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10) == 27) break;//按下ESC键，程序退出
	}
	waitKey();
	system("pause");
	return 0;
}


/*
 * 显示帮助界面
 */
void ShowHelpText(){
	cout << "你的OPENCV版本为: " << CV_VERSION << endl;

}

void on_MouseHandle(int event, int x, int y, int flags, void* param){

	Mat& image = *(cv::Mat*) param;
	switch (event) {
		//鼠标移动消息
	case EVENT_MOUSEMOVE: {
		//如果是否进行绘制的标识符为真，则记录下长和宽到RECT型变量中
		if (g_bDrawingBox){
			g_rectangle.width = x - g_rectangle.x;
			g_rectangle.height = y - g_rectangle.y;
		}
	}
		break;

		//左键按下消息
	case EVENT_LBUTTONDOWN: {
		g_bDrawingBox = true;
		g_rectangle = Rect(x, y, 0, 0);//记录起始点
	}
		break;

		//左键抬起消息
	case EVENT_LBUTTONUP: {
		g_bDrawingBox = false;//置标识符为false
		//调用函数进行绘制
		DrawRectangle(image, g_rectangle, ANGLE);
	}
		break;

	}
}


/*
 * 绘制圆角矩形
 */

void DrawRectangle(cv::Mat& img, cv::Rect box, int angle){
	int negativeX = box.width > 0 ? 1 : -1;
	int negativeY = box.height > 0 ? 1 : -1;
	int thickness = 1;
	int lineType = 1;
	int TEMPX = negativeX > 0 ? 0 : -90;
	int TEMPY = negativeY > 0 ? 0 : -90;
	
	// 绘制直线
	DrawLine(img, Point(box.x + (negativeX * angle), box.y), Point(box.x - (negativeX * angle) + box.width, box.y));
	DrawLine(img, Point(box.x + box.width, box.y + (negativeY * angle)), Point(box.x + box.width, box.y - (negativeY * angle) + box.height));
	DrawLine(img, Point(box.x - (negativeX * angle) + box.width, box.y + box.height), Point(box.x + (negativeX * angle), box.y + box.height));
	DrawLine(img, Point(box.x, box.y + (negativeY * angle)), Point(box.x, box.y - (negativeY * angle) + box.height));
	
	// 绘制圆角
	ellipse(img, Point(box.x + box.width - (negativeX * angle), box.y + box.height - (negativeY * angle)), Size(angle, angle), 0, -1 * TEMPX + negativeX*TEMPY + 0, -1 * TEMPX + negativeX*TEMPY + 90, Scalar(255, 255, 0), thickness, lineType);
	ellipse(img, Point(box.x + box.width - (negativeX * angle), box.y + (negativeY * angle)), Size(angle, angle), 0, -1 * (-1 * TEMPX + negativeX*TEMPY) + 270, -1 * (-1 * TEMPX + negativeX*TEMPY) + 360, Scalar(255, 255, 0), thickness, lineType);
	ellipse(img, Point(box.x + (negativeX * angle), box.y + (negativeY * angle)), Size(angle, angle), 0, -1 * TEMPX + negativeX*TEMPY + 180, -1 * TEMPX + negativeX*TEMPY + 270, Scalar(255, 255, 0), thickness, lineType);
	ellipse(img, Point(box.x + (negativeX * angle), box.y + box.height - (negativeY * angle)), Size(angle, angle), 0, -1 * (-1 * TEMPX + negativeX*TEMPY) + 90, -1 * (-1 * TEMPX + negativeX*TEMPY) + 180, Scalar(255, 255, 0), thickness, lineType);
	
}

/*
*自定义的绘制函数，实现了线的绘制
*/
void DrawLine(Mat img, Point start, Point end){
	int thickness = 1;
	int lineType = 1;
	line(img,
		start,
		end,
		Scalar(255, 255, 0),
		thickness,
		lineType);
}