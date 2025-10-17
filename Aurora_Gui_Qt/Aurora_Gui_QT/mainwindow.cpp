#include "mainwindow.h"

#include <string>

#include <iostream>

#include "./ui_mainwindow.h"

#include "Image_Class.h"

#include <QFileDialog>

#include <QPixmap>

#include <QImage>

#include <QDebug>

#include <QObject>
#include <QScreen>
#include <stack>
#include <QMessageBox>

using namespace std;



Image Photo;
Image OriginalPhoto;

QString File_Name;

stack<Image> Images_Stack;

//=================== Adminstrative Functions



void Undo()

{

    if(Images_Stack.size() == 1)
    {
        return;
    }

    if(!Images_Stack.empty())
    {

        Images_Stack.pop();

    }

}



bool Valid_Extension(string& File_Name)

{

    string Valid_Extensions[4] = {"jpg" , "jpeg" , "bmp" , "png"};

    int Dot_Position = File_Name.find('.');



    if (Dot_Position == -1)

    {

        return false;

    }



    string Given_Extension = File_Name.substr(Dot_Position + 1);



    string Lower_Given_Extension;

    for (int i = 0 ; i < Given_Extension.size() ; ++i)

    {

        Lower_Given_Extension += char(tolower(Given_Extension[i]));

    }



    for (int i = 0 ; i < 4 ; ++i)

    {

        if (Lower_Given_Extension == Valid_Extensions[i])

        {

            return true;

        }

    }

    return false;

}



bool is_Valid_Pixel(Image& Picture , int i , int j)

{

    return i < Picture.width && i >= 0 && j < Picture.height && j >= 0;

}




//================================= FILTERS ========================================

void Invert_Colors(Image& Picture)

{

    // Invert Each Pixel's Color In Their Own Channel

    for (int i = 0 ; i < Picture.width ; ++i)

    {

        for (int j = 0 ; j < Picture.height ; ++j)

        {

            for (int k = 0 ; k < Picture.channels ; ++k)

            {

                unsigned int value = Picture.getPixel(i , j , k);

                value = 255 - value;



                if (value > 255)

                value = 255;



                Picture(i , j , k) = value;

            }

        }

    }

}



void Rotate_Image(Image& Picture , int option)

{

    // ROTATE IMAGE 90 Degree

    if (option == 1)

    {

        Image Canva(Picture.height , Picture.width);

        for (int i = 0; i < Canva.width; ++i)

        {

            for (int j = 0; j < Canva.height; ++j)

            {

                for (int k = 0; k < Picture.channels; ++k)

                {

                    Canva(i, j, k) = Picture(j, Canva.width - 1 - i, k);

                }

            }

        }

        swap(Picture.width , Picture.height);

        for (int i = 0 ; i < Picture.width ; ++i)

        {

            for (int j = 0 ; j < Picture.height ; ++j)

            {

                for (int k = 0 ; k < Picture.channels ; ++k)

                {

                    Picture(i , j , k) = Canva(i , j , k);

                }

            }

        }

    }



    else if (option == 2)

    {

        Image Canva(Picture.width , Picture.height);

        // ROTATE 180 DEGREE

        for (int i = 0; i < Picture.width; ++i)

        {

            for (int j = 0; j < Picture.height; ++j)

            {

                for (int k = 0; k < Picture.channels; ++k)

                {

                    Canva(i, j, k) = Picture(Picture.width - i, Picture.height - j, k);

                }

            }

        }



        for (int i = 0 ; i < Picture.width ; ++i)

        {

            for (int j = 0 ; j < Picture.height ; ++j)

            {

                for (int k = 0 ; k < Picture.channels ; ++k)

                {

                    Picture(i , j , k) = Canva(i , j , k);

                }

            }

        }

    }



    else if (option == 3)

    {

        Image Canva(Picture.height , Picture.width);

        // ROTATE IMAGE 270 DEGREE

        for (int i = 0; i < Canva.width; ++i)

        {

            for (int j = 0; j < Canva.height; ++j)

            {

                for (int k = 0; k < Canva.channels; ++k)

                {

                    Canva(i, j, k) = Picture(Canva.height - 1 - j, i, k);

                }

            }

        }

        swap(Picture.width , Picture.height);

        for (int i = 0 ; i < Picture.width ; ++i)

        {

            for (int j = 0 ; j < Picture.height ; ++j)

            {

                for (int k = 0 ; k < Picture.channels ; ++k)

                {

                    Picture(i , j , k) = Canva(i , j , k);

                }

            }

        }

    }

}



