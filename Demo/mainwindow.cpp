#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qtsimpleprogressdialog.h"

#include <QThread>

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

void MainWindow::on_pushButton_clicked()
{
    QtSimpleProgressDialog::execSimple(tr("来回滚动进度条"), [=]{
        QThread::sleep(2);
    }, this, false);
}

void MainWindow::on_pushButton_2_clicked()
{
    auto progress = new QtSimpleProgressDialog(this);
    progress->exec(tr("普通进度条"), [=]{
        emit progress->setProgressRange(0, 100);
        for (int i=0;i<100;++i) {
            if(QThread::currentThread()->isInterruptionRequested())
                break;
            emit progress->setProgressValue(i+1);
            QThread::msleep(20);
        }
    }, false);
}

void MainWindow::on_pushButton_3_clicked()
{
    auto progress = new QtSimpleProgressDialog(this);
    progress->exec(tr("普通进度条1"), [=]{
        emit progress->setProgressRange(0, 100);
        for (int i=0;i<100;++i) {
            if(QThread::currentThread()->isInterruptionRequested())
            {
                break;
            }
            emit progress->setProgressValue(i+1);
            QThread::msleep(20);
        }
    }, false);

    progress->exec(tr("普通进度条2"), [=]{
        emit progress->setProgressRange(0, 100);
        for (int i=0;i<100;++i) {
            if(QThread::currentThread()->isInterruptionRequested())
            {
                break;
            }
            emit progress->setProgressValue(i+1);
            QThread::msleep(20);
        }
    }, false);
}

void MainWindow::on_pushButton_4_clicked()
{
    auto progress = new QtSimpleProgressDialog(this);
    progress->exec(tr("普通进度条"), [=]{
        emit progress->setProgressRange(0, 100);
        for (int i=0;i<100;++i) {
            if(QThread::currentThread()->isInterruptionRequested())
                break;
            emit progress->setProgressValue(i+1);
            QThread::msleep(20);
        }
    }, true);
}
