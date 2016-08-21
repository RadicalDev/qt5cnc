#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    double XStepSize;
    double XCurrentPos;
    double XTravelRate;
    double XFeedRate;
    double XMax;
    double XMin;

    double YStepSize;
    double YCurrentPos;
    double YTravelRate;
    double YFeedRate;
    double YMax;
    double YMin;

    double ZStepSize;
    double ZCurrentPos;
    double ZTravelRate;
    double ZFeedRate;
    double ZMax;
    double ZMin;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void sendGCode();
    void updateConsole(QString);

    void setXStepSize();
    void stepXUp();
    void stepXDown();
    void zeroXAxis();
    void setXTravelRate();
    void setXFeedRate();
    void setXMax();
    void setXMin();
    void updateXPos();

    void setYStepSize();
    void stepYUp();
    void stepYDown();
    void zeroYAxis();
    void setYTravelRate();
    void setYFeedRate();
    void setYMax();
    void setYMin();
    void updateYPos();

    void setZStepSize();
    void stepZUp();
    void stepZDown();
    void zeroZAxis();
    void setZTravelRate();
    void setZFeedRate();
    void setZMax();
    void setZMin();
    void updateZPos();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