void Adding_Frame(Image& Picture , int option)

{

    float ratio = 0.03;

    Image Canva(Picture.width + Picture.width * ratio , Picture.height + Picture.height * ratio);



    int Red = 0 , Green = 0 , Blue = 0;



    if (option == 1)

    {
        Red = 255 , Green = 255 , Blue = 255;
    }
    else if(option == 2)
    {
        Red = 0 , Green = 0 , Blue = 0;
    }
    else if(option == 3)
    {
        Red = 244 , Green = 210 , Blue = 108;
    }
    else if(option == 4)
    {
        Red = 129 , Green = 19 , Blue = 49;
    }
    else if (option == 5)
    {

        Red = 255 , Green = 82 , Blue = 82;



        // Fill The Empty Canva With White Color

        for (int i = 0 ; i < Canva.width ; ++i)

        {

            for (int j = 0 ; j < Canva.height ; ++j)

            {

                Canva(i , j , 0) = Red;

                Canva(i , j , 1) = Green;

                Canva(i , j , 2) = Blue;

            }

        }



        Red = 255 , Green = 255 , Blue = 255;



        for (int i = 0 ; i < Canva.width ; i += 5)

        {

            for (int j = 0 ; j < Canva.height ; j += 5)

            {

                Canva(i , j , 0) = Red;

                Canva(i , j , 1) = Green;

                Canva(i , j , 2) = Blue;

            }

        }



        Red = 255 , Green = 215 , Blue = 0;



        for (int i = 0 ; i < Canva.width ; i += 2)

        {

            for (int j = 0 ; j < Canva.height ; j += 2)

            {

                Canva(i , j , 0) = Red;

                Canva(i , j , 1) = Green;

                Canva(i , j , 2) = Blue;

            }

        }
        goto Jump_Label;
    }



    // Fill The Empty Canva With White Color

    for (int i = 0 ; i < Canva.width ; ++i)

    {

        for (int j = 0 ; j < Canva.height ; ++j)

        {

            Canva(i , j , 0) = Red;

            Canva(i , j , 1) = Green;

            Canva(i , j , 2) = Blue;

        }

    }


Jump_Label:
    // Copy Our Photo's Pixels Inside The Solid Color Canva

    for (int i = ratio * Picture.width ; i < Picture.width ; ++i)

    {

        for (int j = ratio * Picture.height ; j < Picture.height ; ++j)

        {

            for (int k = 0 ; k < Picture.channels ; ++k)

            {

                Canva(i , j , k) = Picture(i , j , k);

            }

        }

    }

    Picture = Canva;

}



void Blur(Image& Picture, int R)

{

    Image Canva(Picture.width , Picture.height);



    int channels = 2;

    int condition = 3;

    while (condition--)

    {

        vector<vector<int>> Prefix_Color(Picture.width + 6 , vector<int>(Picture.height + 6 , 0));



        // Prefix sum Horizontal

        for (int i = 1 ; i < Picture.width ; ++i)

        {

            for (int j = 1 ; j < Picture.height ; ++j)

            {

                Prefix_Color[i][j] = Prefix_Color[i][j - 1] + Picture(i - 1 , j - 1 , channels);

            }

        }

        // Prefix sum Vertical

        for (int i = 1 ; i < Picture.width ; ++i)

        {

            for (int j = 1 ; j < Picture.height ; ++j)

            {

                Prefix_Color[i][j] += Prefix_Color[i - 1][j];

            }

        }



        for (int i = 1 ; i < Picture.width ; ++i)

        {

            for (int j = 1 ; j < Picture.height ; ++j)

            {

                int x1 = max(0 , i - 1 - R);

                int x2 = min(Picture.width - 1 , i + R);

                int y1 = max(0 , j - 1 - R);

                int y2 = min(Picture.height - 1 , j + R);



                long long Sum = Prefix_Color[x2][y2] - Prefix_Color[x1][y2] -

                                Prefix_Color[x2][y1] + Prefix_Color[x1][y1];



                int lower = (2 * R + 1) * (2 * R + 1);

                long long avg = Sum / lower;

                if (avg > 255)

                {

                    avg = 255;

                }

                else if (avg < 0)

                {

                    avg = 0;

                }



                Canva(i , j , channels) = avg;

            }

        }

        --channels;

    }

    Picture = Canva;

}



