// demo1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//�򿪡�����ͼƬ�ļ�
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

	// Matlab���� cvLoadImage ��������һ�ֵ���
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
	
	//����Ƶ�ļ���ȡ
	//CvCapture *cap = cvCreateFileCapture("D:\\opencv\\demo.mp4");
	//������ͷ��ȡ������Ϊ-1�����ѡȡһ������ͷ
	//HighGUI���� #define cvCaptureFromCAM cvCreateCameraCapture����������ͬ����
	CvCapture *cap = cvCreateCameraCapture(0);
	
	double fps = cvGetCaptureProperty(cap, CV_CAP_PROP_FPS);
	CvSize size = cvSize(
		(int) cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_WIDTH),
		(int) cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_HEIGHT)
	);
	
	//������������-1����(����ʱ����һ��������ѡ���)
	//CV_FOURCC('P','I','M','1'),CV_FOURCC('M','J','P','G'),CV_FOURCC('M', 'P', '4', '2')����
	CvVideoWriter *writer = cvCreateVideoWriter(
		"D:\\opencv\\demoOut.avi",
		-1,//������
		10,//fps,
		size
	);

	while(1) {
		imgin = cvQueryFrame(cap);
		if(!imgin)
			break;
		cvShowImage("input", imgin);

		//ͼ��任����ʾ��д��AVI
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

// ��Ե���
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