#include "Image_Class.h"
using namespace std;

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

void Adding_Frame(Image& Picture , Image& Canva)
{
    // CREATE ANOTHER OBJECT WHICH IS LARGER BY NEARLY 60 - 80 ============== (DELETE THIS)
    // Fill The Empty Canva With Color
    for (int i = 0 ; i < Canva.width ; ++i)
    {
        for (int j = 0 ; j < Canva.height ; ++j)
        {
            for (int k = 0 ; k < Canva.channels ; ++k)
            {
                Canva(i , j , k) = 255;
            }
        }
    }

    // Copy Our Photo's Pixels Inside The Solid Color Canva
    // IT HAS A PROBLEM IT EATS UP THE LEFT ASPECT OF THE IMAGE =============== (DELETE THIS)
    for (int i = 80 ; i < Picture.width ; ++i)
    {
        for (int j = 80 ; j < Picture.height ; ++j)
        {
            for (int k = 0 ; k < Picture.channels ; ++k)
            {
                Canva(i , j , k) = Picture(i , j , k);
            }
        }
    }
}

void Blurring_Image(Image& Picture , Image& Canva)
{
    unsigned int avg = 0;
    for (int i = 0 ; i < Picture.width ; ++i)
        {
        unsigned int sum = 0;

        for (int j = 0 ; j < Picture.height ; ++j)
        {
            for (int k = 0 ; k < Picture.channels ; ++k)
            {
                sum += Picture(i , j , k);
                Canva(i , j , k) = avg;
            }
        }
        avg = sum / Picture.height;
    }
}

int main()
{
    Image Photo;
    Photo.loadNewImage("short_toy.png");
    Image Photo2(Photo.height , Photo.width);
    Photo2.saveImage("me.jpg");
}
