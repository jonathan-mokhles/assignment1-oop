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
void DetectImageEdges(){
    for (int r = 0; i < SIZE; r++) {
        for (int c = 0; j < SIZE; c++) {

                if (abs(image[i][j] - image[i][j + 1] > 15)) {

                     image[i][j] = 0;

                } else {
                     image[i][j] = 255;
                }
            }
        }
}
void MirrorImage(){
  cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side?";
  char c;
  cin>>c;  //to choose mirror side
  int n=1;

  switch (c)
  {
  case 'l':
    for (int i = 0; i < SIZE; i++) {
      for (int j = 128; j< SIZE; j++) {
        n+=2;
       image[i][j]=image[i][j-n];
    }
    n=1;
  }
    break;
  
  case 'r':
    for (int i = 0; i < SIZE; i++) {
      for (int j =0; j< SIZE/2; j++) {

      image[i][j]=image[i][SIZE-j];
    }
  }
    break;

  case 'u':
    for (int i = 128; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
      
         image[i][j]=image[i-n][j];
    }
      n+=2;
  }
    break;

  case 'd':
        for (int i = 0; i < SIZE/2; i++) {
          for (int j =0; j< SIZE; j++) {

           image[i][j]=image[SIZE-i][j];
          }
       }
    break;
  
  default:
    break;
  }
}

void choosefilter (){ 

    int filterNumber;
 while(true){
  cout<<"Please select a filter to apply or 0 to exit:";
  cout<<"\n1- Black & White Filter \n2- Invert Filter\n3- Merge Filter \n4- Flip Image\n5- Rotate Image \n6- Darken and Lighten Image\n7- Detect Image Edges \n8- Enlarge Image\n9- Shrink Image \n10- Mirror 1/2 Image\n11- Shuffle Image\n12- Blur Image\n16- Save the image to a file\n0- Exit\n";
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
  else if (filterNumber == 7)
  {
    DetectImageEdges();
  }
  else if (filterNumber == 8)
  {
 
  }
  else if (filterNumber == 9)
  {
 
  }
  else if (filterNumber ==10 )
  {
    MirrorImage();
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
