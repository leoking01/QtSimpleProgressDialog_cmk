#ifndef QTCUSTOMPROGRESSDIALOG_H
#define QTCUSTOMPROGRESSDIALOG_H

#include <QProgressDialog>

class QtCustomProgressDialog : public QProgressDialog
{
    Q_OBJECT
public:
    explicit QtCustomProgressDialog(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // QTCUSTOMPROGRESSDIALOG_H
