#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <camerarunq.h>
#include <displayimage.h>
#include <cal_step1q.h>

extern int camera_update, display_image;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionStep1_triggered();
    void on_actionDisplay_triggered();
    void on_actionRun_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
};

#endif // MAINWINDOW_H
