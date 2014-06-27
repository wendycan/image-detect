#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv/cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/highgui.h>
#include <QFileDialog>
using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    QString     FileOpName; //declare FileOpName as IplImage
    IplImage*   imagerd; //declare imagerd as IplImage
    QFileInfoList list;
    int count;
private slots:
    void on_pushButton_clicked();
    void openImage(); //add a new openImage function to the project
    void travelDirectory(const QString &);
    int histogram(Mat);
    void checkHistogram(Mat);
    void on_pushButton_histogram_clicked();
    Mat removeCircle(Mat, int, int, int);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
