#ifndef QTSIMPLEPROGRESSDIALOG_H
#define QTSIMPLEPROGRESSDIALOG_H

#include "qtsimpleprogressdialog_global.h"
#include <QObject>
#include <functional>

typedef std::function<void()> Func;

class QtSimpleProgressDialogPrivate;
class QTSIMPLEPROGRESSDIALOGSHARED_EXPORT QtSimpleProgressDialog:public QObject
{
    Q_OBJECT
public:
    QtSimpleProgressDialog(QWidget *parent=nullptr);
public:
    void exec(QString message, Func func, bool canCancel);

signals:
    void setProgressRange(int min, int max);
    void setProgressMessage(const QString &msg);
    void setProgressValue(int value);

public:
    ///
    /// \brief execSimple   创建来回滚动的进度条
    /// \param message      提示信息
    /// \param func         耗时操作
    /// \param parent       父窗口
    /// \param canCancel    是否可以取消
    ///
    static void execSimple(QString message, Func func, QWidget *parent=nullptr, bool canCancel=true);

private:
    QtSimpleProgressDialogPrivate * const dd_ptr;
    Q_DECLARE_PRIVATE_D(dd_ptr, QtSimpleProgressDialog)
};

#endif // QTSIMPLEPROGRESSDIALOG_H
