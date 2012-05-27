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
    QMessageBox msgBox;
    msgBox.setText("Kinect Calibration");
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
    cal_step1q *myCalStep1q = new cal_step1q(0); // 0: horizontal, 1: vertical
    myCalStep1q->start();
}
