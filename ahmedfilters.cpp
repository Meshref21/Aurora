#include "Image_Class.h"
using namespace std;

void Grayscaled(Image &image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg /= 3;
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = avg;
            }
        }
    }

}

void Merged(Image &picture, Image &photo) {
    for (int i = 0; i < picture.width; i++) {

        for (int j = 0; j < picture.height; j++) {

            for (int k = 0; k < picture.channels; k++) {
                int val1 = picture(i, j, k);
                int val2 = photo(i, j, k);

                float alpha = 0.5;
                int newVal = int(alpha * val1 + (1 - alpha) * val2);

                picture(i, j, k) = newVal;
            }
        }
    }
}

void Darken(Image &picture) {
    for (int i = 0; i < picture.width; i++) {

        for (int j = 0; j < picture.height; j++) {

            for (int k = 0; k < picture.channels; k++) {

                int value = picture(i, j, k);
                int newVal = int(0.5 * value);
                if (newVal > 255) newVal = 255;
                if (newVal < 0) newVal = 0;
                picture(i, j, k) = newVal;

            }
        }
    }
}

void Lighten (Image &picture) {
    for (int i = 0; i < picture.width; i++) {

        for (int j = 0; j < picture.height; j++) {

            for (int k = 0; k < picture.channels; k++) {

                int value = picture(i, j, k);
                int newVal = int(1.5 * value);
                if (newVal > 255) newVal = 255;
                if (newVal < 0) newVal = 0;
                picture(i, j, k) = newVal;

            }
        }
    }
}


//Working on Edge detecting filter
int main() {
    Image image("luffy.jpg");


    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg /= 3;

            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = avg;
            }
        }
    }


    Image edge = image;
    edge.channels = 1;


    for (int i = 0; i < edge.width; i++)
        for (int j = 0; j < edge.height; j++)
            edge(i, j, 0) = 0;

    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };


    for (int j = 1; j < image.height - 1; j++) {
        for (int i = 1; i < image.width - 1; i++) {
            int sumX = 0;
            int sumY = 0;

            for (int dj = -1; dj <= 1; dj++) {
                for (int di = -1; di <= 1; di++) {
                    int pxl = (int) image(i + di, j + dj, 0);
                    int kx = Gx[dj + 1][di + 1];
                    int ky = Gy[dj + 1][di + 1];
                    sumX += pxl * kx;
                    sumY += pxl * ky;
                }
            }

            int magnitude = (int)std::sqrt((double)sumX * sumX + (double)sumY * sumY);
            if (magnitude > 255) magnitude = 255;
            if (magnitude < 0) magnitude = 0;


            edge(i, j, 0) = 255 - (unsigned char)magnitude;
        }
    }


    edge.saveImage("edges.jpg");
    std::cout << "Saved edges_inverted.jpg\n";
}