void Natural_Sunlight(Image& Picture)

{

    int Blue = 0 , Green , Red;

    for (int i = 0 ; i < Picture.width ; ++i)

    {

        for (int j = 0 ; j < Picture.height ; ++j)

        {

            Blue = Picture(i , j , 2);

            if (Blue > 100)

            {

                Picture(i , j , 2) -= 30;

            }



            Red = Picture(i , j , 0);

            Green = Picture(i , j , 1);



            if (Red < 60 && Green < 60 )

            {

                Picture(i , j , 0) += 20;

                Picture(i , j , 1) += 20;

            }



            Red *= 1.10;

            if (Red > 255)

            {

                Red = 255;

            }

            Picture(i , j , 0) = Red;



            Blue *= 0.85;

            if (Blue < 0)

            {

                Blue = 0;

            }

            Picture(i , j , 2) = Blue;

        }

    }

}



void Oil_Painting(Image& Picture)

{



    int R = 3;

    Image Canva(Picture.width , Picture.height);



    for (int i = 0 ; i < Picture.width ; ++i)

    {

        for (int j = 0 ; j < Picture.height ; ++j)

        {

            for (int k = 0 ; k < Picture.channels ; ++k)

            {

                int freq[256] = {0};



                for (int dx = -R ; dx <= R ; ++dx)

                {

                    for (int dy = -R ; dy <= R ; ++dy)

                    {

                        int row = i + dx;

                        int column = j + dy;

                        if (is_Valid_Pixel(Picture, row, column))

                        {

                            int Color_Value = Picture(row, column, k);

                            ++freq[Color_Value];

                        }

                    }

                }



                int best_value = 0, best_count = 0;

                for (int q = 0 ; q < 256 ; ++q)

                {

                    if (freq[q] > best_count)

                    {

                        best_count = freq[q];

                        best_value = q;

                    }

                }

                Canva(i , j , k) = best_value;

            }

        }

    }

    Picture = Canva;

}



void Old_Tv(Image& Picture)

{

    Image Canva = Picture;

    srand(time(0));

    for (int i = 0 ; i < Picture.width ; ++i)

    {

        for (int j = 0 ; j < Picture.height ; ++j)

        {



            // Adding Color Distortion

            if (is_Valid_Pixel(Canva, i, j - 1))

            {

                Picture(i, j, 0) = Canva(i, j - 1, 0);

            }



            if (is_Valid_Pixel(Picture, i, j + 1))

            {

                Picture(i, j, 2) = Canva(i , j + 1, 2);

            }



            for (int k = 0 ; k < Picture.channels ; ++k)

            {

                // Adding Noise

                float Color = Picture(i, j, k);

                // Random Value Between 20 and -20

                float noise = (rand() % 41) - 20;

                float New_Color = noise + Color;



                // Adding Scanlines

                if (j % 2 == 0)

                {

                    New_Color *= 0.90;

                }



                if (New_Color > 255)

                {

                    New_Color = 255;

                }

                else if (New_Color < 0)

                {

                    New_Color = 0;

                }



                Picture(i, j, k) = New_Color;

            }

        }

    }

}



void Purple(Image& Picture)

{

    for (int i = 0 ; i < Picture.width ; ++i)

    {

        for (int j = 0 ; j < Picture.height ; ++j)

        {

            float Red = Picture(i, j, 0);

            float Green = Picture(i, j, 1);

            float Blue = Picture(i, j, 2);



            Red *= 1.15;

            Blue *= 1.15;

            Green *= 0.85;



            if (Red > 255)

            {

                Red = 255;

            }

            if (Green < 0)

            {

                Green = 0;

            }

            if (Blue > 255)

            {

                Blue = 255;

            }

            Picture(i, j, 0) = Red;

            Picture(i, j, 1) = Green;

            Picture(i, j, 2) = Blue;

        }

    }

}



void GrayScale(Image &Picture)

{

    for (int i = 0; i < Picture.width; i++) {

        for (int j = 0; j < Picture.height; j++) {

            unsigned int avg = 0;

            for (int k = 0; k < Picture.channels; k++) {

                avg += Picture(i, j, k);

            }

            avg /= 3;

            for (int k = 0; k < 3; k++) {

                Picture(i, j, k) = avg;

            }

        }

    }

}



