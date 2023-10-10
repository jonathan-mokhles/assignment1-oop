#include<iostream>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];

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
void loadImage () {
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);

}
void choosefilter (){ 

    int filterNumber;
    cout<<"Please select a filter to apply or 0 to exit:";
    cout<<"\n1- Black & White Filter \n2- Invert Filter\n3- Merge Filter \n4- Flip Image\n5- Darken and Lighten Image \n6- Rotate Image\n7- Detect Image Edges\n8- Enlarge Image\n9- Shrink Image\n10- Mirror 1/2 Image\n11- Shuffle Image\n12- Blur Image\n13- Crop Image\n14- Skew Image Right \n15- Skew Image Up \n16- Save the image to a file\n0- Exit\n";
    cin>>filterNumber;
  if (filterNumber == 1)
  {
    black_white();
  }
  else if (filterNumber == 2)
  {
    /* code */
  }
  else if (filterNumber == 2)
  {
    /* code */
  }
  else if (filterNumber == 4)
  {
    flip();
  }
  else
  {
    
  }
  
  }
void saveImage () {
   char imageFileName[100]="test";
//    cout << "Enter the target image file name: ";
//    cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}


int main(){

  loadImage();
  choosefilter();
  saveImage();
}