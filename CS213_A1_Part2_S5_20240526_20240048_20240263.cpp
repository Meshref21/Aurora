// Github repo : https://github.com/Meshref21/photoeditor
// Document : https://drive.google.com/file/d/15pdmZmUyn7E51XLWCQk3qjCBKExxXKL9/view
// Video : https://drive.google.com/file/d/1oqJmEQr0KluO5woJMW5u9MfGtvit_zFs/view?usp=sharing

// Mohamed Mahmoud
// id : 20240526
// All-B
// Invert_Colors - Rotate_Image - Adding_Frame - Blur
// Oil_Painting - Old_Tv - Purple

// Ahmed Mohamed
// id : 20240048
// S5
// GrayScale - Darken Lighten - Edge_Detecting - Infrared - Red_Detecting - Merged

// Saif Mohamed
// id : 20240263
// S5
// Black and White - Flip - Crop - Resize - Skew - Cold - Natural_Sunlight


#include <algorithm>
#include "Image_Class.h"
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

bool is_Valid_Pixel(Image& Picture , int i , int j)
{
    return i < Picture.width && i >= 0 && j < Picture.height && j >= 0;
}

int Valid_Extension(string& File_Name)
{
    string Valid_Extensions[4] = {"jpg" , "jpeg" , "bmp" , "png"};
    int Dot_Position = File_Name.find('.');

    if (Dot_Position == -1)
    {
        return -1;
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
            return 1;
        }
    }
    return 0;
}

void Save_Image(Image& Picture, string& Image_Name , string& Save_Name)
{
    Save_Label:
    unsigned int option;
    cout << "1. Save On The Same File (Replace)" << '\n';
    cout << "2. Save On New File" << '\n';
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(option)
    {
        case 1:
            Picture.saveImage(Image_Name);
        break;
        case 2:
            cout << "Enter File Name\n";
            while (true)
            {
                cin >> Save_Name;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (Valid_Extension(Save_Name) == -1)
                {
                    cout << "Please Specify The Image Extension\n";
                }
                else if (Valid_Extension(Save_Name) == 0 )
                {
                    cout << "Invalid Extension Try Again\n";
                }
                else
                    break;
            }
            Picture.saveImage(Save_Name);
        break;
        default:
            cout << "This Is Not A Valid Option Try Again\n";
            goto Save_Label;
    }
}

void Save_Confirmation(Image& Picture, string& Image_Name, string& Save_Name)
{
    int option;
    cout << "1. Save Current Image\n";
    cout << "2. Continue Without Saving\n";

    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (option)
    {
        case 1:
            Save_Image(Picture, Image_Name, Save_Name);
        break;
        case 2:
            break;
        default:
            cout << "Invalid Option Try Again\n";
    }
}

bool File_Exists(string& Picture_Name)
{
    if (filesystem::exists(Picture_Name))
    {
        return true;
    }
    return false;
}

bool Check_Image_Validation(string& To_Check)
{
        if (File_Exists(To_Check))
        {
            return true;
        }

        if (!Valid_Extension(To_Check))
        {
            cout << "Invalid Extension Try Again\n";
            cout << "Usable Extensions: jpg, jpeg, png, bmp\n";
            return false;
        }

        if (Valid_Extension(To_Check) == -1)
        {
            cout << "Please Specify The Image Extension\n";
            return false;
        }

        cout << "Invalid Image Name Try Again\n";
    return false;
}

void Load_Image(Image& Picture, string& Image_Name)
{
    while (true)
    {
        cout << "Enter The Image Filename (e.g. luffy.jpg)\n";
        getline(cin , Image_Name);
        if (Check_Image_Validation(Image_Name))
        {
            break;
        }
    }
    Picture.loadNewImage(Image_Name);
}
//===================================

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

void Rotate_Image(Image& Picture)
{
    Local_Label:
    unsigned int option;
    cout << "1.Rotate 90 Degree" << '\n';
    cout << "2.Rotate 180 Degree" << '\n';
    cout << "3.Rotate 270 Degree" << '\n';
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // ROTATE IMAGE 90 DEGREE
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
    else
    {
        cout << "Enter A Number Between 1 and 3 Try Again!\n";
        goto Local_Label;
    }
}

