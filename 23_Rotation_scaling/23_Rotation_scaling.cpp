// 23_Rotation_scaling.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//读取本地的一张图片，旋转缩放，并显示出来
	cv::Mat dstMat;
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/推文/1.jpg");
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
	//等待用户按键
	waitKey(0);
	return 0;
}
