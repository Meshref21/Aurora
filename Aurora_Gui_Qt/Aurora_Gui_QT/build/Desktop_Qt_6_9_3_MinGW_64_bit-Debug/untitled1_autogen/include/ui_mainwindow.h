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
    QLineEdit *Crop_Width;
    QLineEdit *Crop_Height;
    QPushButton *Crop_Apply_Button;
    QLineEdit *Resize_Width;
    QLineEdit *Resize_Height;
    QPushButton *Resize_Apply_Button;
    QLineEdit *Skew_Angle;
    QPushButton *Skew_Apply_Button;
    QPushButton *Merge_Button;
    QLabel *lbl_Image_Display_2;
    QComboBox *Frames_List_menu;
    QPushButton *Darken_Button;
    QPushButton *Lighten_Button;
    QPushButton *Rotate90_Button;
    QPushButton *Rotate180_Button;
    QPushButton *Rotate270_Button;
    QPushButton *FlipVertical_Button;
    QPushButton *Flip_Horizontal_Button;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1535, 888);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Invert_Push_Button = new QPushButton(centralwidget);
        Invert_Push_Button->setObjectName("Invert_Push_Button");
        Invert_Push_Button->setGeometry(QRect(10, 150, 141, 31));
        Invert_Push_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        LoadImage_Button = new QPushButton(centralwidget);
        LoadImage_Button->setObjectName("LoadImage_Button");
        LoadImage_Button->setGeometry(QRect(630, 10, 151, 51));
        LoadImage_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 45, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        SaveImage_Button = new QPushButton(centralwidget);
        SaveImage_Button->setObjectName("SaveImage_Button");
        SaveImage_Button->setGeometry(QRect(790, 10, 151, 51));
        SaveImage_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 45, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        GrayScale_Button = new QPushButton(centralwidget);
        GrayScale_Button->setObjectName("GrayScale_Button");
        GrayScale_Button->setGeometry(QRect(10, 70, 141, 31));
        GrayScale_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        BlackandWhite_Button = new QPushButton(centralwidget);
        BlackandWhite_Button->setObjectName("BlackandWhite_Button");
        BlackandWhite_Button->setGeometry(QRect(10, 110, 141, 31));
        BlackandWhite_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Flip_Button = new QPushButton(centralwidget);
        Flip_Button->setObjectName("Flip_Button");
        Flip_Button->setGeometry(QRect(10, 190, 141, 31));
        Flip_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Rotate_Button = new QPushButton(centralwidget);
        Rotate_Button->setObjectName("Rotate_Button");
        Rotate_Button->setGeometry(QRect(10, 230, 141, 31));
        Rotate_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        DarkenandLighten_Button = new QPushButton(centralwidget);
        DarkenandLighten_Button->setObjectName("DarkenandLighten_Button");
        DarkenandLighten_Button->setGeometry(QRect(10, 270, 141, 31));
        DarkenandLighten_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Crop_Button = new QPushButton(centralwidget);
        Crop_Button->setObjectName("Crop_Button");
        Crop_Button->setGeometry(QRect(10, 310, 141, 31));
        Crop_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Frame_Button = new QPushButton(centralwidget);
        Frame_Button->setObjectName("Frame_Button");
        Frame_Button->setGeometry(QRect(10, 350, 141, 31));
        Frame_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Edge_Detector_Button = new QPushButton(centralwidget);
        Edge_Detector_Button->setObjectName("Edge_Detector_Button");
        Edge_Detector_Button->setGeometry(QRect(10, 390, 141, 31));
        Edge_Detector_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Resize_Button = new QPushButton(centralwidget);
        Resize_Button->setObjectName("Resize_Button");
        Resize_Button->setGeometry(QRect(10, 430, 141, 31));
        Resize_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Blur_Button = new QPushButton(centralwidget);
        Blur_Button->setObjectName("Blur_Button");
        Blur_Button->setGeometry(QRect(1380, 310, 141, 31));
        Blur_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Natural_Sunlight_Button = new QPushButton(centralwidget);
        Natural_Sunlight_Button->setObjectName("Natural_Sunlight_Button");
        Natural_Sunlight_Button->setGeometry(QRect(1380, 350, 141, 31));
        Natural_Sunlight_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        OilPaint_Button = new QPushButton(centralwidget);
        OilPaint_Button->setObjectName("OilPaint_Button");
        OilPaint_Button->setGeometry(QRect(1380, 390, 141, 31));
        OilPaint_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Oldtv_Button = new QPushButton(centralwidget);
        Oldtv_Button->setObjectName("Oldtv_Button");
        Oldtv_Button->setGeometry(QRect(1380, 70, 141, 31));
        Oldtv_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Purple_Button = new QPushButton(centralwidget);
        Purple_Button->setObjectName("Purple_Button");
        Purple_Button->setGeometry(QRect(1380, 110, 141, 31));
        Purple_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Infrared_Button = new QPushButton(centralwidget);
        Infrared_Button->setObjectName("Infrared_Button");
        Infrared_Button->setGeometry(QRect(1380, 150, 141, 31));
        Infrared_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Skew_Button = new QPushButton(centralwidget);
        Skew_Button->setObjectName("Skew_Button");
        Skew_Button->setGeometry(QRect(1380, 190, 141, 31));
        Skew_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Cold_Button = new QPushButton(centralwidget);
        Cold_Button->setObjectName("Cold_Button");
        Cold_Button->setGeometry(QRect(1380, 230, 141, 31));
        Cold_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        RedDetector_Button = new QPushButton(centralwidget);
        RedDetector_Button->setObjectName("RedDetector_Button");
        RedDetector_Button->setGeometry(QRect(1380, 270, 141, 31));
        RedDetector_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        lbl_Image_Display = new QLabel(centralwidget);
        lbl_Image_Display->setObjectName("lbl_Image_Display");
        lbl_Image_Display->setGeometry(QRect(460, 410, 671, 331));
        lbl_Image_Display->setFrameShape(QFrame::Shape::Box);
        lbl_Image_Display->setScaledContents(true);
        lbl_Image_Display->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Undo_Button = new QPushButton(centralwidget);
        Undo_Button->setObjectName("Undo_Button");
        Undo_Button->setGeometry(QRect(1010, 20, 93, 26));
        Undo_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(150, 200, 255);\n"