void Darken_and_Lighten(Image &Picture , int option) {



    if (option == 1)

    {

        for (int i = 0; i < Picture.width; i++)

        {

            for (int j = 0; j < Picture.height; j++)

            {

                for (int k = 0; k < Picture.channels; k++)

                {

                    int value = Picture(i, j, k);

                    int newVal = int(0.5 * value);

                    if (newVal > 255) newVal = 255;

                    if (newVal < 0) newVal = 0;

                    Picture(i, j, k) = newVal;

                }

            }

        }

    }



    else if (option == 2)

    {

        for (int i = 0; i < Picture.width; i++)

        {

            for (int j = 0; j < Picture.height; j++)

            {

                for (int k = 0; k < Picture.channels; k++)

                {

                    int value = Picture(i, j, k);

                    int newVal = int(1.5 * value);

                    if (newVal > 255) newVal = 255;

                    if (newVal < 0) newVal = 0;

                    Picture(i, j, k) = newVal;

                }

            }

        }

    }

}



void Edge_Detector(Image &image) {

    for (int i = 0; i < image.width; i++) {

        for (int j = 0; j < image.height; j++) {

            unsigned int avg = 0;

            for (int k = 0; k < 3; k++) {

                avg += image(i, j, k);

            }

            avg /= 3;

            for (int k = 0; k < 3; k++) {

                image(i, j, k) = avg;

            }

        }

    }



    Image edge = image;



    for (int i = 0; i < edge.width; i++) {

        for (int j = 0; j < edge.height; j++) {

            for (int k = 0; k < 3; k++) {

                edge(i, j, k) = 0;

            }

        }

    }



    // Sobel kernels

    int Gx[3][3] = {

    {-1, 0, 1},

        {-2, 0, 2},

        {-1, 0, 1}

};

int Gy[3][3] = {

{-1, -2, -1},

    {0,  0,  0},

    {1,  2,  1}

};



// Edge detection

for (int j = 1; j < image.height - 1; j++) {

    for (int i = 1; i < image.width - 1; i++) {

        int sumX = 0, sumY = 0;

        for (int dj = -1; dj <= 1; dj++) {

            for (int di = -1; di <= 1; di++) {

                int pxl = (int)image(i + di, j + dj, 0);

                sumX += pxl * Gx[dj + 1][di + 1];

                sumY += pxl * Gy[dj + 1][di + 1];

            }

        }

        int magnitude = (int)std::sqrt(sumX * sumX + sumY * sumY);

        magnitude = std::min(255, std::max(0, magnitude));



        for (int k = 0; k < 3; k++) {

            edge(i, j, k) = 255 - magnitude;

        }

    }

}

image = edge;

}



void Infrared(Image &pic) {

    for (int i = 0 ; i < pic.width ; ++i)

    {

        for (int j = 0 ; j < pic.height ; ++j)

        {

            for (int k = 0 ; k < pic.channels ; ++k)

            {

                unsigned int value = pic.getPixel(i , j , k);

                value = 255 - value;



                if (value > 255)

                value = 255;



                pic(i , j , k) = value;

            }

            pic(i, j, 0) = 255;

        }

    }



}

void Resize(Image& Picture , int x , int y) {

    Image resized(x,y);

    double width_scale = static_cast<double>(Picture.width) / resized.width;
    double height_scale = static_cast<double>(Picture.height) / resized.height;

    for(int i = 0; i < resized.width; i++ ) {
        double newx ,newy;
        for(int j = 0 ; j < resized.height; j++ ) {
            for(int k = 0 ; k < 3 ; k++ ) {
                newx= round(i* width_scale);
                newy = round(j* height_scale);
                resized(i,j,k)=Picture(newx,newy,k);
            }
        }
    }
    Picture = resized;
}

void Merged(Image &picture , Image& Canva) {

    Resize(Canva , picture.width , picture.height );

    for (int i = 0; i < picture.width; i++) {

        for (int j = 0; j < picture.height; j++) {

            for (int k = 0; k < picture.channels; k++) {

                int val1 = picture(i, j, k);
                int val2 = Canva(i, j, k);

                float alpha = 0.5;

                int newVal = int(alpha * val1 + (1 - alpha) * val2);

                picture(i, j, k) = newVal;

            }

        }
    }
}

