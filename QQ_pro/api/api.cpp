#include "api.h"
#include "quiwidget.h"

API::API(QObject *parent) : QObject(parent)
{

}


QString API::getFileName(const QString &filter, const QString &defaultDir, const QString &fileName)
{
    QString file;
    QFileDialog dialog;
    dialog.setFixedSize(900, 600);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setWindowTitle("保存文件");
    dialog.setLabelText(QFileDialog::Accept, "保存(&S)");
    dialog.setLabelText(QFileDialog::Reject, "取消(&C)");
    dialog.selectFile(fileName);
    dialog.setNameFilter(filter);
    dialog.setDirectory(defaultDir);

    if (dialog.exec() == 1) {
        file = dialog.selectedFiles().value(0);
        file = QFileInfo(file).suffix().isEmpty() ? "" : file;
    }

    return file;
}

QString API::getDefaultDir()
{
    return QUIHelper::appPath();
}
