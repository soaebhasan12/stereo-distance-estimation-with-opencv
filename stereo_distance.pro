##################################################
##################################################
######### Project created by QtCreator ###########
##################################################
##################################################

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stereo_distance
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_calib3d -lopencv_features2d

SOURCES += src/main.cpp \
           src/main_window.cpp

HEADERS  += src/main_window.h \
            src/project_utils.h \
            src/stereo_calibration.h \
            src/stereo_processing.h

FORMS    += forms/main_window.ui
