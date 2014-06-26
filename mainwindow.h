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
private slots:
    void on_pushButton_clicked();
    void openImage(); //add a new openImage function to the project
    void travelDirectory(const QString &);
    int check(Mat);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
