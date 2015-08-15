// demo2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "highgui.h"
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	cvNamedWindow("img1", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("img2", CV_WINDOW_AUTOSIZE);

	IplImage *img = cvLoadImage("D:\\opencv\\demo.jpg");
	cvShowImage("img1", img);

	IplImage *img2 = cvLoadImage("D:\\opencv\\demo2.jpg");

	// ���ø���Ȥ����ROI
	cvSetImageROI(img, cvRect(100, 100, 300, 300));
	cvSetImageROI(img2, cvRect(100, 100, 300, 300));

	// ����任����ʾ
	//cvAddS(img, cvScalar(-100.0f), img);
	cvAddWeighted(img, 0.4, img2, 0.4, 0.2, img);
	cvResetImageROI(img);
	cvPutText(img, "text", cvPoint(100, 100), &cvFont(10.0), cvScalar(1));
	cvShowImage("img2", img);

	cvWaitKey();
	return 0;
}

