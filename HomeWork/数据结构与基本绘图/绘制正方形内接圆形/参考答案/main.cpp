#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


#define WINDOW_NAME2 "【绘制图2】"        //为窗口标题定义的宏 
#define WINDOW_WIDTH 600//定义窗口大小的宏

void DrawFilledCircle(Mat img, Point center);//绘制圆





/*
 *输出一些帮助信息
 */
void ShowHelpText()
{
	//输出欢迎信息和OpenCV版本
	cout << "此计算机OPENCV版本为:  " << CV_VERSION << endl;
}




/*
 *控制台应用程序的入口函数
 */
int main(void)
{

	//创建空白的Mat图像
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	ShowHelpText();
	//绘制化学中的原子示例图

	//绘制矩形
	rectangle(rookImage,
		Point(WINDOW_WIDTH / 4, WINDOW_WIDTH /4),
		Point(3 * WINDOW_WIDTH / 4 , 3 * WINDOW_WIDTH / 4),
		Scalar(0, 255, 255),
		-1,
		8);
	DrawFilledCircle(rookImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	// 显示绘制出的图像
	imshow(WINDOW_NAME2, rookImage);
	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 200);

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
		WINDOW_WIDTH / 4,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}

