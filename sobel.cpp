#include <cmath>
#include "sobel.h"

void generateSobelImages(cv::Mat &input) {
	// Create objects for our output images
	cv::Mat ddx;
	cv::Mat ddy;
	cv::Mat magnitudeOfGradient;
	cv::Mat directionOfGradient;

	// Initialise the objects
	ddx.create(input.size(), input.type());
	ddy.create(input.size(), input.type());
	magnitudeOfGradient.create(input.size(), input.type());
	directionOfGradient.create(input.size(), input.type());

	// Set the objects to initial values
	for(int imageRowIndex = 0; imageRowIndex < input.rows; imageRowIndex++) {
		for(int imageColumnIndex = 0; imageColumnIndex < input.cols; imageColumnIndex++) {
			ddx.at<uchar>(imageRowIndex, imageColumnIndex) = (uchar) 0;
			ddy.at<uchar>(imageRowIndex, imageColumnIndex) = (uchar) 0;
			magnitudeOfGradient.at<uchar>(imageRowIndex, imageColumnIndex) = (uchar) 0;
			directionOfGradient.at<uchar>(imageRowIndex, imageColumnIndex) = (uchar) 0;
		}
	}

	// Then calculate the output values
	for(int imageRowIndex = 1; imageRowIndex < input.rows - 1; imageRowIndex++) {
		for(int imageColumnIndex = 1; imageColumnIndex < input.cols - 1; imageColumnIndex++) {
			int ddxAtX = convolveImageAt(input, imageRowIndex, imageColumnIndex, XKERNEL);
			// int ddxAtY = getDdyAtIndex();
			// int magnitudeOfGradientAtx = getMagnitudeOfGradientAtX();
			// int directionOfGradientAtx = getDirectionOfGradientAtX();

			ddx.at<uchar>(imageRowIndex, imageColumnIndex) = (uchar) ddxAtX;
		}
	}

	imwrite("ddx.jpg", ddx);
}

int convolveImageAt(cv::Mat &input, int row, int column, const cv::Mat &kernel) {


	int sum = 0;

	for(int kernelRow = 0; kernelRow < kernel.rows; kernelRow++) {
		for(int kernelColumn; kernelColumn < kernel.cols; kernelColumn++) {
			int imageRow = row - 1 + kernelRow;
			int imageColumn = column - 1 + kernelColumn;

			printf("%d\n", row);

			int imageval = ( int ) input.at<uchar>( imageRow, imageColumn );
			double kernalval = kernel.at<double>( kernelRow, kernelColumn );

			sum += imageval * kernalval;
		}
	}

	return sum;
}

/*

void calculateFirstDerivative(cv::Mat &input, cv::Mat &output, const cv::Mat &kernel) {

	// Initialise the output using the input
	output.create(input.size(), input.type());

	for(int imageRowIndex = 0; imageRowIndex < input.rows; imageRowIndex++) {
		for(int imageColumnIndex = 0; imageColumnIndex < input.cols; imageColumnIndex++) {
			output.at<uchar>(imageRowIndex, imageColumnIndex) = (uchar) 0;
		}
	}

	for(int imageRowIndex = 1; imageRowIndex < input.rows - 1; imageRowIndex++) {
		for(int imageColumnIndex = 1; imageColumnIndex < input.cols - 1; imageColumnIndex++) {

			 int pixelValue = 0;

			 for(int kernelRowIndex = 0; kernelRowIndex < kernel.rows; kernelRowIndex++) {
				 for(int kernelColumnIndex = 0; kernelColumnIndex < kernel.cols; kernelColumnIndex++) {
					 	int rowIndex = imageRowIndex + kernelRowIndex - 1;
						int columnIndex = imageColumnIndex + kernelColumnIndex - 1;

						int imageVal = ( int ) input.at<uchar> (rowIndex, columnIndex);
						int kernelVal = ( int ) kernel.at<double>( kernelRowIndex, kernelColumnIndex );
						pixelValue = pixelValue + (imageVal*kernelVal);
				 }
			 }

			 output.at<uchar>(imageRowIndex, imageColumnIndex) = (uchar) pixelValue;
		}
	}
}

void calculateMagnitude(cv::Mat &ddx, cv::Mat &ddy, cv::Mat &output) {

	// Use ddx or ddy
	output.create(ddx.size(), ddx.type());

	// Loop over the image, pixel by pixel
	for(int imageRow = 0; imageRow < ddx.rows; imageRow++) {
		for(int imageColumn = 0; imageColumn < ddx.cols; imageColumn++)	{
			int ddxImageVal = ( int ) ddx.at<uchar>( imageRow, imageColumn );
			int ddyImageVal = ( int ) ddy.at<uchar>( imageRow, imageColumn );

			int gradientAtPixel = abs(ddxImageVal) + abs(ddyImageVal);
			gradientAtPixel = gradientAtPixel > 255 ? 255:gradientAtPixel;
			output.at<uchar>(imageRow, imageColumn) = (uchar) gradientAtPixel;
		}
	}
}

void calculateGradientOrientation(cv::Mat &ddx, cv::Mat &ddy, cv::Mat &output) {

	// Use ddx or ddy
	output.create(ddx.size(), ddx.type());

	for(int imageRow = 0; imageRow < ddx.rows; imageRow++) {
		for(int imageColumn = 0; imageColumn < ddx.cols; imageColumn++)	{
			int ddxImageVal = ( int ) ddx.at<uchar>( imageRow, imageColumn );
			int ddyImageVal = ( int ) ddy.at<uchar>( imageRow, imageColumn );

			int directionAtPixel = 0;
			if(ddxImageVal != 0) {
				directionAtPixel = atan(ddyImageVal/ddxImageVal);
			}
			output.at<uchar>(imageRow, imageColumn) = (uchar) directionAtPixel;
		}
	}
}

void thresholdImage(cv::Mat &input, cv::Mat &output) {
	// Use ddx or ddy
	output.create(input.size(), input.type());

	for(int imageRow = 0; imageRow < input.rows; imageRow++) {
		for(int imageColumn = 0; imageColumn < input.cols; imageColumn++)	{
			int inVal = ( int ) input.at<uchar>( imageRow, imageColumn );

			int outval = 0;
			if(inVal > 10) {
				outval = 255;
			}

			output.at<uchar>(imageRow, imageColumn) = (uchar) outval;
		}
	}
}

*/
