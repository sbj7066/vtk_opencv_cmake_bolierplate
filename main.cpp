#include <iostream>
 
using namespace std;
#include <opencv2/opencv.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <vtkSmartPointer.h>

int main()
{
    cv::Mat image;
    image = cv::imread("KakaoTalk_20230206_102145381.jpg");
 
    while(true)
    {
        cv::namedWindow("image_001");
        cv::imshow("image_001",image);
 
        cv::Mat gray_image;
        cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY); // 흑백영상으로 변환
 
        cv::namedWindow("Gray_image");
        cv::imshow("Gray_image", gray_image);  // 흑백 영상 출력
 
        // get a adaptive threshold image
        cv::Mat athimage;
        auto clahe = cv::createCLAHE();
        clahe->apply(gray_image, athimage);

        //cv::adaptiveThreshold(gray_image, athimage, 255, 
        //                      cv::ADAPTIVE_THRESH_MEAN_C, 
        //                      cv::THRESH_BINARY, 11, 7);
 
        cv::namedWindow("Threshold Image");
        cv::imshow("Threshold Image", athimage);
        cv::imwrite("result.jpg", athimage);
        //cv::imshow("Triple Image", gray_image * 3);
 
        int key = cv::waitKey(10);
        
        if(key == 27)      //ESC key
            break;
    }
 
    return 0;
}