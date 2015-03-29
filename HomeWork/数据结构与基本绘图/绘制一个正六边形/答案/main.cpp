#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include<math.h>

using namespace cv;
using namespace std;


#define WINDOW_NAME2 "【绘制图2】"        // 为窗口标题定义的宏 
#define WINDOW_WIDTH 600// 定义窗口大小的宏

void DrawPolygon(Mat img);// 绘制多边形
void DrawLine(Mat img, Point start, Point end);// 绘制线段



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
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	ShowHelpText();
	// 绘制化学中的原子示例图

	// 绘制组合图
	DrawPolygon(rookImage);

	// 显示绘制出的图像
	imshow(WINDOW_NAME2, rookImage);
	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 200);

	waitKey(0);
	return(0);
}

/*
 * 自定义的绘制函数，实现了凹多边形的绘制
 */
void DrawPolygon(Mat img)
{
	int lineType = 8;

	//创建一些点
	Point rookPoints[1][6];
	rookPoints[0][0] = Point(WINDOW_WIDTH / 3, WINDOW_WIDTH / 3);
	rookPoints[0][1] = Point(2 * WINDOW_WIDTH / 3, WINDOW_WIDTH / 3);
	rookPoints[0][2] = Point(5 * WINDOW_WIDTH / 6, (sqrt(3) + 2) * WINDOW_WIDTH / 6);
	rookPoints[0][3] = Point(2 * WINDOW_WIDTH / 3, (sqrt(3) + 1) * WINDOW_WIDTH / 3);
	rookPoints[0][4] = Point(WINDOW_WIDTH / 3, (sqrt(3) + 1) * WINDOW_WIDTH / 3);
	rookPoints[0][5] = Point(WINDOW_WIDTH / 6, (sqrt(3) + 2) * WINDOW_WIDTH / 6);
	
	
	const Point* ppt[1] = { rookPoints[0] };
	cout << *ppt[0] << endl;
	int npt[] = { 6 };
	
	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),
		lineType);
}

/*
 *自定义的绘制函数，实现了线的绘制
 */
void DrawLine(Mat img, Point start, Point end)
{
	int thickness = 2;
	int lineType = 8;
	line(img,
		start,
		end,
		Scalar(0, 0, 0),
		thickness,
		lineType);
}