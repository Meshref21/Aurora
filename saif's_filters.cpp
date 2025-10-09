#include "Image_Class.h"
#include <cmath>
#include <iostream>

using namespace std;
void black_AND_white() {
    Image image("building.jpg");
    for(int i = 0; i < image.width; i++ ) {
        for(int j = 0 ; j < image.height; j++ ) {
            unsigned int avg =0;
            for(int k = 0;k < 3; k++) {
                avg+=image(i,j,k);
            }
            avg/=3;
            if(avg<=128){avg=0;}
            else {
                avg=255;
            }
            for(int k=0 ; k<3; k++) {
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
/////////////////////////////
void Resize() {
    cout<<"Enter image name + extention\n";
    string pic_name;
    cin>>pic_name;
    Image picture;
    picture.loadNewImage(pic_name);
    int x,y;
    cout<<"Enter the new width of image: \n";
    cin>>x;
    cout<<"Enter the new height of image: \n";
    cin>>y;
    Image resized(x,y);
    for(int i=0;i<resized.width;i++) {
        for(int j=0;j<resized.height;j++) {
            for(int k=0;k<3;k++) {
                int newx = round(i*(picture.width/x));
                int newy = round(j*(picture.height/y));
                resized(i,j,k)=picture(newx,newy,k);
            }
        }
    }
    string new_name;
    cout<<"Enter the new name: ";
    cin>>new_name;
    resized.saveImage(new_name);

}
/////////////////////////////////////////////////
void skew() {
    cout << "Enter image name + extension: ";
    string pic_name;
    cin >> pic_name;

    Image picture;
    picture.loadNewImage(pic_name);

    int angle;
    cout << "Enter the angle of skewness: ";
    cin >> angle;
    double radangle = M_PI / 180.0 * angle;
    int shift = tan(radangle) * picture.height;
    int new_w = picture.width + abs(shift);
    Image skewed(new_w, picture.height);

    for(int i=0;i<skewed.width;i++) {

        for(int j=0;j<skewed.height;j++) {
                for (int k = 0; k < 3; k++) {
                    skewed(i, j, k) =255;
                }
        }
    }

    for(int i=0;i<picture.width;i++) {

        for(int j=0;j<picture.height;j++) {

            int newx = i + abs ( tan(radangle)*(picture.height-j));
            if (newx >= 0 && newx < new_w) {

                for (int k = 0; k < 3; k++) {
                    skewed(newx, j, k) = picture(i, j, k);
                }
            }
        }
    }

    string new_name;
    cout << "Enter the new name: ";
    cin >> new_name;
    skewed.saveImage(new_name);

}

///////////////////////////////////////////////////////
void sunFixation() {
    cout << "Enter image name + extension: ";
    string pic_name;
    cin >> pic_name;

    Image picture;
    picture.loadNewImage(pic_name);


    for(int i=0;i<picture.width;i++) {

        for(int j=0;j<picture.height;j++) {
            if(picture(i,j,0) + 30 <= 255){
            picture(i,j,0) += 30;
            }
            if(picture(i,j,1) + 15 <= 255){
                picture(i,j,1) += 15 ;
            }
            if(picture(i,j,2) - 20 >= 0){
                picture(i,j,2) -= 20 ;
            }


        }
    }

    string new_name;
    cout << "Enter the new name: ";
    cin >> new_name;
  picture.saveImage(new_name);

}
//////////////////////////////////////////////////////////////////////
void cold() {
    cout << "Enter image name + extension: ";
    string pic_name;
    cin >> pic_name;

    Image picture;
    picture.loadNewImage(pic_name);


    for(int i = 0; i < picture.width; i++ ) {

        for(int j=0 ; j < picture.height ;j++ ) {
            if(picture(i,j,0) -25 >= 0 ){
                picture(i,j,0) -= 25 ;
            }
            if(picture(i,j,1) -10 >= 0 ){
                picture(i,j,1) -= 15;
            }
            if(picture(i,j,2) + 30 <= 255){
                picture(i,j,2) += 30;
            }


        }
    }

    string new_name;
    cout << "Enter the new name: ";
    cin >> new_name;
    picture.saveImage(new_name);

}


int main() {
    return 0;
}


