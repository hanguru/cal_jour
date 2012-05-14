#ifndef CAL_STEP1Q_H
#define CAL_STEP1Q_H

#include <cv.h>
#include <highgui.h>
#include <XnCppWrapper.h>
//#include <gl\glut.h>
//#include <gl\GL.h>
//#include <gl\GLU.h>

#include <QDebug>
#include <QThread>

#define CAL_NUM 100

extern IplImage *Ipl_rgb, *Ipl_depth, *Ipl_rgb_result, *Ipl_depth_result;
extern int WIN_SIZE_X;
extern int WIN_SIZE_Y;
extern int minpoint_x, minpoint_y, minpoint_depth, maxpoint_depth, body_depth;

//extern int depth_updating, rgb_updating, depth_copying, rgb_copying;
extern int camera_update, display_image;

class cal_step1q : public QThread
{
public:
    cal_step1q(int direction);
    ~cal_step1q();

private:
    struct cal_data
    {
        float depth;
        float length;
    };

    //cal_data h_cal_data[CAL_NUM], v_cal_data[CAL_NUM];
    //CvPoint left_pt[CAL_NUM], right_pt[CAL_NUM];
    //int h_cal_num, v_cal_num;
    //float left_x_ave, left_y_ave, right_x_ave, right_y_ave, left_depth_ave, right_depth_ave;

    cal_data h_cal_data[CAL_NUM], v_cal_data[CAL_NUM];
    int h_cal_num, v_cal_num, focal_x_num, focal_y_num;
    CvPoint left_pt[CAL_NUM], right_pt[CAL_NUM], top_pt[CAL_NUM], bottom_pt[CAL_NUM];
    float focal_x[CAL_NUM*CAL_NUM], focal_y[CAL_NUM*CAL_NUM];
    float left_x_ave, left_y_ave, right_x_ave, right_y_ave, left_depth_ave, right_depth_ave;
    float top_x_ave, top_y_ave, bottom_x_ave, bottom_y_ave, top_depth_ave, bottom_depth_ave;
    int focal_test_num;

    IplImage *Ipl_depth_disp, *Ipl_calibration_test;
    int direction;

    void run();
    void operate();//IplImage *Ipl_depth_disp, int minpoint_depth, int direction);

};

#endif // CAL_STEP1Q_H
