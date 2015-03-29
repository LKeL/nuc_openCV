#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


#define WINDOW_NAME1 "������ͼ1��"        // Ϊ���ڱ��ⶨ��ĺ� 
#define WINDOW_WIDTH 600// ���崰�ڴ�С�ĺ�

void DrawFilledCircle(Mat img, Point center);// ����Բ


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
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	// ����Բ��
	DrawFilledCircle(atomImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	// ��ʾ���Ƴ���ͼ��
	imshow(WINDOW_NAME1, atomImage);
	moveWindow(WINDOW_NAME1, 0, 200);
	waitKey(0);
	return(0);
}

/*
 * �Զ���Ļ��ƺ�����ʵ����ʵ��Բ�Ļ���
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

