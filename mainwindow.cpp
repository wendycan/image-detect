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
    ui->setupUi(this);
//    Mat image = imread("/Users/mac/Desktop/demo.jpg");

//    cvtColor(image,image,CV_BGR2GRAY);

    /* == 边缘检测 == */
//    Mat image2;
//    Canny(image,image2,10,100);
//    threshold(image2,image2,128,255,CV_THRESH_BINARY);

    /* == 滤波处理 == */
//    Mat image1;
//    blur(image,image1,Size(5,5));
//    GaussianBlur(image, image1, Size(5,5),1.5);

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

    /* == 二值化 ==*/
//    Mat image1;
//    float temp;
//    for(int i=0;i<image.rows;i++){
//        for(int j=0;j<image.cols;j++){
//            temp = image.at<float>(i,j);
//        }
//    }
//    threshold(image,image1,220,255,CV_THRESH_BINARY);

//    namedWindow("origion", CV_WINDOW_AUTOSIZE);
//    imshow("origion", w);
//    QImage qimage = mat2qimage(image);
//    QImage qimage1 = mat2qimage(image1);

//    namedWindow("addfilter", CV_WINDOW_AUTOSIZE);
//    resizeWindow("addfilter", 500,500);
//    imshow("addfilter", im3);

//    namedWindow("direct", CV_WINDOW_AUTOSIZE);
//    resizeWindow("direct", 500,500);
//    imshow("direct", image2);

//    waitKey(50000);
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
void MainWindow::openImage()
{
    //declare FileOpName as the choosen opened file name
     QString dir = QFileDialog::getExistingDirectory(this,
                                    tr("Open Directory"), QDir::currentPath());
    travelDirectory(dir);
    //Check if FileOpName exist or not
//    if (!FileOpName.isEmpty()) {
//        QImage image(FileOpName);
//        if (image.isNull()) {
//            QMessageBox::information(this, tr("Face Recognition"),
//                                     tr("Cannot load %1.").arg(FileOpName));

//            return;
//        }

//    }
    //function to load the image whenever fName is not empty
//        if( FileOpName.size() )
//        {
//        imagerd = cvLoadImage(FileOpName.toAscii().data());
//        QImage imageView = QImage((const unsigned char*)(imagerd->imageData), imagerd->width,imagerd->height,QImage::Format_RGB888).rgbSwapped();
//        ui->label->setPixmap(QPixmap::fromImage(imageView));
//        Mat image = imread("/Users/mac/Desktop/demo.jpg");
//        namedWindow("my window", CV_WINDOW_NORMAL);
//        resizeWindow("my window", 500,500);
//        imshow("my window", image);
//        waitKey(50000);
//        }
}

void MainWindow::on_pushButton_clicked()
{
    openImage();
}
void MainWindow::travelDirectory(const QString & path){
    QDir dir(path);
    if (!dir.exists()) {
        //error
    }
    dir.setFilter(QDir::Files|QDir::NoDotAndDotDot);
    QFileInfoList list = dir.entryInfoList();
    if(list.size()< 1 ) {
        //error
    }
    int i=0;
    do{
        QFileInfo file = list.at(i);
        QString filePath = file.absoluteFilePath();
        ui->textBrowser->append(filePath);
        QByteArray temp = filePath.toLatin1();
        const char * filePathChar = temp.data();  //convert QString to const char *
        Mat img = imread(filePathChar);
        check(img);
        i++;
    } while(i < list.size());
}
int MainWindow::check(Mat img){
//    imshow("ori", img);
//    img = img;
    return 1;
}
