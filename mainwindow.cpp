#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  
{
    ui->setupUi(this);


    // X Axis
    XStepSize = 1;
    XCurrentPos = 0;
    XTravelRate = 800;
    XFeedRate = 500;
    XMax = 115;
    XMin = 0;

    ui->lineEditXStepSize->setText(QString::number(XStepSize));
    ui->lcdNumberXPos->display(XCurrentPos);
    ui->lineEditXTravel->setText(QString::number(XTravelRate));
    ui->lineEditXFeed->setText(QString::number(XFeedRate));
    ui->lineEditXMax->setText(QString::number(XMax));
    ui->lineEditXMin->setText(QString::number(XMin));

    connect(ui->lineEditXStepSize, &QLineEdit::returnPressed, this, &MainWindow::setXStepSize);
    connect(ui->lineEditXMax, &QLineEdit::returnPressed, this, &MainWindow::setXMax);
    connect(ui->lineEditXMin, &QLineEdit::returnPressed, this, &MainWindow::setXMin);
    connect(ui->pushButtonXPlus, &QPushButton::clicked, this, &MainWindow::stepXUp);
    connect(ui->pushButtonXMinus, &QPushButton::clicked, this, &MainWindow::stepXDown);
    connect(ui->pushButtonXZero, &QPushButton::clicked, this, &MainWindow::zeroXAxis);
    connect(ui->lineEditXTravel, &QLineEdit::returnPressed, this, &MainWindow::setXTravelRate);
    connect(ui->lineEditXFeed, &QLineEdit::returnPressed, this, &MainWindow::setXFeedRate);

    // Y Axis
    YStepSize = 1;
    YCurrentPos = 0;
    YTravelRate = 800;
    YFeedRate = 500;
    YMax = 205;
    YMin = 0;

    ui->lineEditYStepSize->setText(QString::number(YStepSize));
    ui->lcdNumberYPos->display(YCurrentPos);
    ui->lineEditYTravel->setText(QString::number(YTravelRate));
    ui->lineEditYFeed->setText(QString::number(YFeedRate));
    ui->lineEditYMax->setText(QString::number(YMax));
    ui->lineEditYMin->setText(QString::number(YMin));

    connect(ui->lineEditYStepSize, &QLineEdit::returnPressed, this, &MainWindow::setYStepSize);
    connect(ui->lineEditYMax, &QLineEdit::returnPressed, this, &MainWindow::setYMax);
    connect(ui->lineEditYMin, &QLineEdit::returnPressed, this, &MainWindow::setYMin);
    connect(ui->pushButtonYPlus, &QPushButton::clicked, this, &MainWindow::stepYUp);
    connect(ui->pushButtonYMinus, &QPushButton::clicked, this, &MainWindow::stepYDown);
    connect(ui->pushButtonYZero, &QPushButton::clicked, this, &MainWindow::zeroYAxis);
    connect(ui->lineEditYTravel, &QLineEdit::returnPressed, this, &MainWindow::setYTravelRate);
    connect(ui->lineEditYFeed, &QLineEdit::returnPressed, this, &MainWindow::setYFeedRate);

    // Z Axis
    ZStepSize = 0.1;
    ZCurrentPos = 0;
    ZTravelRate = 500;
    ZFeedRate = 200;
    ZMax = 48;
    ZMin = 0;

    ui->lineEditZStepSize->setText(QString::number(ZStepSize));
    ui->lcdNumberZPos->display(ZCurrentPos);
    ui->lineEditZTravel->setText(QString::number(ZTravelRate));
    ui->lineEditZFeed->setText(QString::number(ZFeedRate));
    ui->lineEditZMax->setText(QString::number(ZMax));
    ui->lineEditZMin->setText(QString::number(ZMin));

    connect(ui->lineEditZStepSize, &QLineEdit::returnPressed, this, &MainWindow::setZStepSize);
    connect(ui->lineEditZMax, &QLineEdit::returnPressed, this, &MainWindow::setZMax);
    connect(ui->lineEditZMin, &QLineEdit::returnPressed, this, &MainWindow::setZMin);
    connect(ui->pushButtonZPlus, &QPushButton::clicked, this, &MainWindow::stepZUp);
    connect(ui->pushButtonZMinus, &QPushButton::clicked, this, &MainWindow::stepZDown);
    connect(ui->pushButtonZZero, &QPushButton::clicked, this, &MainWindow::zeroZAxis);
    connect(ui->lineEditZTravel, &QLineEdit::returnPressed, this, &MainWindow::setZTravelRate);
    connect(ui->lineEditZFeed, &QLineEdit::returnPressed, this, &MainWindow::setZFeedRate);

    // GCode
    connect(ui->lineEditGcode, &QLineEdit::returnPressed, this, &MainWindow::sendGCode);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendGCode(){
    this->updateConsole(ui->lineEditGcode->text());
    ui->lineEditGcode->clear();
}

void MainWindow::updateConsole(QString str){
    ui->textBrowserConsole->append(str);
}

void MainWindow::setXStepSize(){
    XStepSize = ui->lineEditXStepSize->text().toDouble();
    this->updateConsole(QString("X Step size set to: %1").arg(XStepSize));
}

void MainWindow::stepXUp(){
    if(XCurrentPos + XStepSize <= XMax){
        XCurrentPos += XStepSize;
    }else{
        XCurrentPos = XMax;
    }
    this->updateConsole(QString("+ Moving X axis to: %1").arg(XCurrentPos));
}

void MainWindow::stepXDown(){
    if(XCurrentPos - XStepSize >= XMin){
        XCurrentPos -= XStepSize;
    }else{
        XCurrentPos = XMin;
    }
    this->updateConsole(QString("- Moving X axis to: %1").arg(XCurrentPos));
}

void MainWindow::zeroXAxis(){
    XCurrentPos = 0;
    this->updateConsole(QString("Set XCurrentPos to: %1").arg(XCurrentPos));
}

void MainWindow::setXTravelRate(){
    XTravelRate = ui->lineEditXTravel->text().toDouble();
    this->updateConsole(QString("Set XTravelRate to: %1").arg(XTravelRate));
}

void MainWindow::setXFeedRate(){
    XFeedRate = ui->lineEditXFeed->text().toDouble();
    this->updateConsole(QString("Set XFeedRate to: %1").arg(XFeedRate));
}

void MainWindow::setXMax(){
    XMax = ui->lineEditXMax->text().toDouble();
    this->updateConsole(QString("Set XMax to: %1").arg(XMax));
}

void MainWindow::setXMin(){
    XMin = ui->lineEditXMin->text().toDouble();
    this->updateConsole(QString("Set XMin to: %1").arg(XMin));
}

void MainWindow::updateXPos(){
    ui->lcdNumberXPos->display(XCurrentPos);
}

void MainWindow::setYStepSize(){
    YStepSize = ui->lineEditYStepSize->text().toDouble();
    this->updateConsole(QString("Y Step size set to: %1").arg(YStepSize));
}

void MainWindow::stepYUp(){
    if(YCurrentPos + YStepSize <= YMax){
        YCurrentPos += YStepSize;
    }else{
        YCurrentPos = YMax;
    }
    this->updateConsole(QString("+ Moving Y axis to: %1").arg(YCurrentPos));
}

void MainWindow::stepYDown(){
    if(YCurrentPos - YStepSize >= YMin){
        YCurrentPos -= YStepSize;
    }else{
        YCurrentPos = YMin;
    }
    this->updateConsole(QString("- Moving Y axis to: %1").arg(YCurrentPos));
}

void MainWindow::zeroYAxis(){
    YCurrentPos = 0;
    this->updateConsole(QString("Set YCurrentPos to: %1").arg(YCurrentPos));
}

void MainWindow::setYTravelRate(){
    YTravelRate = ui->lineEditYTravel->text().toDouble();
    this->updateConsole(QString("Set YTravelRate to: %1").arg(YTravelRate));
}

void MainWindow::setYFeedRate(){
    YFeedRate = ui->lineEditYFeed->text().toDouble();
    this->updateConsole(QString("Set YFeedRate to: %1").arg(YFeedRate));
}

void MainWindow::setYMax(){
    YMax = ui->lineEditYMax->text().toDouble();
    this->updateConsole(QString("Set YMax to: %1").arg(YMax));
}

void MainWindow::setYMin(){
    YMin = ui->lineEditYMin->text().toDouble();
    this->updateConsole(QString("Set YMin to: %1").arg(YMin));
}

void MainWindow::updateYPos(){
    ui->lcdNumberYPos->display(YCurrentPos);
}

void MainWindow::setZStepSize(){
    ZStepSize = ui->lineEditZStepSize->text().toDouble();
    this->updateConsole(QString("Z Step size set to: %1").arg(ZStepSize));
}

void MainWindow::stepZUp(){
    if(ZCurrentPos + ZStepSize <= ZMax){
        ZCurrentPos += ZStepSize;
    }else{
        ZCurrentPos = ZMax;
    }
    this->updateConsole(QString("+ Moving Z axis to: %1").arg(ZCurrentPos));
}

void MainWindow::stepZDown(){
    if(ZCurrentPos - ZStepSize >= ZMin){
        ZCurrentPos -= ZStepSize;
    }else{
        ZCurrentPos = ZMin;
    }
    this->updateConsole(QString("- Moving Z axis to: %1").arg(ZCurrentPos));
}

void MainWindow::zeroZAxis(){
    ZCurrentPos = 0;
    this->updateConsole(QString("Set ZCurrentPos to: %1").arg(ZCurrentPos));
}

void MainWindow::setZTravelRate(){
    ZTravelRate = ui->lineEditZTravel->text().toDouble();
    this->updateConsole(QString("Set ZTravelRate to: %1").arg(ZTravelRate));
}

void MainWindow::setZFeedRate(){
    ZFeedRate = ui->lineEditZFeed->text().toDouble();
    this->updateConsole(QString("Set ZFeedRate to: %1").arg(ZFeedRate));
}

void MainWindow::setZMax(){
    ZMax = ui->lineEditZMax->text().toDouble();
    this->updateConsole(QString("Set ZMax to: %1").arg(ZMax));
}

void MainWindow::setZMin(){
    ZMin = ui->lineEditZMin->text().toDouble();
    this->updateConsole(QString("Set ZMin to: %1").arg(ZMin));
}

void MainWindow::updateZPos(){
    ui->lcdNumberZPos->display(ZCurrentPos);
}


