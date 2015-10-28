
#include <stdio.h>
#include "/usr/include/opencv2/opencv.hpp"
#include "/usr/include/opencv2/core/core.hpp"
#include "/usr/include/opencv2/highgui/highgui.hpp"

using namespace cv;


const cv::Mat XKERNEL = (Mat_<double>(3,3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
const cv::Mat YKERNEL = (Mat_<double>(3,3) << -1, -2 -1, 0, 0, 0, 1, 2, 1);
/*
void calculateFirstDerivative(cv::Mat &input, cv::Mat &output, const cv::Mat &kernel);
void calculateMagnitude(cv::Mat &ddx, cv::Mat &ddy, cv::Mat &output);
void calculateGradientOrientation(cv::Mat &ddx, cv::Mat &ddy, cv::Mat &output);
void thresholdImage(cv::Mat &input, cv::Mat &output);
*/

void generateSobelImages(cv::Mat &input);
int convolveImageAt(cv::Mat &input, int row, int column, const cv::Mat &kernel);
