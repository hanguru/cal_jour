#include "camerarunq.h"

CameraRunQ::CameraRunQ()
{
}

void CameraRunQ::Depth_to_IplImage (IplImage* image, xn::DepthGenerator g_depth,const XnDepthPixel* ppDepth, xn::DepthMetaData* g_depthMD)
{

    ppDepth = g_depthMD->Data();

    unsigned short *p_imageData = (unsigned short *)image->imageData;

    int tempmax=0, tempmin_x=0, tempmin_y=0, tempmin=256*256-1;
    for(int yy=0; yy<WIN_SIZE_Y; yy++){
        for(int xx=0; xx<WIN_SIZE_X; xx++){

            if(ppDepth[xx+yy*WIN_SIZE_X]>tempmax)
            {
                tempmax=ppDepth[xx+yy*WIN_SIZE_X];
            }
            else if( (ppDepth[xx+yy*WIN_SIZE_X]<tempmin) &&
                (ppDepth[xx+yy*WIN_SIZE_X]>10) )
            {
                tempmin=ppDepth[xx+yy*WIN_SIZE_X];
                tempmin_x = WIN_SIZE_X -1 - xx;
                tempmin_y = yy;
            }
        }
    }

    minpoint_x = tempmin_x;
    minpoint_y = tempmin_y;
    minpoint_depth = tempmin;
    maxpoint_depth = tempmax;

    // body depth
    body_depth=ppDepth[WIN_SIZE_X*(WIN_SIZE_Y-30) + WIN_SIZE_X/2];

    for(int yy=0; yy<WIN_SIZE_Y; yy++){
        for(int xx=0; xx<WIN_SIZE_X; xx++){
            int xx_inv = WIN_SIZE_X -1 - xx;
            //p_imageData[xx+yy*WIN_SIZE_X] = 0;
            p_imageData[xx+yy*WIN_SIZE_X] = (unsigned short)ppDepth[xx_inv+yy*WIN_SIZE_X];

            //p_imageData[xx+yy*WIN_SIZE_X] = (unsigned short)((float)ppDepth[xx_inv+yy*WIN_SIZE_X]/(tempmax)*(256*256-1));
            //p_imageData[xx+yy*WIN_SIZE_X] = (unsigned short)ppDepth[xx_inv+yy*WIN_SIZE_X];
        }
    }
}

void CameraRunQ::RGB_to_IplImage (IplImage* image,xn::ImageGenerator g_image, xn::ImageMetaData* g_imageMD)
{
    const XnRGB24Pixel* pImageRow = g_imageMD->RGB24Data();

    //XN_PIXEL_FORMAT_RGB24

    for(int yy=0; yy<WIN_SIZE_Y; yy++){
        for(int xx=0; xx<WIN_SIZE_X; xx++){
            int xx_inv = WIN_SIZE_X -1 - xx;
            image->imageData[3*(xx+yy*WIN_SIZE_X)+0]=pImageRow[xx_inv+yy*WIN_SIZE_X].nBlue;
            image->imageData[3*(xx+yy*WIN_SIZE_X)+1]=pImageRow[xx_inv+yy*WIN_SIZE_X].nGreen;
            image->imageData[3*(xx+yy*WIN_SIZE_X)+2]=pImageRow[xx_inv+yy*WIN_SIZE_X].nRed;
        }
    }
}

void CameraRunQ::run()
{
    xn::Context g_context;
    xn::DepthGenerator g_depth;
    xn::ImageGenerator g_image;
    const XnDepthPixel* ppDepth;

    ppDepth = NULL;

    XnStatus rc;
    xn::EnumerationErrors errors;

    rc = g_context.InitFromXmlFile(SAMPLE_XML_PATH, &errors);
    rc = g_context.FindExistingNode(XN_NODE_TYPE_DEPTH, g_depth);
    rc = g_context.FindExistingNode(XN_NODE_TYPE_IMAGE, g_image);

    // aligning rgb & depth
    g_depth.GetAlternativeViewPointCap().SetViewPoint(g_image);

    xn::ImageMetaData g_imageMD;
    xn::DepthMetaData g_depthMD;

    while(camera_update)
    {
        rc = g_context.WaitAnyUpdateAll();

        // rgb & depth capture
        g_depth.GetMetaData(g_depthMD);
        g_image.GetMetaData(g_imageMD);


        //while (depth_copying) {}
        //depth_updating = 1;
        //depth_updating = 0;
        //while(rgb_copying) {}
        //rgb_updating = 1;
        //rgb_updating = 0;


        // rgb & depth conversion
        Depth_to_IplImage( Ipl_depth, g_depth, ppDepth, &g_depthMD );
        RGB_to_IplImage(Ipl_rgb, g_image, &g_imageMD);

    } // while (camera_update)

}





