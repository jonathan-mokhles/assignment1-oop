// FCAI – OOP Programming – 2023 - Assignment 1 

//AHMED MOHAMED AHMED >> asadq265@gmail.com >> 20210029
//JONATHAN MOKHLES >> jonathanmokhles@gmail.com >> 20220100
//AHMED RIZQ MOHAMED >> arizq9941@gmail.com >> 20210017

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char new_image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char pic[SIZE][SIZE][RGB];
unsigned char new_image2[SIZE][SIZE][RGB];
int x,y;

void loadImage ();
void loadImageformerge ();
void saveImage ();
void saveImagefornew ();
void saveImagefornew2 ();
void BlackandWhite ();
void InvertImage ();
void MergeImage ();
void FlipImage ();
void RotateImage ();
void DarkenandLighten();
void EnlargeImage();
void ShrinkImage();
void getpic ();
void returnpic ();
void hlmirror ();
void hrmirror();
void vlmirror();
void vrmirror();
void ShuffleImage();
void BlurImage ();
void DetectImage();
void Crop_Image();
int main() {
    while(true) {
        char operation;
        cout << "\nPlease select a filter to apply or 0 to exit:\n" << endl;
        cout << "1- Black & White Filter" << endl;
        cout << "2- Invert Filter" << endl;
        cout << "3- Merge Filter" << endl;
        cout << "4- Flip Image" << endl;
        cout << "5- Darken and Lighten Image" << endl;
        cout << "6- Rotate Image" << endl;
        cout << "7- Detect Image Edges" << endl;
        cout << "8- Enlarge Image" << endl;
        cout << "9- Shrink Image" << endl;
        cout << "a- Mirror 1/2 Image" << endl;
        cout << "b- Shuffle Image" << endl;
        cout << "c- Blur Image" << endl;
        cout << "d- Crop Image" << endl;
        cout << "0- Exit\n" << endl;
        cin >> operation;
        if (operation == '1') {
            loadImage();
            BlackandWhite();
            saveImage();
        }
        else if (operation == '2') {
            loadImage();
            InvertImage();
            saveImage();
        }
        else if (operation == '3') {
            loadImageformerge();
            MergeImage();
            saveImagefornew();
        }
        else if (operation == '4') {
            loadImage();
            FlipImage();
            saveImagefornew();
        }
        else if (operation == '5') {
            loadImage();
            DarkenandLighten();
            saveImagefornew();
        }
        else if (operation == '6') {
            loadImage();
            RotateImage();
            saveImagefornew();
        } else if (operation == '7') {
            loadImage();
            DetectImage();
            saveImage();
        } else if (operation == '8') {
            loadImage();
            EnlargeImage();
            saveImagefornew();
        } else if (operation == '9') {
            loadImage();
            ShrinkImage();
            saveImagefornew2();
        }
        else if (operation == 'a') {
            int choise;
            bool check = true;
            cout<<" 1-Horizontal right mirror \n 2-Horizontal left mirror \n 3-Vertical up mirror \n 4-Vertical down mirror \n Enter your choice here : ";
            cin>>choise;
            getpic();
            if(choise==1){
                hlmirror();
            }
            else if (choise==2)
            {
                hrmirror();
            }
            else if (choise==3)
            {
                vlmirror();
            }
            else if (choise==4)
            {
                vrmirror();
            }
            returnpic();
        }
        else if (operation == 'b') {
            loadImage();
            ShuffleImage();
            saveImagefornew();
        }
        else if (operation == 'c') {
            loadImage();
            BlurImage();
            saveImage();
        }
        else if (operation == 'd') {
            cout <<"enter x : ";
            cin >>x;
            cout <<"enter y : ";
            cin >>y;
            loadImage();
            Crop_Image();
            saveImage();
        }
        else if(operation=='s'){

        }
        else if (operation == '0')
            break;
    }
}
//_____
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
//_____
void loadImageformerge () {
    char imageFileName[100],imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    cout << "Enter the source new_image file name: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
    strcat (imageFileName2, ".bmp");
    readRGBBMP(imageFileName2, image2);
}

