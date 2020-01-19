#include "qtsimpleprogressdialog.h"
#include "qtcustomprogressdialog.h"

#include <QProgressDialog>
#include <QThread>

class QtSimpleProgressDialogPrivate
{
public:
    QtSimpleProgressDialogPrivate(QtSimpleProgressDialog *p)
        :q_ptr(p)
        ,m_progress(nullptr)
    {
    }

    ~QtSimpleProgressDialogPrivate()
    {
        cleanUp();
    }

private:
    void exec(QString message, Func func, bool canCancel)
    {
        m_progress->setLabelText(message);
        if(!canCancel)
        {
            m_progress->setCancelButton(nullptr);
        }

        QThread *thread = QThread::create(func);
        QObject::connect(m_progress, &QtCustomProgressDialog::canceled, thread, &QThread::requestInterruption);
        QObject::connect(thread, &QThread::finished, m_progress, &QtCustomProgressDialog::close);

        thread->start();
        m_progress->exec();
        thread->wait();
        thread->deleteLater();
        cleanUp();
    }

    void init()
    {
        cleanUp();

        auto q = q_func();
        m_progress = new QtCustomProgressDialog(qobject_cast<QWidget*>(q->parent()));

        QObject::connect(q, &QtSimpleProgressDialog::setProgressRange, m_progress, &QtCustomProgressDialog::setRange);
        QObject::connect(q, &QtSimpleProgressDialog::setProgressValue, m_progress, &QtCustomProgressDialog::setValue);
        QObject::connect(q, &QtSimpleProgressDialog::setProgressMessage, m_progress, &QtCustomProgressDialog::setLabelText);
    }

    void cleanUp()
    {
        auto q = q_func();
        if(nullptr != m_progress)
        {
            q->disconnect(m_progress);

            m_progress->close();
            m_progress->disconnect();
            m_progress->deleteLater();
            m_progress = nullptr;
        }
    }

private:
    QtSimpleProgressDialog * const q_ptr;
    Q_DECLARE_PUBLIC(QtSimpleProgressDialog)
    QtCustomProgressDialog *m_progress;
};

QtSimpleProgressDialog::QtSimpleProgressDialog(QWidget *parent)
    :QObject (parent)
    ,dd_ptr(new QtSimpleProgressDialogPrivate(this))
{
}

void QtSimpleProgressDialog::exec(QString message, Func func, bool canCancel)
{
    auto d = d_func();
    d->init();
    d->exec(message, func, canCancel);
}

void QtSimpleProgressDialog::execSimple(QString message, Func func, QWidget *parent, bool canCancel)
{
    auto progress = new QtSimpleProgressDialog(parent);
    auto d = progress->d_func();
    d->init();
    progress->setProgressRange(0, 0);
    d->exec(message, func, canCancel);
    progress->deleteLater();
}
