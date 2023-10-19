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
                  image[255-j][255-i]=image[i][255-j]; 
                    }
                   else if (number ==180)
                   {
                    image [255-i][255-j]=image[i][j];
                   }
                    else if (number ==270)
                    {
                        image[255-j][i]=image[i][j];
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
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

                if (abs(image[i][j] - image[i][j + 1] > 15)) {

                     image[i][j] = 0;

                } else {
                     image[i][j] = 255;
                }
            }
        }
}
void ShrinkImage () {
    int operation;
    cout<<"please choose what you want"<<endl;
    cout<<"enter 1 to shrink the image to 1/2"<<endl;
    cout<<"enter 2 to shrink the image to 1/3"<<endl;
    cout<<"enter 3 to shrink the image to 1/4"<<endl;
    cin>>operation;

    if(operation==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i/2][j/2]=image[i][j];
            }
        }
    }
    else if(operation==2){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i/3][j/3]=image[i][j];
            }
        }
    }
    else if(operation==3){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                image[i/4][j/4]=image[i][j];
            }
        }
    }
    else{
        cin.clear();
        cin.ignore();
        cout<<"\nenter agian and correct 1 or 2 or 3 : \n\n ";
        ShrinkImage ();
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
void BlurImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

           image[i][j] = (image[i][j]+image[i+1][j]+image[i-1][j]+image[i+1][j+1]+image[i-1][j-1]+image[i][j+1]+image[i][j-1]+image[i+1][j-1]+image[i-1][j+1]+image[i+2][j+2]+image[i+2][j]+image[i][j+2]+image[i-2][j]+image[i][j-2]+image[i+2][j-2]+image[i-2][j+2])/16;
        }
    }
}
void CropImage(){
      cout<<"Please enter x y l w: ";
   int x,y,l,w;
   cin>>x>>y>>l>>w;
      for (int i = y; i < l+y; i++) {
        for (int j = x; j < w+x; j++) {

           new_image[i][j]=image[i][j];
        }
    }
    //copying the image to "image" arry to save it
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

           image[i][j]=new_image[i][j];
        }
    }
}
void WhitePicture () {
           for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

          new_image[i][j]=255;
        }
    }
}
void Skew_Horizontally() {

  int x=256;
  for (int i = 0; i < SIZE; i++) {
    x--;
    for (int j = 0; j< SIZE; j++) {
       
      image[i][(j+x)/2] = image[i][j];
    }
  }
  int num=0;
  for (int i = 0; i < SIZE; i++) {
    if (i%2){num +=1;}
    for (int j = 0; j< (126-num); j++) {
    
      image[i][j] = 256;
    }
  }
  num=0;
  for (int i = 0; i < SIZE; i++) {
    if (i%2){num +=1;}
    for (int j = (SIZE-num); j< SIZE; j++) {
    
      image[i][j] = 256;
    }
  }
}
void moveing (int quarter, int i, int j)
{

    int temp = j;
   cin>> quarter;
    if (quarter==1)
        for (int k=0; k < SIZE/2; i++,k++)
        {
            j=temp;
            for(int z=0; z<SIZE/2; j++,z++)
            image[i][j]=image[k][z];
        }
        
            else if (quarter==2)

                for(int k=0; k<SIZE/2;i++,k++)
                {
                    j=temp;
                for(int z=0; z<SIZE/2; j++, z++) 
                image[i][j]=image[k][z];

                }
                else if (quarter==3)

                for(int k=0; k<SIZE/2; i++, k++)
                {
                    j=temp;
                    for(int z=0; z<SIZE/2; j++, z++)
                    image[i][j]=image[k][z];
                }
                else if (quarter==4)

                for(int k=0; k<SIZE/2; i++, k++)
                {
                    j=temp;
                    for(int z=0; z<SIZE/2; j++, z++)
                    image[i][j]=image[k][z];
                }
                
}

void shuffelimage()
{
    int n;
    cout<<"please enter the quarter: \n";
    for(int i=0; i<4; i++)
    {
         cin>> n;
         if (i==0)
            moveing(n,0,0);
         else if (i==1)
            moveing (n,0,SIZE/2) ;
         else if (i==2)
            moveing (n,SIZE/2,0);
         else if (i==3)
            moveing (n,SIZE/2,SIZE/2);                 
    }
   


}

void enlargimage ()
{
    int n;
    cout<< "please enter whate is your qyarter you want enlarge \n";
    cin>> n;
    for(int i=0 ;i<SIZE;i++)
    {
        for(int j=0; j<SIZE; j++)
        {
         
           if (n==1)
           {
                image[i][j]=image[i/2][j/2];
           }
            
            else if (n==2)
            {
            image[i][j]=image[i/2][SIZE/2 + j/2];
            }
            else if (i==3)
            {
            image[i][j]=image[SIZE/2 + i/2][j/2] ;   
            }
            else if (i==4)
            {
            image[i][j]=image[SIZE/2 + i/2][SIZE/2 + j/2];
            }

        }

        
    }



}

double skewhorizontalh ()
{
    char h=1;
    cout<<"please enter whate do you want we skew your new_image \n";
    cin>> h;
    if (h==1)
    {
       for(int i=0; i<SIZE;i++)
       {
         for(int j=0; j<SIZE;j++)
        
            image[i][(SIZE/2)+j-i]=image[i][j];
       }
    }
    else
    {
        h!=1;
        cout<<"please check whate you enter \n"; 
    }
    
    
}
void choosefilter (){ 

    int filterNumber;
 while(true){
  cout<<"Please select a filter to apply or 0 to exit:";
  cout<<"\n1- Black & White Filter \n2- Invert Filter\n3- Merge Filter \n4- Flip Image\n5- Rotate Image \n6- Darken and Lighten Image\n7- Detect Image Edges \n8- Enlarge Image\n9- Shrink Image \n10- Mirror 1/2 Image\n11- Shuffle Image\n12- Blur Image\n13- Crop Image\n14-e- Skew Image Right  \n15- f- Skew Image Up  \n16- Save the image to a file\n0- Exit\n";
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
   enlargimage();
  }
  else if (filterNumber == 9)
  {
    ShrinkImage ();
  }
  else if (filterNumber ==10 )
  {
    MirrorImage();
  }
  else if (filterNumber ==11 )
  {
  
   shuffelimage();
  }
  else if (filterNumber ==12 )
  {
      BlurImage();
  }
  else if (filterNumber ==13 )
  {
    WhitePicture();
    CropImage();
  }
  else if (filterNumber ==14 )
  {
     skewhorizontalh();
  }
   else if (filterNumber ==15 )
  {
     Skew_Horizontally();
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