"font: 9pt \"Franklin Gothic\";\n"
"color:rgb(0,0,0)"));
        hSlider = new QSlider(centralwidget);
        hSlider->setObjectName("hSlider");
        hSlider->setGeometry(QRect(670, 740, 261, 31));
        hSlider->setStyleSheet(QString::fromUtf8(""));
        hSlider->setMaximum(4);
        hSlider->setOrientation(Qt::Orientation::Horizontal);
        hSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        hSlider->setTickInterval(1);
        Crop_Width = new QLineEdit(centralwidget);
        Crop_Width->setObjectName("Crop_Width");
        Crop_Width->setGeometry(QRect(180, 460, 113, 26));
        Crop_Width->setStyleSheet(QString::fromUtf8("background-color:rgb(200, 255, 255);\n"
"font: 9pt \"Franklin Gothic\";\n"
"color:rgb(0,0,0)"));
        Crop_Height = new QLineEdit(centralwidget);
        Crop_Height->setObjectName("Crop_Height");
        Crop_Height->setGeometry(QRect(180, 490, 113, 26));
        Crop_Height->setStyleSheet(QString::fromUtf8("background-color:rgb(200, 255, 255);\n"
"font: 9pt \"Franklin Gothic\";\n"
"color:rgb(0,0,0)"));
        Crop_Apply_Button = new QPushButton(centralwidget);
        Crop_Apply_Button->setObjectName("Crop_Apply_Button");
        Crop_Apply_Button->setGeometry(QRect(190, 520, 93, 26));
        Crop_Apply_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Resize_Width = new QLineEdit(centralwidget);
        Resize_Width->setObjectName("Resize_Width");
        Resize_Width->setGeometry(QRect(300, 460, 113, 26));
        Resize_Width->setStyleSheet(QString::fromUtf8("background-color:rgb(200, 255, 255);\n"
"font: 9pt \"Franklin Gothic\";\n"
"color:rgb(0,0,0)"));
        Resize_Height = new QLineEdit(centralwidget);
        Resize_Height->setObjectName("Resize_Height");
        Resize_Height->setGeometry(QRect(300, 490, 113, 26));
        Resize_Height->setStyleSheet(QString::fromUtf8("background-color:rgb(200, 255, 255);\n"
"font: 9pt \"Franklin Gothic\";\n"
"color:rgb(0,0,0)"));
        Resize_Apply_Button = new QPushButton(centralwidget);
        Resize_Apply_Button->setObjectName("Resize_Apply_Button");
        Resize_Apply_Button->setGeometry(QRect(310, 520, 93, 26));
        Resize_Apply_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Skew_Angle = new QLineEdit(centralwidget);
        Skew_Angle->setObjectName("Skew_Angle");
        Skew_Angle->setGeometry(QRect(300, 560, 113, 26));
        Skew_Angle->setStyleSheet(QString::fromUtf8("background-color:rgb(200, 255, 255);\n"
"font: 9pt \"Franklin Gothic\";\n"
"color:rgb(0,0,0)"));
        Skew_Apply_Button = new QPushButton(centralwidget);
        Skew_Apply_Button->setObjectName("Skew_Apply_Button");
        Skew_Apply_Button->setGeometry(QRect(310, 590, 93, 26));
        Skew_Apply_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Merge_Button = new QPushButton(centralwidget);
        Merge_Button->setObjectName("Merge_Button");
        Merge_Button->setGeometry(QRect(1380, 430, 141, 31));
        Merge_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(30, 90, 90);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        lbl_Image_Display_2 = new QLabel(centralwidget);
        lbl_Image_Display_2->setObjectName("lbl_Image_Display_2");
        lbl_Image_Display_2->setGeometry(QRect(460, 70, 671, 331));
        lbl_Image_Display_2->setFrameShape(QFrame::Shape::Box);
        lbl_Image_Display_2->setLineWidth(1);
        lbl_Image_Display_2->setMidLineWidth(0);
        Frames_List_menu = new QComboBox(centralwidget);
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->addItem(QString());
        Frames_List_menu->setObjectName("Frames_List_menu");
        Frames_List_menu->setGeometry(QRect(190, 350, 121, 28));
        Frames_List_menu->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Darken_Button = new QPushButton(centralwidget);
        Darken_Button->setObjectName("Darken_Button");
        Darken_Button->setGeometry(QRect(180, 270, 90, 29));
        Darken_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Lighten_Button = new QPushButton(centralwidget);
        Lighten_Button->setObjectName("Lighten_Button");
        Lighten_Button->setGeometry(QRect(290, 270, 91, 29));
        Lighten_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Rotate90_Button = new QPushButton(centralwidget);
        Rotate90_Button->setObjectName("Rotate90_Button");
        Rotate90_Button->setGeometry(QRect(180, 230, 41, 29));
        Rotate90_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Rotate180_Button = new QPushButton(centralwidget);
        Rotate180_Button->setObjectName("Rotate180_Button");
        Rotate180_Button->setGeometry(QRect(240, 230, 41, 29));
        Rotate180_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Rotate270_Button = new QPushButton(centralwidget);
        Rotate270_Button->setObjectName("Rotate270_Button");
        Rotate270_Button->setGeometry(QRect(300, 230, 41, 29));
        Rotate270_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        FlipVertical_Button = new QPushButton(centralwidget);
        FlipVertical_Button->setObjectName("FlipVertical_Button");
        FlipVertical_Button->setGeometry(QRect(170, 190, 93, 26));
        FlipVertical_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        Flip_Horizontal_Button = new QPushButton(centralwidget);
        Flip_Horizontal_Button->setObjectName("Flip_Horizontal_Button");
        Flip_Horizontal_Button->setGeometry(QRect(280, 190, 93, 26));
        Flip_Horizontal_Button->setStyleSheet(QString::fromUtf8("background-color:rgb(15, 30, 60);\n"
"font: 9pt \"Franklin Gothic\";\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(1400, 670, 121, 91));
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/GPC/Downloads/aurora_logo_nobg.png")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1535, 25));
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
        Crop_Width->setText(QString());
        Crop_Height->setText(QString());
        Crop_Apply_Button->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        Resize_Width->setText(QString());
        Resize_Height->setText(QString());
        Resize_Apply_Button->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        Skew_Angle->setText(QString());
        Skew_Apply_Button->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        Merge_Button->setText(QCoreApplication::translate("MainWindow", "Merge", nullptr));
        lbl_Image_Display_2->setText(QString());
        Frames_List_menu->setItemText(0, QCoreApplication::translate("MainWindow", "Choose", nullptr));
        Frames_List_menu->setItemText(1, QCoreApplication::translate("MainWindow", "White Frame", nullptr));
        Frames_List_menu->setItemText(2, QCoreApplication::translate("MainWindow", "Black Frame", nullptr));
        Frames_List_menu->setItemText(3, QCoreApplication::translate("MainWindow", "Yellowish Gray", nullptr));
        Frames_List_menu->setItemText(4, QCoreApplication::translate("MainWindow", "Claret Frame", nullptr));
        Frames_List_menu->setItemText(5, QCoreApplication::translate("MainWindow", "Pointy Yellow", nullptr));

        Darken_Button->setText(QCoreApplication::translate("MainWindow", "Darken", nullptr));
        Lighten_Button->setText(QCoreApplication::translate("MainWindow", "Lighten", nullptr));
        Rotate90_Button->setText(QCoreApplication::translate("MainWindow", "90", nullptr));
        Rotate180_Button->setText(QCoreApplication::translate("MainWindow", "180", nullptr));
        Rotate270_Button->setText(QCoreApplication::translate("MainWindow", "270", nullptr));
        FlipVertical_Button->setText(QCoreApplication::translate("MainWindow", "Vertical", nullptr));
        Flip_Horizontal_Button->setText(QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
