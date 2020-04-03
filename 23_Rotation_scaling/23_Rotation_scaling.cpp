// 23_Rotation_scaling.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ����ת���ţ�����ʾ����
	cv::Mat dstMat;
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/����/1.jpg");
	if (srcMat.empty())return-1;
	
	//
	float angle = -10.0, scale = 1;
	//
	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
	//
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	imshow("src", srcMat);
	imshow("dst", dstMat);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}
