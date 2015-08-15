// demo3.cpp : 定义控制台应用程序的入口点。
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
	cvNamedWindow("高斯模糊");
	cvShowImage("高斯模糊", img1);

	cvSmooth(img0, img1, CV_BLUR);
	cvNamedWindow("简单平滑");
	cvShowImage("简单平滑", img1);
	
	cvSmooth(img0, img1, CV_MEDIAN);
	cvNamedWindow("中值滤波");
	cvShowImage("中值滤波", img1);
	
	cvDilate(img0, img1);
	cvNamedWindow("膨胀");
	cvShowImage("膨胀", img1);
	
	cvErode(img0, img1);
	cvNamedWindow("腐蚀");
	cvShowImage("腐蚀", img1);
	
	////////////////
	cvMorphologyEx(img0, img1, img2, NULL, CV_MOP_GRADIENT);
	cvNamedWindow("形态梯度");
	cvShowImage("形态梯度", img1);
	*/

	IplImage *graySrc = cvLoadImage("D:\\opencv\\gray.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cvNamedWindow("img0");
	cvShowImage("img0", graySrc);

	IplImage *grayDst = cvCreateImage(cvSize(graySrc->width, graySrc->height), IPL_DEPTH_8U, 1);

	cvThreshold(graySrc, grayDst, 15, 255, 1);
	cvNamedWindow("阈值化");
	cvShowImage("阈值化", grayDst);

	cvAdaptiveThreshold(graySrc, grayDst, 255, 1, 1, 71, 15);
	cvNamedWindow("自适应阈值");
	cvShowImage("自适应阈值", grayDst);
	
	/*
	// 出错
	cvPyrUp(graySrc, grayDst);
	cvNamedWindow("图像金字塔");
	cvShowImage("图像金字塔", grayDst);
	//*/

	cvWaitKey();
	return 0;
}