//_____
void saveImage () {

    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
//_____
void saveImagefornew () {
    char imageFileName[100],imageFileName2[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, new_image);

}
void saveImagefornew2 () {
    char imageFileName[100],imageFileName2[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, new_image2);

}



void BlackandWhite (){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int a=0; a<RGB; a++){


                if (image[i][j][1] > 127){
                    image[i][j][1] = 255;
                }
                else{
                    image[i][j][1] = 0;
                }
                if (image[i][j][2] > 127){
                    image[i][j][2] = 255;
                }
                else{
                    image[i][j][2] = 0;
                }
                if (image[i][j][0] > 127){
                    image[i][j][0] = 255;
                }
                else{
                    image[i][j][0] = 0;
                }
                if((image[i][j][1]==0 && image[i][j][2]==0)||(image[i][j][2]==0 && image[i][j][0]==0)||(image[i][j][0]==0 && image[i][j][1]==0)){
                    image[i][j][a]=0;
                }
                else {
                    image[i][j][a]=255;
                }
            }
        }
    }
}
//_____
void InvertImage () {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int a=0; a<RGB; a++){


                if (image[i][j][1] > 127){
                    image[i][j][1] = 255;
                }
                else{
                    image[i][j][1] = 0;
                }
                if (image[i][j][2] > 127){
                    image[i][j][2] = 255;
                }
                else{
                    image[i][j][2] = 0;
                }
                if (image[i][j][3] > 127){
                    image[i][j][3] = 255;
                }
                else{
                    image[i][j][3] = 0;
                }
                if((image[i][j][1]==0 && image[i][j][2]==0)||(image[i][j][2]==0 && image[i][j][3]==0)||(image[i][j][3]==0 && image[i][j][1]==0)){
                    image[i][j][a]=0;
                }
                else {
                    image[i][j][a]=255;
                }
                image[i][j][a]=255-image[i][j][a];
            }

        }
    }
}
//_____
void MergeImage () {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int a=0; a<RGB; a++){

                new_image[i][j][a]=(image[i][j][a]+image2[i][j][a])/2;
            }
        }
    }
}
//_____
void FlipImage (){
    int operation, num;
    bool check = true;
    cout<<"please choose what you want"<<endl;
    cout<<"1-flip the image by 180 degree enter 1"<<endl;
    cout<<"2-flip the image enter 2"<<endl;
    cin>>operation;

    if(operation==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=image[255-i][j][a];
                }
            }
        }
    }
    else if(operation==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=image[i][255-j][a];
                }
            }
        }
    }
    else{
        cin.clear();
        cin.ignore();
        cout<<"\nenter agian and correct 1 or 2 or 3 :\n ";
        FlipImage ();
    }
}
//_____
void RotateImage (){
    int operation, num;
    bool check = true;
    cout<<"please choose what you want"<<endl;
    cout<<"1-Rotate the image clockwise by 90 degree enter 1"<<endl;
    cout<<"2-Rotate the image clockwise by 180 degree enter 2"<<endl;
    cout<<"3-Rotate the image clockwise by 270 degree enter 3"<<endl;
    cin>>operation;

    if(operation==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=image[255-j][i][a];
                }
            }
        }
    }
    else if(operation==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[j][i][a]=image[255-j][255-i][a];

                }
            }
        }
    }
    else if(operation==3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=image[j][255-i][a];
                }
            }
        }
    }
    else{
        cin.clear();
        cin.ignore();
        cout<<"enter agian and correct 1 or 2 or 3 :\n ";

        RotateImage ();

    }
}
//_____
void DarkenandLighten(){
    int operation, num;
    bool check = true;
    cout<<"Please choose what you want"<<endl;
    cout<<"1-If you want darken image enter 1 "<<endl;
    cout<<"2-If you want Lighten image enter 2 "<<endl;
    cin>>operation;

    if(operation==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=(image[i][j][a])/2;
                }
            }
        }
    }
    else if(operation==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=(image[i][j][a]+255)/2;

                }
            }
        }
    }

    else{
        cin.clear();
        cin.ignore();
        cout<<"\nenter agian and correct 1 or 2 : \n ";

        void DarkenandLighten();

    }
}
//_____
void EnlargeImage(){
    int operation, num;
    bool check = true;
    cout<<"please choose what you want"<<endl;
    cout<<"enter 1 to Enlarge Image to foto1"<<endl;
    cout<<"enter 2 to Enlarge Image to foto2"<<endl;
    cout<<"enter 3 to Enlarge Image to foto3"<<endl;
    cout<<"enter 4 to Enlarge Image to foto4"<<endl;
    cin>>operation;

    if(operation==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=image[i/2][j/2][a];


                }
            }
        }

    }
    else if(operation==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=image[i/2][(j/2)+127][a];


                }
            }
        }
    }
    else if(operation==3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=image[(i/2)+127][j/2][a];


                }
            }
        }
    }
    else if(operation==4){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image[i][j][a]=image[(i/2)+127][(j/2)+127][a];


                }
            }
        }
    }
    else{
        cin.clear();
        cin.ignore();
        cout<<"enter agian and correct 1 or 2 or 3 : \n ";

        void EnlargeImage();

    }
}
//_____
void ShrinkImage(){
    int operation, num;
    cout<<"please choose what you want"<<endl;
    cout<<"enter 1 to shrink the image to 1/2"<<endl;
    cout<<"enter 2 to shrink the image to 1/3"<<endl;
    cout<<"enter 3 to shrink the image to 1/4"<<endl;
    cin>>operation;

    if(operation==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image2[i/2][j/2][a]=image[i][j][a];


                }
            }
        }

    }
    else if(operation==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image2[i/3][j/3][a]=image[i][j][a];


                }
            }
        }
    }
    else if(operation==3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int a = 0; a< RGB; a++) {
                    new_image2[i/4][j/4][a]=image[i][j][a];


                }
            }
        }
    }
    else{
        cin.clear();
        cin.ignore();
        cout<<"enter agian and correct 1 or 2 or 3 : \n ";

        ShrinkImage();

    }
}
//_________
void getpic () {
    char userpic[100];

    cout << "Enter the source image file name: ";
    cin >> userpic;

    strcat (userpic, ".bmp");
    readRGBBMP(userpic, pic);
}

