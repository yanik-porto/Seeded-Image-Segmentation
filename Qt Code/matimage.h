#ifndef MATIMAGE_H
#define MATIMAGE_H

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include <QMouseEvent>
#include <windows.h>

using namespace cv;
using namespace std;

class matImage : public cv::Mat
{
public:
    matImage();
    matImage(const string&);
    matImage(const Mat &mImg);
    ~matImage();


private:
    bool click;
    string winName;
};

#endif // MATIMAGE_H
