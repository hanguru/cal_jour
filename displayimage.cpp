#include "displayimage.h"

DisplayImage::DisplayImage(IplImage *Ipl_rgb_src, IplImage *Ipl_depth_src, IplImage *Ipl_rgb_result_src)
{
    Ipl_rgb_disp = cvCloneImage(Ipl_rgb_src);
    Ipl_depth_disp = cvCloneImage(Ipl_depth_src);
    Ipl_rgb_result_disp = cvCloneImage(Ipl_rgb_result_src);

    //process(Ipl_rgb_src, Ipl_depth_src);
}

void DisplayImage::process(IplImage *Ipl_rgb_src, IplImage *Ipl_depth_src, IplImage *Ipl_rgb_result_src)
{
    while (display_image)
    {
        //while(Ipl_rgb_updating) {}
        //if (!rgb_updating)
        {
            //rgb_copying = 1;
            //Ipl_rgb_disp = cvCloneImage(Ipl_rgb_src);
            cvCopy(Ipl_rgb_src, Ipl_rgb_disp, NULL);
            cvCopy(Ipl_rgb_result_src, Ipl_rgb_result_disp, NULL);
            //Ipl_rgb_disp = Ipl_rgb_src;
            //rgb_copying = 0;
        }

        //while(depth_updating) {}
        //if (!depth_updating)
        {
            //depth_copying = 1;
            //Ipl_depth_disp = cvCloneImage(Ipl_depth_src);
            cvCopy(Ipl_depth_src, Ipl_depth_disp, NULL);
            //Ipl_depth_disp = Ipl_depth_src;
            //depth_copying = 0;
        }

        // depth value conversion for display
        unsigned short *p_imageData = (unsigned short *)Ipl_depth_disp->imageData;
        for(int yy=0; yy<WIN_SIZE_Y; yy++){
            for(int xx=0; xx<WIN_SIZE_X; xx++){
                int xx_inv = xx;//IN_SIZE_X -1 - xx;
                //p_imageData[xx+yy*WIN_SIZE_X] = 0;
                //p_imageData[xx+yy*WIN_SIZE_X] = (unsigned short)p_imagedData[xx_inv+yy*WIN_SIZE_X];
                p_imageData[xx+yy*WIN_SIZE_X] = (unsigned short)((float)p_imageData[xx_inv+yy*WIN_SIZE_X]/(maxpoint_depth)*(256*256-1));
            }
        }

        cvShowImage ("Color", Ipl_rgb_disp);
        cvShowImage ("Colo2r", Ipl_rgb_result_disp);
        cvShowImage ("Depth", Ipl_depth_disp);
        cvWaitKey(33);
    }
    cvReleaseImage( &Ipl_rgb_disp );
    cvReleaseImage( &Ipl_rgb_result_disp );
    cvReleaseImage( &Ipl_depth_disp );
    cvDestroyWindow("Color");
    cvDestroyWindow("Color2");
    cvDestroyWindow("Depth");
}

DisplayImage::~DisplayImage()
{
    cvReleaseImage( &Ipl_rgb_disp );
    cvReleaseImage( &Ipl_rgb_result_disp );
    cvReleaseImage( &Ipl_depth_disp );
    cvDestroyWindow("Color");
    cvDestroyWindow("Color2");
    cvDestroyWindow("Depth");
}
