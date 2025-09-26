#include "Image_Class.h"
#include <iostream>
using namespace std;
void black_AND_white() {
    Image image("building.jpg");
    for(int i=0;i<image.width;i++) {
        for(int j=0;j<image.height;j++) {
            unsigned int avg =0;
            for(int k=0;k<3;k++) {
                avg+=image(i,j,k);
            }
            avg/=3;
            if(avg<=128){avg=0;}
            else {
                avg=255;
            }
            for(int k=0;k<3;k++) {
                image(i,j,k)=avg;
            }
        }
    }
    image.saveImage("building_black_and_white.png");
}

void flip() {
    Image image("arrow.jpg");
    cout<<"press h for horizontal flip or v for vertical flip\n";
    char flip_kind;
    cin>>flip_kind;
    if(flip_kind=='h') {
        for(int i=0;i<image.width/2;i++) {
            for(int j=0;j<image.height;j++) {
                for(int k=0;k<3;k++) {
                    int temp;
                    temp=image(i,j,k);
                    image(i,j,k)=image(image.width-i-1,j,k);
                    image(image.width-i-1,j,k)=temp;
                }
            }
        }
    }
    else{
        for(int i=0;i<image.width;i++) {
            for(int j=0;j<image.height/2;j++) {
                for(int k=0;k<3;k++) {
                    int temp;
                    temp=image(i,j,k);
                    image(i,j,k)=image(i,image.height-j-1,k);
                    image(i,image.height-j-1,k)=temp;
                }
            }
        }
    }
    image.saveImage("arrow_fliped.png");
    cout<<"done";
}

int main() {
flip();
    return 0;
}