void Adding_Frame(Image& Picture)
{
    float ratio = 0.03;
    Image Canva(Picture.width + Picture.width * ratio , Picture.height + Picture.height * ratio);

    Local_Label:
    cout << "1. Solid Color Frame\n";
    cout << "2. Fancy Frame\n";
    int option; cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int Red = 0 , Green = 0 , Blue = 0;

    if (option == 1)
    {
        cout << "1. White Frame\n";
        cout << "2. Black Frame\n";
        cout << "3. Yellowish Gray Frame\n";
        cout << "4. Claret Frame\n";
        int value; cin >> value;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (value)
        {
            case 1:
                Red = 255 , Green = 255 , Blue = 255;
                break;
            case 2:
                Red = 0 , Green = 0 , Blue = 0;
                break;
            case 3:
                Red = 244 , Green = 210 , Blue = 108;
                break;
            case 4:
                Red = 129 , Green = 19 , Blue = 49;
                break;
            default:
                cout << "Enter A Number Between 1 ~ 4 Try Again!\n";
                goto Local_Label;
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

    }
    else if (option == 2)
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
    }
    else
        {
            cout << "Enter 1 or 2 Try Again!\n";
            goto Local_Label;
        }

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

void Blur(Image& Picture)
{
    Image Canva(Picture.width , Picture.height);

    Local_Label:
    int R;
    cout << "Enter Your Blur Level 1 ~ 5" << '\n';
    cin >> R;

    if (R > 5 || R < 0)
    {
        cout << "Please Enter A Number Between 1 And 5\n";
        goto Local_Label;
    }


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

        for (int i = 0 ; i < Picture.width ; ++i)
        {
            for (int j = 0 ; j < Picture.height ; ++j)
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
    Local_Label:
    cout << "Enter The Level Of This Effect 1~3\n";
    int R; cin >> R;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (R > 3 || R <= 0)
    {
        cout << "Try Again!\n";
        goto Local_Label;
    }

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
//=================================

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

void Darken_and_Lighten(Image &Picture) {

    unsigned int option;
    cout << "1.Darken\n";
    cout << "2.Lighten\n";
    cin >> option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

void Merged(Image &picture) {

    Image Canva;
    string Save_Name;
    Load_Image(Canva , Save_Name);

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

//=================================
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

void Flip(Image& Picture) {

    unsigned int option;
    cout << "1.Flip Horizontal\n";
    cout << "2.Flip Vertical\n";
    cin>>option;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void Crop(Image& Picture) {
    int x1,y1,w,h;
    cout<<"Please Enter Starting x: ";
    cin>>x1;
    cout<<"Please Enter Starting y: ";
    cin>>y1;
    again:
    cout<<"Please Enter The Width You want to crop : ";
    cin>>w;
    cout<<"Please Enter The Height You want to crop : ";
    cin>>h;
    Image cropped (w,h);
    if(x1>Picture.width||y1>Picture.height||w+x1>Picture.width||h+y1>Picture.height) {
        cout<<"This rectangle is out of range\n";
        goto again;
    }
    for(int i=0;i<w;i++) {
        for(int j=0;j<h;j++) {
            for(int k=0;k<3;k++) {
                cropped(i,j,k)=Picture(i+x1,j+y1,k);
            }
        }
    }
    Picture = cropped;
}
void Resize(Image& Picture) {

    int x,y;
    cout<<"Enter The New Width Of Image: \n";
    cin>>x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Enter The New Height Of Image: \n";
    cin>>y;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void Skew(Image& Picture) {

    int angle;
    cout << "Enter The Angle Of Skewness: \n";
    cin >> angle;
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

 // Shows All The Filters And Apply A Change on The Image
void Filters_List(Image& Picture)
{
    unsigned int Filter_num;
    cout << "1.  Black And White" << '\n';
    cout << "2.  Invert Colors" << '\n';
    cout << "3.  GrayScale" << '\n';
    cout << "4.  Darken And Lighten" << '\n';
    cout << "5.  Flip" << '\n';
    cout << "6.  Rotate" << '\n';
    cout << "7.  Adding Frame\n";
    cout << "8.  Blur\n";
    cout << "9.  Natural SunLight\n";
    cout << "10. Oil Painting\n";
    cout << "11. Old TV\n";
    cout << "12. Purple\n";
    cout << "13. Skew\n";
    cout << "14. Cold Effect\n";
    cout << "15. Resize\n";
    cout << "16. Crop\n";
    cout << "17. Merge\n";
    cout << "18. Red Detector\n";
    cout << "19. Infrared\n";
    cout << "20. Edge Detector\n";
    cin >> Filter_num;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (Filter_num)
    {
        case 1:
            Black_and_White(Picture);
            break;
        case 2:
            Invert_Colors(Picture);
            break;
        case 3:
            GrayScale(Picture);
            break;
        case 4:
            Darken_and_Lighten(Picture);
            break;
        case 5:
            Flip(Picture);
            break;
        case 6:
            Rotate_Image(Picture);
            break;
        case 7:
            Adding_Frame(Picture);
            break;
        case 8:
            Blur(Picture);
            break;
        case 9:
            Natural_Sunlight(Picture);
            break;
        case 10:
            Oil_Painting(Picture);
            break;
        case 11:
            Old_Tv(Picture);
            break;
        case 12:
            Purple(Picture);
            break;
        case 13:
            Skew(Picture);
            break;
        case 14:
            Cold(Picture);
            break;
        case 15:
            Resize(Picture);
            break;
        case 16:
            Crop(Picture);
            break;
        case 17:
            Merged(Picture);
            break;
        case 18:
            Red_Detector(Picture);
            break;
        case 19:
            Infrared(Picture);
            break;
        case 20:
            Edge_Detector(Picture);
            break;
        default:
            cout << "This Is Not A Valid Option Try Again\n";
    }
}

void Menu(Image& Picture)
{
    string Image_Name , Save_Name;
    bool is_Saved = true;

    // Load image for the first time
    while (true)
    {
        cout << "Enter The Image Filename (e.g. luffy.jpg)\n";
        getline(cin , Image_Name);
        if (Check_Image_Validation(Image_Name))
        {
            break;
        }
    }
    Picture.loadNewImage(Image_Name);

    while (true)
    {
        unsigned int Option;
        cout << "1. Load New Image" << '\n';
        cout << "2. Filters" << '\n';
        cout << "3. Save Image " << '\n';
        cout << "4. Exit " << '\n';
        cin >> Option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (Option)
        {
            case 1:
                if (!is_Saved)
                {
                    Save_Confirmation(Picture, Image_Name, Save_Name);
                }
                Load_Image(Picture, Image_Name);
            break;
            case 2:
                Filters_List(Picture);
                is_Saved = false;
                break;
            case 3:
                Save_Image(Picture, Image_Name, Save_Name);
                is_Saved = true;
                break;
            case 4:
                if (!is_Saved)
                {
                    Save_Confirmation(Picture, Image_Name, Save_Name);
                }
                cout << "THANK YOU" << '\n';
                return;
            default:
                cout << "This Is Not A Valid Option Try Again\n";
        }
    }
}

int main()
{
    Image Photo;
    Menu(Photo);
}
