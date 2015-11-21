#include "matimage.h"

string GetWindowTitle()
{
    char wnd_title[256];
    HWND hwnd=GetForegroundWindow();
    GetWindowTextA(hwnd,wnd_title,sizeof(wnd_title));
    cout<<wnd_title<<endl;
    return wnd_title;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    Mat* input = (Mat*)userdata;

    if(event==EVENT_LBUTTONDOWN)
    {
        //click=!click;
        //cout<<click<<endl;
    }

    else if ( event == EVENT_MOUSEMOVE )
    {
    //cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

        if(true)
        {
            circle(*input,cvPoint(x,y),2,CV_RGB(0,255,0),4);
            imshow(GetWindowTitle(),*input);
        }
    }
}

matImage::matImage():
    cv::Mat(),
    click(false)
{
    setMouseCallback(GetWindowTitle(),CallBackFunc,this->data);
}

matImage::matImage(const string &filename):
    click(false)
{
    *this=imread(filename);
    setMouseCallback(GetWindowTitle(),CallBackFunc,this->data);
}

matImage::matImage(const Mat &mImg):
    cv::Mat(mImg),
    click(false),
    winName("name")
{
    //namedWindow(winName,0);
    setMouseCallback(GetWindowTitle(),CallBackFunc,this->data);
}

matImage::~matImage()
{

}
