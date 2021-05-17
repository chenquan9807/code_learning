#include "ViBe.h"
#include <cstdio>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat frame, gray, mask;
	VideoCapture capture;
	capture.open(0);
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	if (!capture.isOpened())
	{
		cout << "No camera or video input!\n" << endl;
		return -1;
	}

	ViBe_BGS Vibe_Bgs;
	bool count = true;

	while (1)
	{
		capture >> frame;
		if (frame.empty())
			continue;

		cvtColor(frame, gray, CV_RGB2GRAY);
		if (count)
		{
			Vibe_Bgs.init(gray);
			Vibe_Bgs.processFirstFrame(gray);
			cout << " Training ViBe complete!" << endl;
			count = false;
		}
		else
		{
			Vibe_Bgs.testAndUpdate(gray);
			mask = Vibe_Bgs.getMask();
			morphologyEx(mask, mask, MORPH_OPEN, Mat());
			imshow("mask", mask);
		}


		imshow("input", frame);

		if (cvWaitKey(10) == 27)
			break;
	}

	return 0;
}