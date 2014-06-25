#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cv::Mat image = cv::imread("/Users/mac/Desktop/1.jpg");
    cv::imshow("my image", image);
    cv::waitKey(50000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
