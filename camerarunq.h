#ifndef CAMERARUNQ_H
#define CAMERARUNQ_H
#define SAMPLE_XML_PATH "/root/work/kinect/OpenNI/Samples/Config/SamplesConfig.xml"

#include <QThread>
#include <XnCppWrapper.h>
#include <cv.h>
#include <QDebug>

extern IplImage *Ipl_rgb, *Ipl_depth, *Ipl_rgb_result, *Ipl_depth_result;
extern int WIN_SIZE_X;
extern int WIN_SIZE_Y;
extern int minpoint_x, minpoint_y, minpoint_depth, maxpoint_depth, body_depth;

//extern int depth_updating, rgb_updating, depth_copying, rgb_copying;
extern int camera_update, display_image;

class CameraRunQ : public QThread
{
    //Q_OBJECT
public:
    CameraRunQ();
private:
    void Depth_to_IplImage (IplImage* image, xn::DepthGenerator g_depth,const XnDepthPixel* ppDepth, xn::DepthMetaData* g_depthMD);
    void RGB_to_IplImage (IplImage* image,xn::ImageGenerator g_image, xn::ImageMetaData* g_imageMD);


protected:
    void run();
};

#endif // CAMERARUNQ_H
