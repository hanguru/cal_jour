#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    // for cvFitLine function
    int SAMPLE_CNT, Hpoints_cnt, Vpoints_cnt;
    CvPoint2D32f *Hpoints, *Vpoints;
    float HFitResult[4], VFitResult[4];// to store the results

    SAMPLE_CNT=51; Hpoints_cnt=0; Vpoints_cnt=0;
    Hpoints=(CvPoint2D32f*)malloc( SAMPLE_CNT * sizeof(Hpoints[0]));
    Vpoints=(CvPoint2D32f*)malloc( SAMPLE_CNT * sizeof(Vpoints[0]));

    CvPoint *Hsamples_L, *Hsamples_R;
    Hsamples_L=(CvPoint*)malloc( SAMPLE_CNT * sizeof(Hsamples_L[0]));
    Hsamples_R=(CvPoint*)malloc( SAMPLE_CNT * sizeof(Hsamples_R[0]));

    float d1, d2, X1, X2;

    Hsamples_L[ 0].x = -125;
    Hsamples_L[ 1].x = -126;
    Hsamples_L[ 2].x = -126;
    Hsamples_L[ 3].x = -126;
    Hsamples_L[ 4].x = -130;
    Hsamples_L[ 5].x = -132;
    Hsamples_L[ 6].x = -132;
    Hsamples_L[ 7].x = -132;
    Hsamples_L[ 8].x = -132;
    Hsamples_L[ 9].x = -132;
    Hsamples_L[10].x = -132;
    Hsamples_L[11].x = -132;
    Hsamples_L[12].x = -127;
    Hsamples_L[13].x = -127;
    Hsamples_L[14].x = -118;
    Hsamples_L[15].x = -117;
    Hsamples_L[16].x = -117;
    Hsamples_L[17].x = -112;
    Hsamples_L[18].x = -112;
    Hsamples_L[19].x = -112;
    Hsamples_L[20].x = -107;
    Hsamples_L[21].x = -106;
    Hsamples_L[22].x = -105;
    Hsamples_L[23].x = -104;
    Hsamples_L[24].x = -95;
    Hsamples_L[25].x = -95;
    Hsamples_L[26].x = -87;
    Hsamples_L[27].x = -102;
    Hsamples_L[28].x = -102;
    Hsamples_L[29].x = -102;
    Hsamples_L[30].x = -107;
    Hsamples_L[31].x = -107;
    Hsamples_L[32].x = -106;
    Hsamples_L[33].x = -106;
    Hsamples_L[34].x = -107;
    Hsamples_L[35].x = -107;
    Hsamples_L[36].x = -108;
    Hsamples_L[37].x = -108;
    Hsamples_L[38].x = -107;
    Hsamples_L[39].x = -107;
    Hsamples_L[40].x = -107;
    Hsamples_L[41].x = -107;
    Hsamples_L[42].x = -107;
    Hsamples_L[43].x = -107;
    Hsamples_L[44].x = -101;
    Hsamples_L[45].x = -93;
    Hsamples_L[46].x = -93;
    Hsamples_L[47].x = -93;
    Hsamples_L[48].x = -92;
    Hsamples_L[49].x = -88;
    Hsamples_L[50].x = -88;
    Hsamples_L[ 0].y = 949;
    Hsamples_L[ 1].y = 941;
    Hsamples_L[ 2].y = 941;
    Hsamples_L[ 3].y = 940;
    Hsamples_L[ 4].y = 892;
    Hsamples_L[ 5].y = 858;
    Hsamples_L[ 6].y = 857;
    Hsamples_L[ 7].y = 839;
    Hsamples_L[ 8].y = 839;
    Hsamples_L[ 9].y = 838;
    Hsamples_L[10].y = 799;
    Hsamples_L[11].y = 799;
    Hsamples_L[12].y = 768;
    Hsamples_L[13].y = 766;
    Hsamples_L[14].y = 738;
    Hsamples_L[15].y = 737;
    Hsamples_L[16].y = 737;
    Hsamples_L[17].y = 713;
    Hsamples_L[18].y = 713;
    Hsamples_L[19].y = 712;
    Hsamples_L[20].y = 692;
    Hsamples_L[21].y = 691;
    Hsamples_L[22].y = 691;
    Hsamples_L[23].y = 690;
    Hsamples_L[24].y = 684;
    Hsamples_L[25].y = 684;
    Hsamples_L[26].y = 726;
    Hsamples_L[27].y = 754;
    Hsamples_L[28].y = 756;
    Hsamples_L[29].y = 757;
    Hsamples_L[30].y = 788;
    Hsamples_L[31].y = 789;
    Hsamples_L[32].y = 789;
    Hsamples_L[33].y = 789;
    Hsamples_L[34].y = 817;
    Hsamples_L[35].y = 818;
    Hsamples_L[36].y = 862;
    Hsamples_L[37].y = 897;
    Hsamples_L[38].y = 898;
    Hsamples_L[39].y = 899;
    Hsamples_L[40].y = 900;
    Hsamples_L[41].y = 901;
    Hsamples_L[42].y = 903;
    Hsamples_L[43].y = 904;
    Hsamples_L[44].y = 932;
    Hsamples_L[45].y = 953;
    Hsamples_L[46].y = 955;
    Hsamples_L[47].y = 969;
    Hsamples_L[48].y = 972;
    Hsamples_L[49].y = 998;
    Hsamples_L[50].y = 999;
    Hsamples_R[ 0].x = 174;
    Hsamples_R[ 1].x = 175;
    Hsamples_R[ 2].x = 175;
    Hsamples_R[ 3].x = 175;
    Hsamples_R[ 4].x = 179;
    Hsamples_R[ 5].x = 180;
    Hsamples_R[ 6].x = 180;
    Hsamples_R[ 7].x = 181;
    Hsamples_R[ 8].x = 181;
    Hsamples_R[ 9].x = 181;
    Hsamples_R[10].x = 181;
    Hsamples_R[11].x = 181;
    Hsamples_R[12].x = 183;
    Hsamples_R[13].x = 183;
    Hsamples_R[14].x = 184;
    Hsamples_R[15].x = 184;
    Hsamples_R[16].x = 184;
    Hsamples_R[17].x = 184;
    Hsamples_R[18].x = 184;
    Hsamples_R[19].x = 184;
    Hsamples_R[20].x = 184;
    Hsamples_R[21].x = 184;
    Hsamples_R[22].x = 184;
    Hsamples_R[23].x = 184;
    Hsamples_R[24].x = 185;
    Hsamples_R[25].x = 185;
    Hsamples_R[26].x = 186;
    Hsamples_R[27].x = 186;
    Hsamples_R[28].x = 186;
    Hsamples_R[29].x = 186;
    Hsamples_R[30].x = 187;
    Hsamples_R[31].x = 187;
    Hsamples_R[32].x = 187;
    Hsamples_R[33].x = 187;
    Hsamples_R[34].x = 188;
    Hsamples_R[35].x = 188;
    Hsamples_R[36].x = 189;
    Hsamples_R[37].x = 187;
    Hsamples_R[38].x = 188;
    Hsamples_R[39].x = 188;
    Hsamples_R[40].x = 189;
    Hsamples_R[41].x = 189;
    Hsamples_R[42].x = 189;
    Hsamples_R[43].x = 189;
    Hsamples_R[44].x = 192;
    Hsamples_R[45].x = 200;
    Hsamples_R[46].x = 200;
    Hsamples_R[47].x = 199;
    Hsamples_R[48].x = 199;
    Hsamples_R[49].x = 200;
    Hsamples_R[50].x = 200;
    Hsamples_R[ 0].y = 894;
    Hsamples_R[ 1].y = 895;
    Hsamples_R[ 2].y = 893;
    Hsamples_R[ 3].y = 892;
    Hsamples_R[ 4].y = 890;
    Hsamples_R[ 5].y = 891;
    Hsamples_R[ 6].y = 891;
    Hsamples_R[ 7].y = 889;
    Hsamples_R[ 8].y = 890;
    Hsamples_R[ 9].y = 890;
    Hsamples_R[10].y = 890;
    Hsamples_R[11].y = 889;
    Hsamples_R[12].y = 894;
    Hsamples_R[13].y = 895;
    Hsamples_R[14].y = 901;
    Hsamples_R[15].y = 901;
    Hsamples_R[16].y = 901;
    Hsamples_R[17].y = 901;
    Hsamples_R[18].y = 902;
    Hsamples_R[19].y = 902;
    Hsamples_R[20].y = 901;
    Hsamples_R[21].y = 902;
    Hsamples_R[22].y = 902;
    Hsamples_R[23].y = 902;
    Hsamples_R[24].y = 909;
    Hsamples_R[25].y = 909;
    Hsamples_R[26].y = 932;
    Hsamples_R[27].y = 930;
    Hsamples_R[28].y = 930;
    Hsamples_R[29].y = 930;
    Hsamples_R[30].y = 929;
    Hsamples_R[31].y = 929;
    Hsamples_R[32].y = 929;
    Hsamples_R[33].y = 929;
    Hsamples_R[34].y = 929;
    Hsamples_R[35].y = 929;
    Hsamples_R[36].y = 928;
    Hsamples_R[37].y = 935;
    Hsamples_R[38].y = 935;
    Hsamples_R[39].y = 933;
    Hsamples_R[40].y = 934;
    Hsamples_R[41].y = 935;
    Hsamples_R[42].y = 935;
    Hsamples_R[43].y = 935;
    Hsamples_R[44].y = 935;
    Hsamples_R[45].y = 926;
    Hsamples_R[46].y = 925;
    Hsamples_R[47].y = 924;
    Hsamples_R[48].y = 925;
    Hsamples_R[49].y = 921;
    Hsamples_R[50].y = 921;


    for (int i=0; i<SAMPLE_CNT; i++)
    {
        d1 = (float)(Hsamples_L[i].y) / 256;
        d2 = (float)(Hsamples_R[i].y) / 256;
        X1 =  (float)(Hsamples_L[i].x) * d1;
        X2 =  (float)(Hsamples_R[i].x) * d2;

        Hpoints[i].x = (X1-X2) * (X1-X2);
        Hpoints[i].y = (d1-d2) * (d1-d2);
        Hpoints_cnt ++;
    }

    CvMat Hpoint_mat = cvMat( 1, Hpoints_cnt, CV_32FC2, Hpoints );
    cvFitLine(&Hpoint_mat,CV_DIST_HUBER ,0,0.01,0.01,HFitResult);
    //cvFitLine(&Hpoint_mat,CV_DIST_L1 ,0,0.1,0.1,HFitResult);
    //cvFitLine(Hpoints,CV_DIST_HUBER ,0,0.01,0.01,HFitResult);

    float fit_angle = HFitResult[1];
    fit_angle = (float)(-1)/fit_angle;
    float focal_x = sqrt(fit_angle);

    QMessageBox msgBox;
    //msgBox.setText("Kinect Calibration");
    char s_text[512];
    sprintf( s_text, "Kinect Calibration, %f %e %f %f focal_length=%f",HFitResult[0], HFitResult[1], HFitResult[2], HFitResult[3], focal_x);
    msgBox.setText(s_text);
    msgBox.exec();
}

void MainWindow::on_actionExit_triggered()
{
    display_image = 0;
    camera_update = 0;
    exit(0);
}

void MainWindow::on_actionRun_triggered()
{
    if (camera_update==0)
    {
        camera_update = 1;
        CameraRunQ *camq = new CameraRunQ;
        camq->start(QThread::HighestPriority);
    }
    else
    {
        camera_update = 0;
    }
}

void MainWindow::on_actionDisplay_triggered()
{
    if (display_image==0)
    {
        display_image = 1;
        DisplayImage *dis_img = new DisplayImage(Ipl_rgb, Ipl_depth, Ipl_rgb_result);
        dis_img->process(Ipl_rgb, Ipl_depth, Ipl_rgb_result);
    }
    else
    {
        display_image = 0;
    }

}

void MainWindow::on_actionStep1_triggered()
{
    cal_step1q *myCalStep1q = new cal_step1q(1); // 0: horizontal, 1: vertical
    myCalStep1q->start();
}
