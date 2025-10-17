#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUndoCommand>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Image;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Invert_Push_Button_clicked();

    void on_LoadImage_Button_clicked();

    void on_SaveImage_Button_clicked();

    void on_GrayScale_Button_clicked();

    void on_BlackandWhite_Button_clicked();

    void on_Flip_Button_clicked();

    void on_Rotate_Button_clicked();

    void on_DarkenandLighten_Button_clicked();

    void on_Crop_Button_clicked();

    void on_Frame_Button_clicked();

    void on_Edge_Detector_Button_clicked();

    void on_Resize_Button_clicked();

    void on_Blur_Button_clicked();

    void on_Natural_Sunlight_Button_clicked();

    void on_OilPaint_Button_clicked();

    void on_Oldtv_Button_clicked();

    void on_Purple_Button_clicked();

    void on_Infrared_Button_clicked();

    void on_Skew_Button_clicked();

    void on_Cold_Button_clicked();

    void on_RedDetector_Button_clicked();

    void on_Undo_Button_clicked();

    void on_Merge_Button_clicked();

private:
    Ui::MainWindow *ui;
    void UpdateDisplayedImage();
    void Original_Picture();
    void HideAllButtons();
};
#endif // MAINWINDOW_H
