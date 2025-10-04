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
////////////////////////////////////////////

void Crop(Image & Picture) {
    int x1,y1,w,h;
    cout<<"Enter image name + extention\n";
    string pic_name;
    cin>>pic_name;
    Image picture;
    picture.loadNewImage(pic_name);
    cout<<"Please Enter Starting x: ";
    cin>>x1;
    cout<<"Please Enter Starting y: ";
    cin>>y1;
    cout<<"Please Enter The Width You want to crop : ";
    cin>>w;
    cout<<"Please Enter The Height You want to crop : ";
    cin>>h;
    Image cropped (w,h);
    if(x1>picture.width||y1>picture.height||w+x1>picture.width||h+y1>picture.height) {
        cout<<"This rectangle is out of range\n";
        //call load function
    }
    else {

        for(int i=0;i<w;i++) {
            for(int j=0;j<h;j++) {
                for(int k=0;k<3;k++) {
                    cropped(i,j,k)=picture(i+x1,j+y1,k);
                }
            }
        }

    }
    string new_name;
    cout<<"Enter the new name: \n";
    cin>>new_name;
   cropped.saveImage(new_name);
}


int main() {
    Image picture;
    Crop(picture);
    return 0;
}