void returnpic () {
    char userpic[100];

    cout << "Enter the target image file name: ";
    cin >> userpic;

    strcat (userpic, ".bmp");
    writeRGBBMP(userpic, pic);
}

void hlmirror() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< (SIZE+1)/2; j++) {
            for (int k = 0; k < RGB; k++)
            {
                pic[i][j][k]=pic[i][-j][k];
            }
        }
    }
}

void hrmirror() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< (SIZE+1)/2; j++) {
            for (int k = 0; k < RGB; k++)
            {
                pic[i][-j][k]=pic[i][j][k];
            }

        }
    }
}

void vlmirror() {
    for (int i = 0; i < (SIZE+1)/2; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < RGB; k++)
            {
                pic[255-i][j][k]=pic[i][j][k];
            }
        }
    }
}

void vrmirror() {
    for (int i = 0; i < (SIZE+1)/2; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < RGB; k++)
            {
                pic[i][j][k]=pic[255-i][j][k];
            }
        }
    }
}


//_____
void ShuffleImage(){
    int q1,q2,q3,q4;
    cout<<"Enter the first num: ";
    cin >> q1;
    if (q1==1){
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j< 127; j++) {
                for(int a=0 ; a<RGB;a++){

                    new_image[i][j][a]=image[i][j][a];

                }
            }
        }
    }
    else if (q1==2){
        for (int i = 0; i < 127; i++) {
            for (int j = 127; j< SIZE; j++) {
                for(int a=0 ; a<RGB;a++){
                    new_image[i][j-127][a]=image[i][j][a];
                }

            }
        }
    }
    else if (q1==3){
        for (int i = 127; i < SIZE; i++) {
            for (int j = 0; j< 127; j++) {
                for(int a=0 ; a<RGB;a++){
                    new_image[i-127][j][a]=image[i][j][a];
                }

            }
        }
    }
    else if (q1==4){
        for (int i = 127; i < SIZE; i++) {
            for (int j = 127; j< SIZE; j++) {
                for(int a=0 ; a<RGB;a++){

                    new_image[i-127][j-127][a]=image[i][j][a];
                }
            }
        }
    }


    cout<<"Enter the Second num: ";
    cin>>q2;

    if (q2==1){
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j< 127; j++) {
                for(int a=0 ; a<RGB;a++){

                    new_image[i][j+127][a]=image[i][j][a];
                }

            }
        }
    }
    else if (q2==2){
        for (int i = 0; i < 127; i++) {
            for (int j = 127; j< SIZE; j++) {
                for(int a=0 ; a<RGB;a++){

                    new_image[i][j][a]=image[i][j][a];
                }

            }
        }
    }else if (q2==3){
        for (int i = 127; i < SIZE; i++) {
            for (int j = 0; j< 127; j++) {
                for(int a=0 ; a<RGB;a++){
                    new_image[i-127][j+127][a]=image[i][j][a];

                }
            }
        }
    }else if (q2==4){
        for (int i = 127; i < SIZE; i++) {
            for (int j = 127; j< SIZE; j++) {
                for(int a=0 ; a<RGB;a++){

                    new_image[i-127][j][a]=image[i][j][a];

                }
            }
        }
    }
    cout<<"Enter the Third num: ";
    cin>>q3;

    if (q3==1){
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j< 127; j++) {
                for(int a=0 ; a<RGB;a++){

                    new_image[i+127][j][a]=image[i][j][a];
                }

            }
        }
    }else if (q3==2){
        for (int i = 0; i < 127; i++) {
            for (int j =127; j< SIZE; j++) {
                for(int a=0 ; a<RGB;a++){

                    new_image[i+127][j-127][a]=image[i][j][a];

                }
            }
        }
    }else if (q3==3){
        for (int i = 127; i < SIZE; i++) {
            for (int j = 0; j< 127; j++) {
                for(int a=0 ; a<RGB;a++){
                    new_image[i][j][a]=image[i][j][a];
                }

            }
        }
    }else if (q3==4){
        for (int i = 127; i < SIZE; i++) {
            for (int j = 127; j< SIZE; j++) {
                for(int a=0 ; a<RGB;a++){

                    new_image[i][j-127][a]=image[i][j][a];
                }

            }
        }
    }
    cout<<"Enter the Fourth num: ";
    cin>>q4;

    if (q4==1){
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j< 127; j++) {
                for(int a=0 ; a<RGB;a++){
                    new_image[i+127][j+127][a]=image[i][j][a];
                }

            }
        }
    }else if (q4==2){
        for (int i = 0; i < 127; i++) {
            for (int j = 127; j< SIZE; j++) {
                for(int a=0 ; a<RGB;a++){
                    new_image[i+127][j][a]=image[i][j][a];

                }
            }
        }
    }else if (q4==3){
        for (int i = 127; i < SIZE; i++) {
            for (int j = 0; j< 127; j++) {
                for(int a=0 ; a<RGB;a++){
                    new_image[i][j+127][a]=image[i][j][a];
                }
            }
        }
    }
    else if (q4==4){
        for (int i = 127; i < SIZE; i++) {
            for (int j = 127; j< SIZE; j++) {
                for(int a=0 ; a<RGB;a++){
                    new_image[i][j][a]=image[i][j][a];
                }
            }
        }
    }

}
//_____
void BlurImage () {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int a=0; a<RGB; a++){
                image[i][j][a]=(image[i][j][a]+ image[i+1][j][a]+ image[i-1][j][a]+ image[i-1][j-1][a]+ image[i][j+1][a]+image[i][j-1][a]+image[i+1][j+1][a]+image[i+1][j-1][a]+image[i-1][j+1][a]+image[i+2][j+2][a]+image[i+2][j][a]+image[i][j+2][a]+image[i-2][j][a]+image[i][j-2][a]+image[i+2][j-2][a]+image[i-2][j+2][a])/16;
            }
        }
    }

