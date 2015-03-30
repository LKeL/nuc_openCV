#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include<math.h>

using namespace cv;
using namespace std;


#define WINDOW_NAME2 "������ͼ2��"        // Ϊ���ڱ��ⶨ��ĺ� 
#define WINDOW_WIDTH 600// ���崰�ڴ�С�ĺ�

void DrawPolygon(Mat img);// ���ƶ����
void DrawLine(Mat img, Point start, Point end);// �����߶�



/*
 * ���һЩ������Ϣ
 */
void ShowHelpText()
{
	// �����ӭ��Ϣ��OpenCV�汾
	cout << "�˼����OPENCV�汾Ϊ:  " << CV_VERSION << endl;
}




/*
 *����̨Ӧ�ó������ں���
 */
int main(void)
{

	// �����հ׵�Matͼ��
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	ShowHelpText();
	// ���ƻ�ѧ�е�ԭ��ʾ��ͼ

	// �������ͼ
	DrawPolygon(rookImage);

	// ��ʾ���Ƴ���ͼ��
	imshow(WINDOW_NAME2, rookImage);
	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 200);

	waitKey(0);
	return(0);
}

/*
 * �Զ���Ļ��ƺ�����ʵ���˰�����εĻ���
 */
void DrawPolygon(Mat img)
{
	int lineType = 8;

	//����һЩ��
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
 *�Զ���Ļ��ƺ�����ʵ�����ߵĻ���
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