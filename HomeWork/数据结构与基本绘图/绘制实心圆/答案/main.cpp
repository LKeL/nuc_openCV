#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


#define WINDOW_NAME1 "【绘制图1】"        // 为窗口标题定义的宏 
#define WINDOW_WIDTH 600// 定义窗口大小的宏

void DrawFilledCircle(Mat img, Point center);// 绘制圆


/*
 * 输出一些帮助信息
 */
void ShowHelpText()
{
	// 输出欢迎信息和OpenCV版本
	cout << "此计算机OPENCV版本为:  " << CV_VERSION << endl;
}




/*
 *控制台应用程序的入口函数
 */
int main(void)
{

	// 创建空白的Mat图像
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	// 绘制圆心
	DrawFilledCircle(atomImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	// 显示绘制出的图像
	imshow(WINDOW_NAME1, atomImage);
	moveWindow(WINDOW_NAME1, 0, 200);
	waitKey(0);
	return(0);
}

/*
 * 自定义的绘制函数，实现了实心圆的绘制
 */
void DrawFilledCircle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;

	circle(img,
		center,
		WINDOW_WIDTH / 8,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}

