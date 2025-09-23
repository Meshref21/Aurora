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

void Rotate_Image(Image& Picture)
{
    //=============================== (IT'S FLIPPING) ====== (DELETE THIS)
    for (int i = 0 ; i < Picture.width / 2 ; ++i)
    {
        for (int j = 0 ; j < Picture.height ; ++j)
        {
            for (int k = 0 ; k < Picture.channels ; ++k)
            {
                swap(Picture(i , j , k) , Picture(Picture.width - 1 - i , j , k));
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
    Photo.loadNewImage("building.jpg");
    Image Photo2(Photo.width , Photo.height);
    Blurring_Image(Photo , Photo2);

    Photo2.saveImage("me.jpg");
}
