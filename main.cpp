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

unsigned char image[256][256];


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

}
void invert(){

}
void _merge(){

}
void flip(){

}
void _rotate(){

}
void darkenLighten(){

}
void detectEdges(){

}
void enlarge(){

}
void shrink(){

}
void mirror(){

}
void shuffle(){

}
void blur(){

}
