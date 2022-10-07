#include "copyprint.h"
#include "quiwidget.h"


QScopedPointer<copyPrint> copyPrint::self;
copyPrint *copyPrint::Instance()
{
    if (self.isNull()) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (self.isNull()) {
            self.reset(new copyPrint);
        }
    }

    return self.data();
}
//构造函数
copyPrint::copyPrint(QObject *parent) : QObject(parent)
{

}
//析构函数
copyPrint::~copyPrint()
{

}

void copyPrint::copyfiletofile(const QString filePath , const QString toFileName)
{
    quint64 size = getDirSize(filePath);
    emit copysize(size);

     QDir tmpDir(filePath);
    /*获取文件列表  统计文件大小*/
    int index = 0;
    foreach(QFileInfo fileInfo, tmpDir.entryInfoList(QDir::Files))
    {

        QString str = QString("%1/%2").arg(fileInfo.path()).arg(fileInfo.fileName());
       // qDebug()<<str;
        QString str2 = QString("%1/%2").arg(toFileName).arg(fileInfo.fileName());
        index++;
        emit copystatus(index, fileInfo.fileName());
        bool success = false;

        success = QUIHelper::copyFile(str,str2);
        if(!success){
            emit copyerror(0);
            return;
        }

    }

//    QFile file(XYZC9000A_old_PATH);
//    updatesuccess = file.copy(XYZC9000A_new_PATH,XYZC9000A_path_PATH);
//    if(updatesuccess){
//        file.remove();
//        updatesuccess = file.rename(XYZC9000A_path_PATH,XYZC9000A_old_PATH);
//    }
}
/******
* Note:传入的文件路径格式如: "D:/SoftPage/SVN"
* "D:\SoftPage\SVN" 无效  需转义为"D:\\SoftPage\\SVN"可正常使用
****/
quint64 copyPrint::getDirSize(const QString filePath)
{
    //qDebug()<<filePath;
    QDir tmpDir(filePath);
    quint64 size = 0;
    int index = 0;
    /*获取文件列表  统计文件大小*/
    foreach(QFileInfo fileInfo, tmpDir.entryInfoList(QDir::Files))
    {
        size += fileInfo.size();
        index ++;
    }
    emit copysizefile(0,index);
    /*获取文件夹  并且过滤掉.和..文件夹 统计各个文件夹的文件大小 */
    foreach(QString subDir, tmpDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        size += getDirSize(filePath + QDir::separator() + subDir); //递归进行  统计所有子目录
    }

    return size;
}
/**
 * @brief FuncModuleWin::copyFile
 * @param fromFIleName 优盘里面的文件
 * @param toFileName 拷贝到/bin里面的启动文件
 * @return
 */
bool copyPrint::copyFile(const QString &fromFIleName, const QString &toFileName)
{
    char* byteTemp = new char[4096];//字节数组
    int fileSize = 0;
    int totalCopySize = 0;
    QFile tofile;
    //emit copysizefile(fileSize);
    tofile.setFileName(toFileName);
    QDataStream out(&tofile);
    out.setVersion(QDataStream::Qt_4_8);
    QFile fromfile;
    fromfile.setFileName(fromFIleName);
    if(!fromfile.open(QIODevice::ReadOnly)){
        qDebug() << "open fromfile failed！！！";
        return false;
    }
    fileSize = fromfile.size();
    QDataStream in(&fromfile);

    in.setVersion(QDataStream::Qt_4_8);
    //ui->progressBar_copy->setRange(0, fileSize);
    emit copysizefile(0,fileSize);
    while(!in.atEnd())
    {
        int readSize = 0;
        //读入字节数组,返回读取的字节数量，如果小于4096，则到了文件尾
        readSize = in.readRawData(byteTemp, 4096);
        out.writeRawData(byteTemp, readSize);
        totalCopySize += readSize;
        //ui->progressBar_copy->setValue(totalCopySize);
        emit copysizefile(totalCopySize,fileSize);
    }
    if(totalCopySize == fileSize){
        tofile.setPermissions(QFile::ExeUser);
        return true;
    }
    else
        return false;
}

