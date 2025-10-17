/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Invert_Push_Button;
    QPushButton *LoadImage_Button;
    QPushButton *SaveImage_Button;
    QPushButton *GrayScale_Button;
    QPushButton *BlackandWhite_Button;
    QPushButton *Flip_Button;
    QPushButton *Rotate_Button;
    QPushButton *DarkenandLighten_Button;
    QPushButton *Crop_Button;
    QPushButton *Frame_Button;
    QPushButton *Edge_Detector_Button;
    QPushButton *Resize_Button;
    QPushButton *Blur_Button;
    QPushButton *Natural_Sunlight_Button;
    QPushButton *OilPaint_Button;
    QPushButton *Oldtv_Button;
    QPushButton *Purple_Button;
    QPushButton *Infrared_Button;
    QPushButton *Skew_Button;
    QPushButton *Cold_Button;
    QPushButton *RedDetector_Button;
    QLabel *lbl_Image_Display;
    QPushButton *Undo_Button;
    QSlider *hSlider;
    QPushButton *FlipVertical_Button;
    QPushButton *Flip_Horizontal_Button;
    QPushButton *Rotate90_Button;
    QPushButton *Rotate180_Button;
    QPushButton *Rotate270_Button;
    QPushButton *Darken_Button;
    QPushButton *Lighten_Button;
    QComboBox *Frames_List_menu;
    QLineEdit *Crop_Width;
    QLineEdit *Crop_Height;
    QPushButton *Crop_Apply_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Invert_Push_Button = new QPushButton(centralwidget);
        Invert_Push_Button->setObjectName("Invert_Push_Button");
        Invert_Push_Button->setGeometry(QRect(70, 150, 141, 31));
        Invert_Push_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        LoadImage_Button = new QPushButton(centralwidget);
        LoadImage_Button->setObjectName("LoadImage_Button");
        LoadImage_Button->setGeometry(QRect(490, 10, 151, 51));
        LoadImage_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        SaveImage_Button = new QPushButton(centralwidget);
        SaveImage_Button->setObjectName("SaveImage_Button");
        SaveImage_Button->setGeometry(QRect(650, 10, 151, 51));
        SaveImage_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        GrayScale_Button = new QPushButton(centralwidget);
        GrayScale_Button->setObjectName("GrayScale_Button");
        GrayScale_Button->setGeometry(QRect(70, 70, 141, 31));
        GrayScale_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        BlackandWhite_Button = new QPushButton(centralwidget);
        BlackandWhite_Button->setObjectName("BlackandWhite_Button");
        BlackandWhite_Button->setGeometry(QRect(70, 110, 141, 31));
        BlackandWhite_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Flip_Button = new QPushButton(centralwidget);
        Flip_Button->setObjectName("Flip_Button");
        Flip_Button->setGeometry(QRect(70, 190, 141, 31));
        Flip_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Rotate_Button = new QPushButton(centralwidget);
        Rotate_Button->setObjectName("Rotate_Button");
        Rotate_Button->setGeometry(QRect(70, 230, 141, 31));
        Rotate_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        DarkenandLighten_Button = new QPushButton(centralwidget);
        DarkenandLighten_Button->setObjectName("DarkenandLighten_Button");
        DarkenandLighten_Button->setGeometry(QRect(70, 270, 141, 31));
        DarkenandLighten_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Crop_Button = new QPushButton(centralwidget);
        Crop_Button->setObjectName("Crop_Button");
        Crop_Button->setGeometry(QRect(70, 310, 141, 31));
        Crop_Button->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        Crop_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Frame_Button = new QPushButton(centralwidget);
        Frame_Button->setObjectName("Frame_Button");
        Frame_Button->setGeometry(QRect(70, 350, 141, 31));
        Frame_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Edge_Detector_Button = new QPushButton(centralwidget);
        Edge_Detector_Button->setObjectName("Edge_Detector_Button");
        Edge_Detector_Button->setGeometry(QRect(70, 390, 141, 31));
        Edge_Detector_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Resize_Button = new QPushButton(centralwidget);
        Resize_Button->setObjectName("Resize_Button");
        Resize_Button->setGeometry(QRect(70, 430, 141, 31));
        Resize_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Blur_Button = new QPushButton(centralwidget);
        Blur_Button->setObjectName("Blur_Button");
        Blur_Button->setGeometry(QRect(1080, 310, 141, 31));
        Blur_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Natural_Sunlight_Button = new QPushButton(centralwidget);
        Natural_Sunlight_Button->setObjectName("Natural_Sunlight_Button");
        Natural_Sunlight_Button->setGeometry(QRect(1080, 350, 141, 31));
        Natural_Sunlight_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        OilPaint_Button = new QPushButton(centralwidget);
        OilPaint_Button->setObjectName("OilPaint_Button");
        OilPaint_Button->setGeometry(QRect(1080, 390, 141, 31));
        OilPaint_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Oldtv_Button = new QPushButton(centralwidget);
        Oldtv_Button->setObjectName("Oldtv_Button");
        Oldtv_Button->setGeometry(QRect(1080, 70, 141, 31));
        Oldtv_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Purple_Button = new QPushButton(centralwidget);
        Purple_Button->setObjectName("Purple_Button");
        Purple_Button->setGeometry(QRect(1080, 110, 141, 31));
        Purple_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Infrared_Button = new QPushButton(centralwidget);
        Infrared_Button->setObjectName("Infrared_Button");
        Infrared_Button->setGeometry(QRect(1080, 150, 141, 31));
        Infrared_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Skew_Button = new QPushButton(centralwidget);
        Skew_Button->setObjectName("Skew_Button");
        Skew_Button->setGeometry(QRect(1080, 190, 141, 31));
        Skew_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Cold_Button = new QPushButton(centralwidget);
        Cold_Button->setObjectName("Cold_Button");
        Cold_Button->setGeometry(QRect(1080, 230, 141, 31));
        Cold_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        RedDetector_Button = new QPushButton(centralwidget);
        RedDetector_Button->setObjectName("RedDetector_Button");
        RedDetector_Button->setGeometry(QRect(1080, 270, 141, 31));
        RedDetector_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        lbl_Image_Display = new QLabel(centralwidget);
        lbl_Image_Display->setObjectName("lbl_Image_Display");
        lbl_Image_Display->setGeometry(QRect(240, 70, 811, 551));
        lbl_Image_Display->setFrameShape(QFrame::Shape::NoFrame);
        lbl_Image_Display->setScaledContents(true);
        lbl_Image_Display->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Undo_Button = new QPushButton(centralwidget);
        Undo_Button->setObjectName("Undo_Button");
        Undo_Button->setGeometry(QRect(870, 20, 93, 26));
        Undo_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        hSlider = new QSlider(centralwidget);
        hSlider->setObjectName("hSlider");
        hSlider->setGeometry(QRect(50, 590, 191, 31));
        hSlider->setMaximum(4);
        hSlider->setOrientation(Qt::Orientation::Horizontal);
        hSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        hSlider->setTickInterval(1);
        FlipVertical_Button = new QPushButton(centralwidget);
        FlipVertical_Button->setObjectName("FlipVertical_Button");
        FlipVertical_Button->setGeometry(QRect(30, 550, 93, 26));
        FlipVertical_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Flip_Horizontal_Button = new QPushButton(centralwidget);
        Flip_Horizontal_Button->setObjectName("Flip_Horizontal_Button");
        Flip_Horizontal_Button->setGeometry(QRect(140, 550, 93, 26));
        Flip_Horizontal_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Rotate90_Button = new QPushButton(centralwidget);
        Rotate90_Button->setObjectName("Rotate90_Button");
        Rotate90_Button->setGeometry(QRect(30, 510, 40, 29));
        Rotate90_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Rotate180_Button = new QPushButton(centralwidget);
        Rotate180_Button->setObjectName("Rotate180_Button");
        Rotate180_Button->setGeometry(QRect(80, 510, 40, 29));
        Rotate180_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Rotate270_Button = new QPushButton(centralwidget);
        Rotate270_Button->setObjectName("Rotate270_Button");
        Rotate270_Button->setGeometry(QRect(130, 510, 40, 29));
        Rotate270_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Darken_Button = new QPushButton(centralwidget);
        Darken_Button->setObjectName("Darken_Button");
        Darken_Button->setGeometry(QRect(20, 620, 90, 29));
        Darken_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Lighten_Button = new QPushButton(centralwidget);
        Lighten_Button->setObjectName("Lighten_Button");
        Lighten_Button->setGeometry(QRect(120, 620, 90, 29));
        Lighten_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Frames_List_menu = new QComboBox(centralwidget);
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->setObjectName("Frames_List_menu");
        Frames_List_menu->setGeometry(QRect(30, 470, 121, 28));
        Frames_List_menu->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        Crop_Width = new QLineEdit(centralwidget);
        Crop_Width->setObjectName("Crop_Width");
        Crop_Width->setGeometry(QRect(260, 560, 113, 26));
        Crop_Height = new QLineEdit(centralwidget);
        Crop_Height->setObjectName("Crop_Height");
        Crop_Height->setGeometry(QRect(260, 590, 113, 26));
        Crop_Apply_Button = new QPushButton(centralwidget);
        Crop_Apply_Button->setObjectName("Crop_Apply_Button");
        Crop_Apply_Button->setGeometry(QRect(270, 630, 93, 26));
        Crop_Apply_Button->setStyleSheet(QString::fromUtf8(" background-color:rgb(3, 0, 29)"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Invert_Push_Button->setText(QCoreApplication::translate("MainWindow", "Invert Colors", nullptr));
        LoadImage_Button->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        SaveImage_Button->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        GrayScale_Button->setText(QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        BlackandWhite_Button->setText(QCoreApplication::translate("MainWindow", "Black and White", nullptr));
        Flip_Button->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        Rotate_Button->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        DarkenandLighten_Button->setText(QCoreApplication::translate("MainWindow", "Darken and Lighten", nullptr));
        Crop_Button->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        Frame_Button->setText(QCoreApplication::translate("MainWindow", "Frame", nullptr));
        Edge_Detector_Button->setText(QCoreApplication::translate("MainWindow", "Edge Detector", nullptr));
        Resize_Button->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        Blur_Button->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        Natural_Sunlight_Button->setText(QCoreApplication::translate("MainWindow", "Natural Sunlight", nullptr));
        OilPaint_Button->setText(QCoreApplication::translate("MainWindow", "Oil Paint", nullptr));
        Oldtv_Button->setText(QCoreApplication::translate("MainWindow", "Old Television", nullptr));
        Purple_Button->setText(QCoreApplication::translate("MainWindow", "Purple ", nullptr));
        Infrared_Button->setText(QCoreApplication::translate("MainWindow", "Infrared", nullptr));
        Skew_Button->setText(QCoreApplication::translate("MainWindow", "Skew", nullptr));
        Cold_Button->setText(QCoreApplication::translate("MainWindow", "Cold", nullptr));
        RedDetector_Button->setText(QCoreApplication::translate("MainWindow", "Red Detector", nullptr));
        lbl_Image_Display->setText(QString());
        Undo_Button->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        FlipVertical_Button->setText(QCoreApplication::translate("MainWindow", "Vertical", nullptr));
        Flip_Horizontal_Button->setText(QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        Rotate90_Button->setText(QCoreApplication::translate("MainWindow", "90", nullptr));
        Rotate180_Button->setText(QCoreApplication::translate("MainWindow", "180", nullptr));
        Rotate270_Button->setText(QCoreApplication::translate("MainWindow", "270", nullptr));
        Darken_Button->setText(QCoreApplication::translate("MainWindow", "Darken", nullptr));
        Lighten_Button->setText(QCoreApplication::translate("MainWindow", "Lighten", nullptr));
        Frames_List_menu->setItemText(0, QCoreApplication::translate("MainWindow", "White Frame", nullptr));
        Frames_List_menu->setItemText(1, QCoreApplication::translate("MainWindow", "Black Frame", nullptr));
        Frames_List_menu->setItemText(2, QCoreApplication::translate("MainWindow", "Yellowish Gray", nullptr));
        Frames_List_menu->setItemText(3, QCoreApplication::translate("MainWindow", "Claret Frame", nullptr));
        Frames_List_menu->setItemText(4, QCoreApplication::translate("MainWindow", "Pointy Yellow", nullptr));

        Crop_Width->setText(QString());
        Crop_Height->setText(QString());
        Crop_Apply_Button->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
