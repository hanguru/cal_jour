#ifndef DISPLAYIMAGE_H
#define DISPLAYIMAGE_H

#include <cv.h>
#include <highgui.h>
//#include <QThread>
#include <QDebug>

extern IplImage *Ipl_rgb, *Ipl_depth, *Ipl_rgb_result, *Ipl_depth_result;
extern int WIN_SIZE_X;
extern int WIN_SIZE_Y;
extern int minpoint_x, minpoint_y, minpoint_depth, maxpoint_depth, body_depth;

//extern int depth_updating, rgb_updating, depth_copying, rgb_copying;
extern int camera_update, display_image;

class DisplayImage //: public QThread
{
public:
    DisplayImage(IplImage *Ipl_rgb_src, IplImage *Ipl_depth_src, IplImage *Ipl_rgb_result_src);
    ~DisplayImage();
    IplImage *Ipl_rgb_disp, *Ipl_depth_disp, *Ipl_rgb_result_disp;
    void process(IplImage *Ipl_rgb_src, IplImage *Ipl_depth_src, IplImage *Ipl_rgb_result_src);

protected:
    //void run();
};

#endif // DISPLAYIMAGE_H