void Red_Detector(Image &pic) {

    for (int i = 0; i < pic.width; i++) {

        for (int j = 0; j < pic.height; j++) {

            int R = pic(i, j, 0);

            int G = pic(i, j, 1);

            int B = pic(i, j, 2);



            if (R > 110 && R > G * 2 && R > B * 2) {

                pic(i, j, 0) = R;

                pic(i, j, 1) = G;

                pic(i, j, 2) = B;

            } else {

                unsigned int avg = (R + G + B) / 3;

                pic(i, j, 0) = avg;

                pic(i, j, 1) = avg;

                pic(i, j, 2) = avg;

            }

        }

    }

}

void Black_and_White(Image& Picture) {



    for(int i=0;i<Picture.width;i++) {

        for(int j=0;j<Picture.height;j++) {

            unsigned int avg =0;

            for(int k=0;k<3;k++) {

                avg+=Picture(i,j,k);

            }

            avg/=3;

            if(avg<=128){avg=0;}

            else {

                avg=255;

            }

            for(int k=0;k<3;k++) {

                Picture(i,j,k)=avg;

            }

        }

    }

}



void Flip(Image& Picture , int option) {



    if(option == 1) {

        for(int i=0;i<Picture.width/2;i++) {

            for(int j=0;j<Picture.height;j++) {

                for(int k=0;k<3;k++) {

                    int temp;

                    temp=Picture(i,j,k);

                    Picture(i,j,k)=Picture(Picture.width-i-1,j,k);

                    Picture(Picture.width-i-1,j,k)=temp;

                }

            }

        }

    }

    else if (option == 2)

    {

        for(int i=0;i<Picture.width;i++) {

            for(int j=0;j<Picture.height/2;j++) {

                for(int k=0;k<3;k++) {

                    int temp;

                    temp=Picture(i,j,k);

                    Picture(i,j,k)=Picture(i,Picture.height-j-1,k);

                    Picture(i,Picture.height-j-1,k)=temp;

                }

            }

        }

    }

}



void Crop(Image& Picture , int width , int height) {

    int x1,y1;

    x1 = (Photo.width - width) / 2;
    y1 = (Photo.height - height) / 2;

    Image cropped (width , height);

    for(int i=0;i<width;i++) {

        for(int j=0;j<height;j++) {

            for(int k=0;k<3;k++) {

                cropped(i,j,k)=Picture(i+x1,j+y1,k);

            }
        }
    }

    Picture = cropped;
}

void Skew(Image& Picture , int angle) {



    double radangle = M_PI / 180.0 * angle;

    int shift = tan(radangle) * Picture.height;

    int new_w = Picture.width + abs(shift);

    Image skewed(new_w, Picture.height);



    for(int i=0;i<skewed.width;i++) {



        for(int j=0;j<skewed.height;j++) {

            for (int k = 0; k < 3; k++) {

                skewed(i, j, k) =255;

            }

        }

    }



    for(int i=0;i<Picture.width;i++) {



        for(int j=0;j<Picture.height;j++) {



            int newx = i + abs ( tan(radangle)*(Picture.height-j));

            if (newx >= 0 && newx < new_w) {



                for (int k = 0; k < 3; k++) {

                    skewed(newx, j, k) = Picture(i, j, k);

                }

            }

        }

    }

    Picture = skewed;
}



void Cold(Image& Picture) {



    for(int i = 0; i < Picture.width; i++ ) {



        for(int j=0 ; j < Picture.height ;j++ ) {

            if(Picture(i,j,0) - 25 >= 0 ){

                Picture(i,j,0) -= 25 ;

            }

            if(Picture(i,j,1) - 15 >= 0 ){

                Picture(i,j,1) -= 15;

            }

            if(Picture(i,j,2) + 30 <= 255){

                Picture(i,j,2) += 30;

            }

        }

    }

}



//===================



MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)

    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    this->showMaximized();

    ui->lbl_Image_Display->setPixmap(QPixmap(File_Name));
    ui->lbl_Image_Display_2->setPixmap(QPixmap(File_Name));

    // SKEW
    ui->Skew_Angle->setVisible(false);
    ui->Skew_Apply_Button->setVisible(false);
    connect(ui->Skew_Button, &QPushButton::clicked, this, [this]()
            {
                ui->Skew_Angle->show();
                ui->Skew_Apply_Button->show();
            });

    connect(ui->Skew_Apply_Button, &QPushButton::clicked, this, [this]()

            {

                QString Skew_Angle = ui->Skew_Angle->text();

                // Int
                int angle = Skew_Angle.toInt();

                // make sure they entered valid numbers
                if (angle > 0 && angle < 90)
                {
                    Skew(Photo , angle);
                    Images_Stack.push(Photo);
                    UpdateDisplayedImage();
                }
                else
                {
                    QMessageBox::warning(this, "Invalid Input", "Please enter a valid angle 1~89");
                }


            });

    // RESIZE
    ui->Resize_Width->setVisible(false);
    ui->Resize_Height->setVisible(false);
    ui->Resize_Apply_Button->setVisible(false);
    connect(ui->Resize_Button, &QPushButton::clicked, this, [this]()

            {
                ui->Resize_Width->show();
                ui->Resize_Height->show();
                ui->Resize_Apply_Button->show();
            });

    connect(ui->Resize_Apply_Button, &QPushButton::clicked, this, [this]()

            {

                QString widthText = ui->Resize_Width->text();
                QString heightText = ui->Resize_Height->text();

                // Int
                int width = widthText.toInt();
                int height = heightText.toInt();

                // make sure they entered valid numbers
                if (width > 0 && height > 0)
                {
                    Resize(Photo , width , height);
                    Images_Stack.push(Photo);
                    UpdateDisplayedImage();
                }
                else
                {
                    QMessageBox::warning(this, "Invalid Input", "Please enter valid width and height!");
                }


            });


    // FRAME
    ui->Frames_List_menu->setVisible(false);
    connect(ui->Frame_Button, &QPushButton::clicked, this, [this]()

            {
                ui->Frames_List_menu->show();
            });

    connect(ui->Frames_List_menu, &QComboBox::currentTextChanged, this, [this](const QString &selected)
            {

                if (selected == "White Frame") {
                    Adding_Frame(Photo , 1);
                }
                else if (selected == "Black Frame") {
                    Adding_Frame(Photo , 2);
                }
                else if (selected == "Yellowish Gray") {
                    Adding_Frame(Photo , 3);
                }
                else if (selected == "Claret Frame") {
                    Adding_Frame(Photo , 4);
                }
                else if(selected == "Pointy Yellow")
                {
                    Adding_Frame(Photo , 5);
                }

                Images_Stack.push(Photo);
                UpdateDisplayedImage();
            });

    // CROP
    ui->Crop_Width->setVisible(false);
    ui->Crop_Height->setVisible(false);
    ui->Crop_Apply_Button->setVisible(false);

    connect(ui->Crop_Button, &QPushButton::clicked, this, [this]()

            {

                ui->Crop_Width->show();
                ui->Crop_Height->show();
                ui->Crop_Apply_Button->show();

            });

    connect(ui->Crop_Apply_Button, &QPushButton::clicked, this, [this]()

            {

                QString widthText = ui->Crop_Width->text();
                QString heightText = ui->Crop_Height->text();

                // Int
                int width = widthText.toInt();
                int height = heightText.toInt();

                // make sure they entered valid numbers
                if (width > 0 && width < Photo.width - 1 && height < Photo.height - 1 && height > 0)
                {
                    Crop(Photo , width , height);
                    Images_Stack.push(Photo);
                    UpdateDisplayedImage();
                }
                else
                {
                    QMessageBox::warning(this, "Invalid Input", "Please enter valid width and height!");
                }


            });


    // DARKEN AND LIGHTEN

    ui->Darken_Button->setVisible(false);

    ui->Lighten_Button->setVisible(false);

    connect(ui->DarkenandLighten_Button, &QPushButton::clicked, this, [this]()

            {

                ui->Darken_Button->show();
                ui->Lighten_Button->show();

            });

    connect(ui->Darken_Button, &QPushButton::clicked, this, [this]()

            {

                Darken_and_Lighten(Photo , 1);

                UpdateDisplayedImage();

                Images_Stack.push(Photo);

            });



    connect(ui->Lighten_Button, &QPushButton::clicked, this, [this]()

            {

                Darken_and_Lighten(Photo , 2);

                UpdateDisplayedImage();

                Images_Stack.push(Photo);

            });



    // ROTATE IMAGE

    ui->Rotate90_Button->setVisible(false);

    ui->Rotate180_Button->setVisible(false);

    ui->Rotate270_Button->setVisible(false);

    connect(ui->Rotate_Button, &QPushButton::clicked, this, [this]()

            {

                ui->Rotate90_Button->show();

                ui->Rotate180_Button->show();

                ui->Rotate270_Button->show();

            });



    connect(ui->Rotate90_Button, &QPushButton::clicked, this, [this]()

            {

                Rotate_Image(Photo, 1);

                UpdateDisplayedImage();

                Images_Stack.push(Photo);

            });





    connect(ui->Rotate180_Button, &QPushButton::clicked, this, [this]()

            {

                Rotate_Image(Photo, 2);

                UpdateDisplayedImage();

                Images_Stack.push(Photo);

            });





    connect(ui->Rotate270_Button, &QPushButton::clicked, this, [this]()

            {

                Rotate_Image(Photo, 3);

                UpdateDisplayedImage();

                Images_Stack.push(Photo);

            });





    ui->FlipVertical_Button->setVisible(false);

    ui->Flip_Horizontal_Button->setVisible(false);

    connect(ui->Flip_Button, &QPushButton::clicked, this, [this]()

            {

                ui->FlipVertical_Button->show();

                ui->Flip_Horizontal_Button->show();

            });



    connect(ui->FlipVertical_Button, &QPushButton::clicked, this, [this]()

            {

                Flip(Photo, 1);

                UpdateDisplayedImage();

                Images_Stack.push(Photo);

            });



    connect(ui->Flip_Horizontal_Button, &QPushButton::clicked, this, [this]()

            {

                Flip(Photo, 2);

                UpdateDisplayedImage();

                Images_Stack.push(Photo);

            });



    //  BLUR HORIZONTAL SLIDER MAKE IT INVISIBLE

    //  JUMPING BACK WHEN THE SLIDER GOES TO THE MAX

    ui->hSlider->setVisible(false);

    connect(ui->Blur_Button, &QPushButton::clicked, this, [this]()

            {

                ui->hSlider->show();
            });

    connect(ui->hSlider, &QSlider::valueChanged, this, [this](int value)

            {

                static int lastValue = 0;


                if (value > lastValue)
                {
                    Images_Stack.push(Photo);
                    Blur(Photo, value);
                    UpdateDisplayedImage();
                }

                else if (value < lastValue)
                {
                    if (!Images_Stack.empty())
                    {
                        Photo = Images_Stack.top();
                        Images_Stack.pop();
                        UpdateDisplayedImage();
                    }
                }

                lastValue = value;
            });

}



