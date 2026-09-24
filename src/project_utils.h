#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QThread>

// Get current date format is YYYY_MM_DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    // date/time format
    strftime(buf, sizeof(buf), "%Y_%m_%d.%X", &tstruct);

    return buf;
}

// Remove all contents from
// ListOfPics.txt file
void clearListOfPics(){
    std::ofstream toFileTXT("/home/pi/OpenCV_Project/ListOfPics.txt", std::ofstream::out | std::ofstream::trunc);
}

static bool clearFilesInDirectory(const QString& path){
    QDir directory(path);
    if (!directory.exists()){
        QMessageBox::warning(0, QObject::tr("Cleanup failed"),
                             QObject::tr("Folder does not exist: %1").arg(path));
        return false;
    }

    const QFileInfoList entries = directory.entryInfoList(
                QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
    foreach (const QFileInfo& entry, entries){
        if (entry.isDir()){
            QMessageBox::warning(0, QObject::tr("Cleanup stopped"),
                                 QObject::tr("Subfolders are not removed: %1")
                                 .arg(entry.fileName()));
            return false;
        }
    }

    foreach (const QFileInfo& entry, entries){
        if (!QFile::remove(entry.absoluteFilePath())){
            QMessageBox::warning(0, QObject::tr("Cleanup failed"),
                                 QObject::tr("Could not remove file: %1")
                                 .arg(entry.fileName()));
            return false;
        }
    }
    return true;
}

// Remove the current calibration
// files
void clearCalibrationFiles(){
    clearFilesInDirectory("/home/pi/OpenCV_Project/CameraCalabration");
}

//Removes all the pictures
// that were taken
void clearAllPicsTaken(){
    clearFilesInDirectory("/home/pi/OpenCV_Project/Images");
}

//Removes all the videos
// that were taken
void clearAllVids(){
    clearFilesInDirectory("/home/pi/OpenCV_Project/Videos");
}

// Remove all the images
// with errors from the listOfPics
void errImgRemove(){
    system("exec echo HiThere");
}



void errorLog(std::string msg){
    // write to TXT file
    // this will store all
    // the images that could
    // not be calibrated
    std::ofstream toFileTXTError("/home/pi/OpenCV_Project/CalibrationPicsErrors.txt", std::ios_base::app);
    toFileTXTError << msg;
    toFileTXTError << "\n";

}

// Sleep Function (seconds to sleep)
class Sleeper : public QThread{
public:
    static void sleep( unsigned long secs){QThread::sleep(secs);}
};

#endif // PROJECT_UTILS_H
