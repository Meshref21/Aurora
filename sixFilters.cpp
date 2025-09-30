#include "Image_Class.h"
#include <filesystem>
using namespace std;

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
        cin >> Image_Name;
        if (Check_Image_Validation(Image_Name))
        {
            break;
        }
    }
    Picture.loadNewImage(Image_Name);
}

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
    unsigned int option;
    cout << "1.Rotate 90 Degree" << '\n';
    cout << "2.Rotate 180 Degree" << '\n';
    cout << "3.Rotate 270 Degree" << '\n';
    cin >> option;

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

void Darken_and_Lighten(Image &Picture) {

    unsigned int option;
    cout << "1.Darken\n";
    cout << "2.Lighten\n";
    cin >> option;

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

 // Shows All The Filters And Apply A Change on The Image
void Filters_List(Image& Picture)
{
    unsigned int Filter_num;
    cout << "1. Black And White" << '\n';
    cout << "2. Invert Colors" << '\n';
    cout << "3. GrayScale" << '\n';
    cout << "4. Darken And Lighten" << '\n';
    cout << "5. Flip" << '\n';
    cout << "6. Rotate" << '\n';
    cin >> Filter_num;

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
        cin >> Image_Name;
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
