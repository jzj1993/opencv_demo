// demo3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	char fname[] = "D:\\opencv\\demo3.jpg";
	IplImage *img0 = cvLoadImage(fname);
	cvNamedWindow("img0");
	cvShowImage("img0", img0);
	
	IplImage *img1 = cvCloneImage(img0);//cvLoadImage(fname);
	IplImage *img2 = cvCloneImage(img0);//cvLoadImage(fname);
	cvSmooth(img0, img1);
	cvNamedWindow("��˹ģ��");
	cvShowImage("��˹ģ��", img1);

	cvSmooth(img0, img1, CV_BLUR);
	cvNamedWindow("��ƽ��");
	cvShowImage("��ƽ��", img1);
	
	cvSmooth(img0, img1, CV_MEDIAN);
	cvNamedWindow("��ֵ�˲�");
	cvShowImage("��ֵ�˲�", img1);
	
	cvDilate(img0, img1);
	cvNamedWindow("����");
	cvShowImage("����", img1);
	
	cvErode(img0, img1);
	cvNamedWindow("��ʴ");
	cvShowImage("��ʴ", img1);
	
	////////////////
	cvMorphologyEx(img0, img1, img2, NULL, CV_MOP_GRADIENT);
	cvNamedWindow("��̬�ݶ�");
	cvShowImage("��̬�ݶ�", img1);
	*/

	IplImage *graySrc = cvLoadImage("D:\\opencv\\gray.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cvNamedWindow("img0");
	cvShowImage("img0", graySrc);

	IplImage *grayDst = cvCreateImage(cvSize(graySrc->width, graySrc->height), IPL_DEPTH_8U, 1);

	cvThreshold(graySrc, grayDst, 15, 255, 1);
	cvNamedWindow("��ֵ��");
	cvShowImage("��ֵ��", grayDst);

	cvAdaptiveThreshold(graySrc, grayDst, 255, 1, 1, 71, 15);
	cvNamedWindow("����Ӧ��ֵ");
	cvShowImage("����Ӧ��ֵ", grayDst);
	
	/*
	// ����
	cvPyrUp(graySrc, grayDst);
	cvNamedWindow("ͼ�������");
	cvShowImage("ͼ�������", grayDst);
	//*/

	cvWaitKey();
	return 0;
}

