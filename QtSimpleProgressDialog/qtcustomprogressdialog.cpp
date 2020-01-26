#include "qtcustomprogressdialog.h"

QtCustomProgressDialog::QtCustomProgressDialog(QWidget *parent) : QProgressDialog(parent)
{
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
}
