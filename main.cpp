#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

void openPicture();
void savePicture();
void pictureFilter();
void blackWhite();
void invert();
void _merge();
void flip();
void _rotate();
void darkenLighten();
void detectEdges();
void enlarge();
void shrink();
void mirror();
void shuffle();
void blur();

unsigned char image[SIZE][SIZE][RGB];


int main()
{
    cout << "Please enter file name of the image to process: "<< endl;
    openPicture();
    while(true){
        cout << "Please select a filter to apply or 0 to exit: " << endl;
        cout << "1- Black & White Filter" << endl;
        cout << "2- Invert Filter" << endl;
        cout << "3- Merge Filter" << endl;
        cout << "4- Flip Image" << endl;
        cout << "5- Rotate Image" << endl;
        cout << "6- Darken and Lighten Image" << endl;
        cout << "7- Detect Image Edges" << endl;
        cout << "8- Enlarge Image" << endl;
        cout << "9- Shrink Image" << endl;
        cout << "a- Mirror 1/2 Image" << endl;
        cout << "b- Shuffle Image" << endl;
        cout << "c- Blur Image" << endl;
        cout << "s- Save the image to a file" << endl;
        cout << "0- Exit" << endl;
        string userChoice;
        cin >> userChoice;
        if(userChoice == "1"){
            blackWhite();
        }
        else if(userChoice == "2"){
            invert();
        }
        else if(userChoice == "3"){
            _merge();
        }
        else if(userChoice == "4"){
            flip();
        }
        else if(userChoice == "5"){
            _rotate();
        }
        else if(userChoice == "6"){
            darkenLighten();
        }
        else if(userChoice == "7"){
            detectEdges();
        }
        else if(userChoice == "8"){
            enlarge();
        }
        else if(userChoice == "9"){
            shrink();
        }
        else if(userChoice == "a"){
            mirror();
        }
        else if(userChoice == "b"){
            shuffle();
        }
        else if(userChoice == "c"){
            blur();
        }
        else if(userChoice == "s"){
            savePicture();
        }
        else if(userChoice == "0"){
            break;
        }
    }
}
void openPicture()
{
	char imageName[100];
	cin >> imageName;
	strcat(imageName, ".bmp");
	readRGBBMP(imageName, image);
}
void savePicture()
{
	char imageName[100];
	cout << "Please enter the filtered photo name : ";
	cin >> imageName;
	strcat(imageName, ".bmp");
	writeRGBBMP(imageName, image);
}
void blackWhite(){
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            if((image[x][y][0]+image[x][y][1]+image[x][y][2]) > 381){
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = 255;
                }
            }
            else{
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = 0;
                }
            }
        }
    }
}
void invert(){

}
void _merge(){

}
void flip(){
    cout << "please choose how to flip the image\n1- horizontally\n2- vertically\n";
    int choose;
    cin >> choose;
    if(choose == 1){
        for(int x = 0; x<SIZE; x++){
            for(int y = 0; y<SIZE/2; y++){
                swap(image[x][y], image[x][255-y]);
            }
        }
    }
    else{
        for(int x = 0; x<SIZE/2; x++){
            for(int y = 0; y<SIZE; y++){
                swap(image[x][y], image[255-x][y]);
            }
        }
    }
}
void _rotate(){

}
void darkenLighten(){

}
void detectEdges(){
    bool isDifferentColor;
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            isDifferentColor = false;
            for(int z = 0; z < RGB; z++){
                if(abs(image[x][y][z] - image[x][y+1][z]) > 30 || abs(image[x][y][z] - image[x+1][y][z]) > 30){
                    isDifferentColor = true;
                }
            }
            if(isDifferentColor){
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = 0;
                }
            }
            else{
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = 255;
                }
            }
        }
    }
}
void enlarge(){

}
void shrink(){

}
void mirror(){
    int startRowPixel, endRowPixel, startColumnPixel, endColumnPixel;
    int a;
    cout << "1- right \n2- left \n3- down \n4- up" << endl;
    cin >> a;
    if(a == 1){
        startRowPixel = 0;
        endRowPixel = SIZE;
        startColumnPixel = 0;
        endColumnPixel = 127;
    }
    else if(a == 2){
        startRowPixel = 0;
        endRowPixel = SIZE;
        startColumnPixel = 127;
        endColumnPixel = SIZE;
    }
    else if(a == 3){
        startRowPixel = 0;
        endRowPixel = 127;
        startColumnPixel = 0;
        endColumnPixel = SIZE;
    }
    else if(a == 4){
        startRowPixel = 127;
        endRowPixel = SIZE;
        startColumnPixel = 0;
        endColumnPixel = SIZE;
    }
    else{
        return mirror();
    }
    for(int x = startRowPixel; x<endRowPixel; x++){
        for(int y = startColumnPixel; y<endColumnPixel; y++){
            if(startRowPixel == 0 && endRowPixel == SIZE){
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = image[x][255-y][z];
                }
            }
            else{
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = image[255-x][y][z];
                }
            }
        }
    }
}
void shuffle(){

}
void blur(){

}