// do Blur to the image

}
//_____
void DetectImage() {
    for (int r = 0; r < 255; r++) {
        for (int c = 0; c < SIZE; c++) {
            for (int k = 0; k < RGB; k++) {

                if (abs(image[r][c][k] - image[r][c + 1][k] > 25)) {

                    image[r][c][0] = image[r][c][1] = image[r][c][2] = 0;

                } else {
                    image[r][c][0] = image[r][c][1] = image[r][c][2] = 255;
                }
            }
        }
    }
}

//_____
void Crop_Image() {
  for (int i = x; i < SIZE; i++) {
    for (int j = 0; j< y; j++) {
        for(int a=0 ; a<RGB;a++){  
            image[i][j][a] = 255;
        }
    }
  }
    for (int i = 0; i < x; i++) {
    for (int j = y; j< SIZE; j++) {
        for(int a=0 ; a<RGB;a++){  
            image[i][j][a] = 255;
        }
    }
  }
  for (int i = SIZE-x; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for(int a=0; a<RGB; a++){    
            image[i][j][a] = 255;
        }
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = SIZE-y; j< SIZE; j++) {
        for(int a=0 ; a<RGB;a++){
            image[i][j][a] = 255;
        }
    }
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j< y; j++) {
        for(int a=0 ; a<RGB;a++){  
            image[i][j][a] = 255;
        }
    }
  }
  for (int i = x; i < SIZE-y; i++) {
    for (int j = y; j< SIZE-x; j++) {
        for(int a=0 ; a<RGB;a++){
            image[i][j][a];
        }
    }
  }
}
