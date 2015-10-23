#include <opencv2\core.hpp>
#include <opencv2\objdetect.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

string eye_cascade_name = "C:\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml";
string face_cascade_name = "C:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
CascadeClassifier eye_cascade;
CascadeClassifier face_cascade;
string window_name = "camera";

void detectAndDisplay(Mat frame);

int main()
{
	cv::Mat frame;
	cv::VideoCapture cap(0);
	
	face_cascade.load(face_cascade_name);
	eye_cascade.load(eye_cascade_name);
	if (!cap.isOpened())
		//如果沒有開啟成功，則離開程式
	{
		return -1;
	}

	while (true)
	{
		if (!cap.read(frame))
			break;
		cv::Mat src = cv::Mat(frame);
		
		detectAndDisplay(src);
		
		
	}
}

void detectAndDisplay(Mat frame) {
	std::vector<Rect> faces;
	std::vector<Rect> eyes;
	Mat frame_gray;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);


	equalizeHist(frame_gray, frame_gray);

	eye_cascade.detectMultiScale(frame_gray, eyes, 1.20, 10, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	
	cout << faces.size() << endl;
	cout << eyes.size() << endl;
	for (int i = 0; i < faces.size(); i++) {
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(0, 255, 0), 4, 8, 0);
	}

	for (int i = 0; i < eyes.size(); i++) {
		Point center(eyes[i].x + eyes[i].width*0.5, eyes[i].y + eyes[i].height*0.5);
		ellipse(frame, center, Size(eyes[i].width*0.5, eyes[i].height*0.5), 0, 0, 360, Scalar(0, 255, 255), 4, 8, 0);
	}

	imshow(window_name, frame);
	cv::waitKey(30);
}