void MainWindow::UpdateDisplayedImage()

{

    QImage qimg(Photo.imageData, Photo.width, Photo.height, Photo.width * 3, QImage::Format_RGB888);

    QPixmap pixmap = QPixmap::fromImage(qimg);
    pixmap = pixmap.scaled(ui->lbl_Image_Display->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->lbl_Image_Display->setPixmap(pixmap);
    ui->lbl_Image_Display->setAlignment(Qt::AlignCenter);
    ui->lbl_Image_Display->setScaledContents(false);

}

void MainWindow::Original_Picture()
{
    QImage qimg2(OriginalPhoto.imageData,
                 OriginalPhoto.width,
                 OriginalPhoto.height,
                 OriginalPhoto.width * 3,
                 QImage::Format_RGB888);

    QPixmap pixmap2 = QPixmap::fromImage(qimg2);
    pixmap2 = pixmap2.scaled(ui->lbl_Image_Display_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->lbl_Image_Display_2->setPixmap(pixmap2);
    ui->lbl_Image_Display_2->setAlignment(Qt::AlignCenter);
    ui->lbl_Image_Display_2->setScaledContents(false);
}

void MainWindow::HideAllButtons()
{
    ui->hSlider->hide();
    ui->Frames_List_menu->hide();
    ui->Rotate90_Button->hide();
    ui->Rotate180_Button->hide();
    ui->Rotate270_Button->hide();
    ui->FlipVertical_Button->hide();
    ui->Flip_Horizontal_Button->hide();
    ui->Darken_Button->hide();
    ui->Lighten_Button->hide();
    ui->Skew_Angle->hide();
    ui->Skew_Apply_Button->hide();
    ui->Crop_Width->hide();
    ui->Crop_Height->hide();
    ui->Crop_Apply_Button->hide();
    ui->Resize_Height->hide();
    ui->Resize_Width->hide();
    ui->Resize_Apply_Button->hide();
}

MainWindow::~MainWindow()

{

    delete ui;

}



// ============================== Buttons section ===============================



// Load Image Button

// Opens a dir selector with 4 image extensions

void MainWindow::on_LoadImage_Button_clicked()

{
    HideAllButtons();
    QString Default_Path = QDir::homePath();

    File_Name = QFileDialog::getOpenFileName(this, tr("Select Image File"), Default_Path,

                                             tr("*.jpg *.png *.bmp *.jpeg"));



    string Std_File_Name = File_Name.toStdString();



    if(Std_File_Name.empty())

    {

        return;

    }

    while(!Images_Stack.empty())
    {
        Images_Stack.pop();
    }

    Photo.loadNewImage(Std_File_Name);
    OriginalPhoto = Photo;

    Images_Stack.push(Photo);


    UpdateDisplayedImage();
    Original_Picture();



    qDebug() << "File Name :: " << File_Name;

}


// Save Image Button

void MainWindow::on_SaveImage_Button_clicked()

{
    HideAllButtons();
    QString Default_Path = QDir::homePath();



    File_Name = QFileDialog::getSaveFileName(this, tr("Save Image File"), Default_Path,

                                             tr("*.jpg *.png *.bmp *.jpeg"));

    string std_File_Name = File_Name.toStdString();

    if(std_File_Name.empty() || !Valid_Extension(std_File_Name))

    {
        QMessageBox::warning(this, "Invalid File Extension", "Valid Extensions are .jpg, .png, .jpeg, .bmp");
        return;
    }

    Photo.saveImage(std_File_Name);

}



void MainWindow::on_GrayScale_Button_clicked()

{
    HideAllButtons();
    GrayScale(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);

}



void MainWindow::on_Invert_Push_Button_clicked()

{
    HideAllButtons();
    Invert_Colors(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);

}



void MainWindow::on_BlackandWhite_Button_clicked()

{

    HideAllButtons();
    Black_and_White(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);

}


void MainWindow::on_Flip_Button_clicked()

{
    HideAllButtons();
}





void MainWindow::on_Rotate_Button_clicked()

{
    HideAllButtons();
}



void MainWindow::on_DarkenandLighten_Button_clicked()

{
    HideAllButtons();
}

void MainWindow::on_Crop_Button_clicked()

{
    HideAllButtons();
}

void MainWindow::on_Frame_Button_clicked()

{
    HideAllButtons();
}

void MainWindow::on_Edge_Detector_Button_clicked()

{

    HideAllButtons();
    Edge_Detector(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);

}





void MainWindow::on_Resize_Button_clicked()

{
    HideAllButtons();
}

void MainWindow::on_Blur_Button_clicked()

{
    HideAllButtons();
}

void MainWindow::on_Natural_Sunlight_Button_clicked()

{
    HideAllButtons();

    Natural_Sunlight(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);



}

void MainWindow::on_OilPaint_Button_clicked()

{

    HideAllButtons();
    Oil_Painting(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);

}


void MainWindow::on_Oldtv_Button_clicked()

{

    HideAllButtons();
    Old_Tv(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);



}

void MainWindow::on_Purple_Button_clicked()

{
    HideAllButtons();
    Purple(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);



}

void MainWindow::on_Infrared_Button_clicked()

{

    HideAllButtons();
    Infrared(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);



}





void MainWindow::on_Skew_Button_clicked()

{
    HideAllButtons();
}


void MainWindow::on_Cold_Button_clicked()

{

    HideAllButtons();
    Cold(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);



}



void MainWindow::on_RedDetector_Button_clicked()

{

    HideAllButtons();
    Red_Detector(Photo);

    UpdateDisplayedImage();

    Images_Stack.push(Photo);

}



void MainWindow::on_Undo_Button_clicked()

{

    Undo();

    ui->hSlider->setValue(0);
    if(!Images_Stack.empty())

    {

        Photo = Images_Stack.top();

        UpdateDisplayedImage();

    }

}

void MainWindow::on_Merge_Button_clicked()
{
    QString Default_Path = QDir::homePath();

    QString Merge_File_Name = QFileDialog::getOpenFileName(
        this,
        tr("Select Image to Merge"),
        Default_Path,
        tr("*.jpg *.png *.bmp *.jpeg")
        );

    if (Merge_File_Name.isEmpty())
        return;

    string Std_Merge_File_Name = Merge_File_Name.toStdString();

    Image Canva;
    Canva.loadNewImage(Std_Merge_File_Name);

    Merged(Photo, Canva);
    Images_Stack.push(Photo);
    UpdateDisplayedImage();

}
