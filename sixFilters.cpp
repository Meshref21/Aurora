#include "Image_Class.h"
#include <filesystem>
using namespace std;

bool Valid_Name(string Picture_Name)
{
    if (filesystem::exists(Picture_Name))
    {
        return true;
    }
    return false;
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

void Rotate_Image(Image& Picture , Image& Canva)
{

    // PICTURE HEIGHT = CANVA WIDTH AND VICE VERSA =========== (REVERSE NEEDED)
    // ROTATE IMAGE 270 DEGREE
    for (int i = 0 ; i < Canva.width ; ++i)
    {
        for (int j = 0 ; j < Canva.height ; ++j)
        {
            for (int k = 0 ; k < Canva.channels ; ++k)
            {
                Canva(i , j , k) = Picture(Canva.height - 1 - j , i , k);
            }
        }
    }

    // PICTURE HEIGHT = CANVA WIDTH AND VICE VERSA =========== (REVERSE NEEDED)
    // ROTATE IMAGE 90 DEGREE
    for (int i = 0 ; i < Canva.width ; ++i)
    {
        for (int j = 0 ; j < Canva.height ; ++j)
        {
            for (int k = 0 ; k < Picture.channels ; ++k)
            {
                Canva(i , j , k) = Picture(j , Canva.width - 1 - i , k);
            }
        }
    }

    // ROTATE 180 DEGREE
    for (int i = 0 ; i < Picture.width ; ++i)
    {
        for (int j = 0 ; j < Picture.height ; ++j)
        {
            for (int k = 0 ; k < Picture.channels ; ++k)
            {
                Canva(i , j , k) = Picture(Picture.width - i , Picture.height - j , k);
            }
        }
    }
}

void GrayScale(Image &Picture) {
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


int main()
{
    // NOT FINISHED YET ============================== (DELETE THIS) (MENU)
    Image Photo; string Image_Name; string Save_Name;
    // Image Photo2(Photo.height , Photo.width);

    while (true)
    {
        unsigned int Option;
        cout << "1. Load Image" << '\n';
        cout << "2. Filters" << '\n';
        cout << "3. Save Image " << '\n';
        cout << "4. Exit " << '\n';

        cin >> Option;

        switch (Option)
        {
            case 1:
                cout << "Enter The Image Name" << '\n';
                cin >> Image_Name;
                if (!Valid_Name(Image_Name))
                {
                    cout << '\n';
                    cout << "Image not Found\n";
                }
                else
                {
                    Photo.loadNewImage(Image_Name);
                }
            break;
            case 2:
                unsigned int Filter_num;
                cout << "1.Black And White" << '\n';
                cout << "2.Invert Colors" << '\n';
                cout << "3.GrayScale" << '\n';
                cout << "4.Darken And Lighten" << '\n';
                cout << "5.Flip" << '\n';
                cout << "6.Rotate" << '\n';
                cin >> Filter_num;

                switch (Filter_num)
                {
                    case 1:
                        Black_and_White(Photo);
                    break;
                        case 2:
                        Invert_Colors(Photo);
                    break;
                        case 3:
                        GrayScale(Photo);
                    break;
                        case 4:
                        Darken_and_Lighten(Photo);
                    break;
                        case 5:
                        Flip(Photo);
                    break;
                        case 6:
                        // Rotate_Image(Photo);
                    break;
                    default:
                        cout << "This Is Not A Valid Option\n";
                }

                break;
            case 3:
                unsigned int option;
                cout << "1.Save On The Same File" << '\n';
                cout << "2.New File" << '\n';
                cin >> option;

                if (option == 1)
                {
                    Photo.saveImage(Image_Name);
                }
                else if (option == 2)
                {
                    cout << "Enter File Name\n";
                    cin >> Save_Name;
                    Photo.saveImage(Save_Name);
                }
            break;
            case 4:
                cout << "THANK YOU" << '\n';
                return 0;
            default:
                cout << "This Is Not A Valid Option\n";
        }
        cout << '\n';
    }
}
