
#include "sobel.h"

bool loadImage(char* imageName, int argc, cv::Mat &image);

int main( int argc, char** argv )
{
  // Load an initial image
 cv::Mat image;
 if(loadImage(argv[1], argc, image) == false) {
   return 0;
 }

 //GaussianBlur( image, image, Size(5,5), 0, 0, BORDER_DEFAULT );

 // Convert the image to gray
 cv::Mat gray_image = image.clone();
 //cvtColor( image, gray_image, CV_BGR2GRAY );

 generateSobelImages(image);
 return 0;
}

bool loadImage(char* imageName, int argc, cv::Mat &image) {
  image = imread(imageName, CV_LOAD_IMAGE_GRAYSCALE);

  if( argc != 2 || !image.data )
  {
    printf( " No image data \n " );
    return false;
  }

  return true;
}
