// FCAI – OOP Programming – 2023 - Assignment 1 

//JONATHAN MOKHLES >> jonathanmokhles@gmail.com >> 20220100
//AHMED RIZQ MOHAMED >> arizq9941@gmail.com >> 20210017
//AHMED MOHAMED AHMED >> asadq265@gmail.com >> 20210029

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];

void loadImage () {
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
void loadImage2 () {
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image2);
}
void saveImage () {
   char imageFileName[100];
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

void black_white() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;

    }
  }
}
void InvertImage() {
  for (int i = 0; i < SIZE; i++)
   {
    for (int j = 0; j< SIZE; j++) 
    {
          image[i][j]=255-image[i][j];
   }
  }
}
void MergeImage() {
  loadImage2 ();
  for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j]=(image[i][j]+image2[i][j])/2;
        }
    }
}
void flip() {
 char axis;
 cout<<"\n h or v  \n";
 cin>>axis;

 if (axis == 'h')
 {
    int temp;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE/2; j++) {

        temp=image[i][j];
        image[i][j]=image[i][256-j];
        image[i][256-j]=temp;

     }
   }
 }

   else if (axis == 'v'){
     int temp;
  for (int i = 0; i < SIZE/2; i++) {
    for (int j = 0; j< SIZE; j++) {

        temp=image[i][j];
        image[i][j]=image[256-i][j];
        image[256-i][j]=temp;

    }
  }
 }
}
void rotateimage(){
  int number;
  cout << "whate is type you want rotate it:  (90) ,(180) or (270)\n" ;
  cin>>number;
  
  for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j< SIZE; j++) {
               
                if (number ==90)
                    {
                  new_image[255-j][255-i]=image[i][255-j]; 
                    }
                   else if (number ==180)
                   {
                    new_image [255-i][255-j]=image[i][j];
                   }
                    else if (number ==270)
                    {
                        new_image[255-j][i]=image[i][j];
                    }


}
        }

  for (int i = 0; i < SIZE; i++) 
        {
  for (int j = 0; j< SIZE; j++){
   image[i][j]=new_image[i][j];
        }
    }
}
void DarkenandLighten(){
  int filter;
    cout << "If you want darker filter enter 1 \nIf you want lighter filter enter 2:  \n";
    cin >>filter;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            if(filter==1 ){
                image[i][j]=(image[i][j])/2;
            }
            else if(filter==2){
                image[i][j]=(image[i][j]+255)/2;
            }
        }
    }
}
void choosefilter (){ 

    int filterNumber;
 while(true){
  cout<<"Please select a filter to apply or 0 to exit:";
  cout<<"\n1- Black & White Filter \n2- Invert Filter\n3- Merge Filter \n4- Flip Image\n5- Rotate Image \n6- Darken and Lighten Image \n7- Save the image to a file\n0- Exit\n";
  cin>>filterNumber;
  if (filterNumber == 1)
  {
    black_white();
  }
  else if (filterNumber == 2)
  {
    InvertImage();
  }
  else if (filterNumber == 3)
  {
    MergeImage();
  }
  else if (filterNumber == 4)
  {
    flip();
  }
  else if (filterNumber == 5)
  {
    rotateimage();
  }
  else if (filterNumber == 6)
  {
    DarkenandLighten();
  }
  else
  {
    break;
  }
    }
  }

 

int main(){

  loadImage();
  choosefilter();
  saveImage();
}
