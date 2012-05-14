#include <QtGui/QApplication>
#include "mainwindow.h"
#include <cv.h>
#include <highgui.h>

IplImage *Ipl_rgb, *Ipl_depth, *Ipl_rgb_result, *Ipl_depth_result;
int WIN_SIZE_X;
int WIN_SIZE_Y;
int minpoint_x, minpoint_y, minpoint_depth, maxpoint_depth, body_depth;
//int depth_updating, rgb_updating, depth_copying, rgb_copying, rgb_result_copying;
int camera_update, display_image;

int main(int argc, char *argv[])
{
    // Initialization
    WIN_SIZE_X = 640;
    WIN_SIZE_Y = 480;

    minpoint_x = 0;
    minpoint_y = 0;
    minpoint_depth = 0;
    maxpoint_depth = 256*256 -1;
    body_depth = 0;
    /*
    depth_updating = 0;
    rgb_updating = 0;
    depth_copying = 0;
    rgb_copying = 0;
    rgb_result_copying = 0;
    */
    camera_update = 0;
    display_image = 0;

    Ipl_rgb = cvCreateImage(cvSize(WIN_SIZE_X, WIN_SIZE_Y),8, 3);
    Ipl_rgb_result = cvCreateImage(cvSize(WIN_SIZE_X, WIN_SIZE_Y),8, 3);
    Ipl_depth = cvCreateImage(cvSize(WIN_SIZE_X, WIN_SIZE_Y),16 , 1);
    Ipl_depth_result = cvCreateImage(cvSize(WIN_SIZE_X, WIN_SIZE_Y),16 , 1);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
