// demo1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
using namespace cv;
using namespace std;

IplImage *doCanny(IplImage*);

int _tmain(int argc, _TCHAR* argv[])
{
	//cvSaveImage("D:\\2.jpg", doCanny(cvLoadImage("D:\\1.jpg")));
	//return 0;
	//*
	//打开、保存图片文件
	cvNamedWindow("pic", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("pic_2", CV_WINDOW_AUTOSIZE);
	IplImage *img = cvLoadImage("D:\\opencv\\demo.jpg");
	IplImage *img_2 =  cvCreateImage(
		cvGetSize(img),
		IPL_DEPTH_8U,
		1
	);
	cvCanny(img, img_2, 40, 150, 3);
	cvShowImage("pic", img);
	cvShowImage("pic_2", img_2);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&img_2);
	cvDestroyWindow("pic");
	cvDestroyWindow("pic_2");
	char outfname[] = "D:\\opencv\\demoOut.jpg";
	if(!cvSaveImage(outfname,img))
		cout << "Could not save " << outfname << " !" << endl;

	while(1);

	// Matlab风格的 cvLoadImage 函数的另一种调用
	Mat mat = imread("D:\\opencv\\demo.jpg");
	if(mat.empty() || !mat.data)
		return -1;
	cvNamedWindow("img", CV_WINDOW_AUTOSIZE);
	imshow("img", mat);
	cvWaitKey();
	//*/
	
	
	cvNamedWindow("input", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("output", CV_WINDOW_AUTOSIZE);
	IplImage *imgin, *imgout;
	
	//从视频文件读取
	//CvCapture *cap = cvCreateFileCapture("D:\\opencv\\demo.mp4");
	//从摄像头读取，参数为-1则随机选取一个摄像头
	//HighGUI中有 #define cvCaptureFromCAM cvCreateCameraCapture，两者是相同函数
	CvCapture *cap = cvCreateCameraCapture(0);
	
	double fps = cvGetCaptureProperty(cap, CV_CAP_PROP_FPS);
	CvSize size = cvSize(
		(int) cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_WIDTH),
		(int) cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_HEIGHT)
	);
	
	//编码器参数：-1可以(运行时弹出一个编码器选择框)
	//CV_FOURCC('P','I','M','1'),CV_FOURCC('M','J','P','G'),CV_FOURCC('M', 'P', '4', '2')不行
	CvVideoWriter *writer = cvCreateVideoWriter(
		"D:\\opencv\\demoOut.avi",
		-1,//编码器
		10,//fps,
		size
	);

	while(1) {
		imgin = cvQueryFrame(cap);
		if(!imgin)
			break;
		cvShowImage("input", imgin);

		//图像变换、显示、写入AVI
		imgout = doCanny(imgin);
		//imgout = cvCloneImage(imgin);
		//cvSmooth(imgin, imgout);
		cvShowImage("output", imgout);
		cvWriteFrame(writer, imgout);

		if(cvWaitKey(10) == 27)
			break;
	}
	cvReleaseVideoWriter(&writer);
	cvReleaseImage(&imgout);
	cvReleaseCapture(&cap);
	cvDestroyWindow("input");
	cvDestroyWindow("output");
	return 0;
}

// 边缘检测
IplImage *doCanny(IplImage *in)
{
	//if(in->nChannels != 1)
	//	return NULL;
	IplImage *out = cvCreateImage(
		cvGetSize(in),
		IPL_DEPTH_8U,
		1
	);
	cvCanny(in, out, 50, 150, 3);
	return out;
}