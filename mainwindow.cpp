#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QFileDialog>
#include <QMessageBox>
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    count = 0;
    ui->setupUi(this);

    /* == 边缘检测 == */
//    Mat image2;
//    Canny(image,image2,10,100);
//    threshold(image2,image2,128,255,CV_THRESH_BINARY);


//    Mat w = Mat(650, 1300, CV_8UC3);
//    Mat left(w,Rect(0,0,650,650));
//    image.copyTo(left);
//    Mat right(w,Rect(650,0,1300,650));
//    image.copyTo(right);

//        im1.resize(500,600);
//        im2.resize(500,600);
//        Size sz1 = image.size();
//        Size sz2 = image1.size();

//        Mat im3(sz1.height, sz1.width+sz2.width, image.type());
//        Mat left(im3, Rect(0, 0, sz1.width, sz1.height));
//        image.copyTo(left);
//        Mat right(im3, Rect(sz1.width, 0, sz2.width, sz2.height));
//        image1.copyTo(right);
    //
//    Canny(image,image1,10,100);
//    threshold(image1,image1,128,255,CV_THRESH_BINARY);

    /* == 直线检测 == */
//    cv::vector<cv::Vec4i> lines;
//    cv::HoughLinesP(image2,lines,1,CV_PI/180,80,50,10);
//    cv::vector<cv::Vec4i>::const_iterator it=lines.begin();
//        while(it!=lines.end())
//        {
//            cv::Point pt1((*it)[0],(*it)[1]);
//            cv::Point pt2((*it)[2],(*it)[3]);
//            cv::line(image,pt1,pt2,cv::Scalar(0,255,0),2); //  线条宽度设置为2
//            ++it;
//        }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    openImage();
}
void MainWindow::openImage()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                    tr("Open Directory"), QDir::currentPath());
    travelDirectory(dir);
}
void MainWindow::travelDirectory(const QString & path){
    QDir dir(path);
    if (!dir.exists()) {
        //error
    }
    dir.setFilter(QDir::Files|QDir::NoDotAndDotDot);
    list = dir.entryInfoList();
    if(list.size()< 1 ) {
        //error
    }
    int i=0;
    do{
        QFileInfo file = list.at(i);
        QString filePath = file.absoluteFilePath();
        QString text = QString::number(i);
        text.append(QString(":     ")).append(filePath);
        ui->textBrowser->append(text);
        i++;
    } while(i < list.size());
}
int MainWindow::histogram(Mat img){
    float range[] = {0,255};
    const float* histRange = { range };
    Mat hist;
    Mat hsv;
    int hist_size = 255;
    int channels[] = {0};
    calcHist(&img, 1, channels, Mat(), hist, 1, &hist_size, &histRange, true, false);
    float result = hist.at<float>(0);
    ui->textBrowserHist->append(QString::number(result));
    if(result < 495000){
        ui->textBrowserHist->append(QString("Not Passed!"));
        return -1;
    }
    return 1;
}
void MainWindow::checkHistogram(Mat img){
    img = img;
}

void MainWindow::on_pushButton_histogram_clicked()
{
    int i=0;
    do{
        QFileInfo file = list.at(i);
        QString filePath = file.absoluteFilePath();
        QByteArray temp = filePath.toLatin1();
        const char * filePathChar = temp.data();  //convert QString to const char *
        Mat img = imread(filePathChar, 0);
        Mat img1;

        GaussianBlur(img, img1, Size(9, 9), 2, 2 );
        img1 = removeCircle(img1, 963, 1305, 900);

        threshold(img1, img1, 7, 255, 1);

        QString result_path = "/Users/mac/Desktop/result/img-";
        result_path.append(QString::number(i)).append(QString(".jpg"));
        QByteArray t_result_path = result_path.toLatin1();
        const char * r_result_path = t_result_path.data();
        imwrite(r_result_path, img1);

        for ( int i = 1; i < 10; i = i + 2 ){
            medianBlur(img1, img1, i);
        }
//        vector<Vec3f> circles;
//        HoughCircles(img1, circles, CV_HOUGH_GRADIENT, 1, img1.rows/8, 200, 22, 0, 0 );

//        for ( int i = 1; i < 11; i = i + 2 ){
//            medianBlur(img, img1, i);
//        }

//        for( size_t i = 0; i < circles.size(); i++ )
//            {
//                 Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
//                 int radius = cvRound(circles[i][2]);
//                 // draw the circle center
//                 circle( img1, center, 3, Scalar(100,100,100), -1, 8, 0 );
//                 // draw the circle outline
//                 circle( img1, center, radius, Scalar(100,100,100), 3, 8, 0 );
//            }

        int key = 0;
        key = histogram(img1);
        if(key == -1){
            count++;
            ui->textBrowserResult->append(filePath);
            QString error_path = "/Users/mac/Desktop/result/errors/error-";
            error_path.append(QString::number(i)).append(QString(".jpg"));
            QByteArray t_error_path = error_path.toLatin1();
            const char * r_error_path = t_error_path.data();
            imwrite(r_error_path, img);
        }
        i++;
     } while(i < list.size());
    QString result = "Not Passed Count:";
    result.append(QString::number(count));
    ui->textBrowserResult->append(result);
}
Mat MainWindow::removeCircle(Mat img, int center_rows, int center_cols, int r){
    int rows = img.rows;
    int cols = img.cols;
    for(int j = 0;j < rows;j++){
        for(int k = 0;k < cols;k++){
            int dist = (center_rows - j) * (center_rows - j) + (center_cols - k) * (center_cols - k);
            if(dist >= r*r){
                img.at<uchar>(j,k) = 0;
            }
        }
    }
    return img;
}
