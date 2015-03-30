#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


#define WINDOW_NAME2 "������ͼ2��"        //Ϊ���ڱ��ⶨ��ĺ� 
#define WINDOW_WIDTH 600//���崰�ڴ�С�ĺ�

void DrawFilledCircle(Mat img, Point center);//����Բ





/*
 *���һЩ������Ϣ
 */
void ShowHelpText()
{
	//�����ӭ��Ϣ��OpenCV�汾
	cout << "�˼����OPENCV�汾Ϊ:  " << CV_VERSION << endl;
}




/*
 *����̨Ӧ�ó������ں���
 */
int main(void)
{

	//�����հ׵�Matͼ��
	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);

	ShowHelpText();
	//���ƻ�ѧ�е�ԭ��ʾ��ͼ

	//���ƾ���
	rectangle(rookImage,
		Point(WINDOW_WIDTH / 4, WINDOW_WIDTH /4),
		Point(3 * WINDOW_WIDTH / 4 , 3 * WINDOW_WIDTH / 4),
		Scalar(0, 255, 255),
		-1,
		8);
	DrawFilledCircle(rookImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	// ��ʾ���Ƴ���ͼ��
	imshow(WINDOW_NAME2, rookImage);
	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 200);

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
		WINDOW_WIDTH / 4,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}

