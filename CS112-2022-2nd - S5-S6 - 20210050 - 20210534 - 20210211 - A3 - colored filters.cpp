// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: 12 colored filters filter.cpp
// Last Modification Date: 23/04/2022
// Author1 and ID and Group: Abdelrahman nasr aqll khalil 20210211
// Author2 and ID and Group: Adham Khalid Fahmy 20210050
// Author3 and ID and Group: ahmed mohammad ahmed 20210534
// Teaching Assistant: Eng.Hager
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
// declaring functions
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
    // selection menue loop
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
        // user choice
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
            int choice;
            cout << "please enter your choice 90 or 180 or 270 : \n";
            cin >> choice;
            //user choices for for rotation degree
            if (choice == 90)
            {
	            _rotate();
            }

	        if (choice == 180)
            {
	            _rotate();
	            _rotate();
            }
            if (choice == 270)
            {
	            _rotate();
	            _rotate();
	            _rotate();
            }
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
    // loop to convert the image to black and white 
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            if((image[x][y][0]+image[x][y][1]+image[x][y][2]) > 381){
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = 255;
                }
            }
            // to convert pixel to black
            else{
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = 0;
                }
            }
        }
    }
}
void invert(){
    // to loop on the array elements
    for (int i = 0 ; i < 256 ; i++)
    {
        for (int j = 0 ; j < 256 ; j++)
        {
            for (int c = 0 ; c < 3 ; c++)
            {
                if (image[i][j][c] == 0)
                {
                    image[i][j][c] = 255;
                }
                else if (image[i][j][c] == 255)
                {
                    image[i][j][c] = 0;
                }
                else
                {
                    image[i][j][c] = 255 - image[i][j][c];
                }
            }
        }
    }

}
void _merge(){
    // open the second image
    unsigned char image2[SIZE][SIZE][RGB];
    unsigned char new_image[SIZE][SIZE][RGB];
    cout << "Please enter the second image name:\n";
        char imageName[100];
        cin >> imageName;
        strcat(imageName, ".bmp");
        readRGBBMP(imageName, image2);


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                new_image[i][j][k]=(image[i][j][k]+image2[i][j][k])/2;
            }
        }
    }
    //save the new image
    {
        char imageName[100];
        cout << "Please enter the filtered photo name : ";
        cin >> imageName;
        strcat(imageName, ".bmp");
        writeRGBBMP(imageName, new_image);
    }
}
void flip(){
    // enter the user choice for darken lighten
    cout << "please choose how to flip the image\n1- horizontally\n2- vertically\n";
    int choose;
    cin >> choose;
    if(choose == 1){
        // swap the first element to the last element an so on verticaly
        for(int x = 0; x<SIZE; x++){
            for(int y = 0; y<SIZE/2; y++){
                swap(image[x][y], image[x][255-y]);
            }
        }
    }
    else{
        // swap the first element to the last element an so on Horizontaly
        for(int x = 0; x<SIZE/2; x++){
            for(int y = 0; y<SIZE; y++){
                swap(image[x][y], image[255-x][y]);
            }
        }
    }
}
void _rotate(){
    // rotate the image by 90 degree
    unsigned char newImage[256][256][3];
    for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
		    for (int c = 0 ; c < 3 ; c++)
            {
                newImage[i][j][c] = image[255-j][i][c];
            }
		}
	}
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
		    for (int c = 0 ; c < 3 ; c++)
            {
                image[i][j][c] = newImage[i][j][c];

            }
		}
	}

}
void darkenLighten(){
    int choice;
    unsigned char new_image[SIZE][SIZE][RGB];
    cout << "Do you want to \n 1-Lighten \n 2-Darken\n";
    cin >> choice;
    //lighten
    if(choice==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    new_image[i][j][k]=(image[i][j][k]+255)/2;
                }
            }
        }
    }
        //darken
    else if(choice==2) {

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    new_image[i][j][k]=image[i][j][k]/2;
                }
            }
        }
    }

    else
        cout << "Please enter a valid choice\n";

    //save the new image
    {
        char imageName[100];
        cout << "Please enter the filtered photo name : ";
        cin >> imageName;
        strcat(imageName, ".bmp");
        writeRGBBMP(imageName, new_image);
    }

}
void detectEdges(){
    // drow the lines
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
            // change the colors to white
            else{
                for(int z = 0; z < RGB; z++){
                    image[x][y][z] = 255;
                }
            }
        }
    }
}
void enlarge(){
    // declare quarters
    unsigned char firstQuarter[128][128][3];
    unsigned char secondQuarter[128][128][3];
    unsigned char thirdQuarter[128][128][3];
    unsigned char fourthQuarter[128][128][3];
    int userChoice;
    // get the user choice
    cout << "Which quarter to enlarge 1, 2, 3 or 4?";
    cin >> userChoice;

    if (userChoice == 1)
    {
        // extact the first quarter
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    firstQuarter[i][j][c] = image[i][j][c];
                }
            }
        }
        // largen 
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[2*i][2*j][c] = firstQuarter[i][j][c];
                }
            }
        }
        // put the largen pixels togather
        for (int i = 0 ; i < 256 ; i++)
        {
            for (int j = 1 ; j < 256 ; j+=2)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = image[i][j-1][c];
                }
            }
        }
        for (int i = 1 ; i < 256 ; i+=2)
        {
            for (int j = 0 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = image[i-1][j][c];
                }
            }
        }

    }


    if (userChoice == 2)
    {
        // extract the quarter
        for (int i = 0; i < 128; i++)
        {
            for (int j = 128; j < 256; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    secondQuarter[i][j-128][c] = image[i][j][c];
                }
            }
        }
        // largen
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[2*i][2*j][c] = secondQuarter[i][j][c];
                }
            }
        }
        //fill the image
        for (int i = 0 ; i < 256 ; i++)
        {
            for (int j = 1 ; j < 256 ; j+=2)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = image[i][j-1][c];
                }
            }
        }
        for (int i = 1 ; i < 256 ; i+=2)
        {
            for (int j = 0 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = image[i-1][j][c];
                }
            }
        }

    }

    if (userChoice == 3)
    {
        //extract the quarters
        for (int i = 128; i < 256; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    thirdQuarter[i-128][j][c] = image[i][j][c];
                }
            }
        }
        //largen
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[2*i][2*j][c] = thirdQuarter[i][j][c];
                }
            }
        }
        //fill the image
        for (int i = 0 ; i < 256 ; i++)
        {
            for (int j = 1 ; j < 256 ; j+=2)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = image[i][j-1][c];
                }
            }
        }
        for (int i = 1 ; i < 256 ; i+=2)
        {
            for (int j = 0 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = image[i-1][j][c];
                }
            }
        }

    }

    if (userChoice == 4)
    {
        // extract the quarters
        for (int i = 128; i < 256; i++)
        {
            for (int j = 128; j < 256; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    fourthQuarter[i-128][j-128][c] = image[i][j][c];
                }
            }
        }
        //largen
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[2*i][2*j][c] = fourthQuarter[i][j][c];
                }
            }
        }
        // fiil the image
        for (int i = 0 ; i < 256 ; i++)
        {
            for (int j = 1 ; j < 256 ; j+=2)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = image[i][j-1][c];
                }
            }
        }
        for (int i = 1 ; i < 256 ; i+=2)
        {
            for (int j = 0 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = image[i-1][j][c];
                }
            }
        }

    }

}
void shrink(){
    int factor;
    // shrinking image to 1/2 and 1/3 and 1/4
    unsigned char new_image[SIZE][SIZE][RGB]={0};
    cout << "Please enter the factor to shrink the image dimensions by it :\n";
    cin >> factor;
    if (factor <= 1)
        cout << "Please enter a valid  number greater than 1\n";
    else{
        for (int i = 0; i < SIZE; i++ ){
            for (int j = 0; j< SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    new_image[i/factor][j/factor][k]=(image[i][j][k]+image[i][j+1][k]+image[i][j-1][k]+image[i-1][j][k]+image[i+1][j][k])/5;
                }
            }
        }
    }

    //save the new image
    {
        char imageName[100];
        cout << "Please enter the filtered photo name : ";
        cin >> imageName;
        strcat(imageName, ".bmp");
        writeRGBBMP(imageName, new_image);
    }
}
void mirror(){
    int startRowPixel, endRowPixel, startColumnPixel, endColumnPixel;
    int a;
    cout << "1- right \n2- left \n3- down \n4- up" << endl;
    cin >> a;
    // conditions to get the start and end points
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
    //mirror the image using the statr and end points
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
    unsigned char firstQuarter[128][128][3];
    unsigned char secondQuarter[128][128][3];
    unsigned char thirdQuarter[128][128][3];
    unsigned char fourthQuarter[128][128][3];
    int qrt1 , qrt2 , qrt3 , qrt4;
    cout << "New order of quarters ?";
    cin >> qrt1 >> qrt2 >> qrt3 >> qrt4;


     // next 4 loops to extact the image quarters
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            for (int c = 0 ; c < 3 ; c++)
            {
                firstQuarter[i][j][c] = image[i][j][c];
            }
        }
    }

    for (int i = 0; i < 128; i++)
    {
        for (int j = 128; j < 256; j++)
        {
            for (int c = 0 ; c <  3 ; c++)
            {
                secondQuarter[i][j-128][c] = image[i][j][c];
            }
        }
    }

    for (int i = 128; i < 256; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            for (int c = 0 ; c < 3 ; c++)
            {
                thirdQuarter[i-128][j][c] = image[i][j][c];
            }
        }
    }

    for (int i = 128; i < 256; i++)
    {
        for (int j = 128; j < 256; j++)
        {
            for (int c = 0 ; c < 3 ; c++)
            {
                fourthQuarter[i-128][j-128][c] = image[i][j][c];
            }
        }
    }

    // see quarter one conditions as it may be one or two or three or four
    if (qrt1 == 1)
    {
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = firstQuarter[i][j][c];
                }
            }
        }
    }

    else if (qrt1 == 2)
    {
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = secondQuarter[i][j][c];
                }
            }
        }
    }

    else if (qrt1 == 3)
    {
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = thirdQuarter[i][j][c];
                }
            }
        }
    }

    else if (qrt1 == 4)
    {
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = fourthQuarter[i][j][c];
                }
            }
        }
    }
    else
    {
        cout << "Not valid input";
    }

    // see quarter two conditions as it may be one or two or three or four
    if (qrt2 == 1)
    {
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 128 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = firstQuarter[i][j-128][c];
                }
            }
        }
    }

    else if (qrt2 == 2)
    {
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 128 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = secondQuarter[i][j-128][c];
                }
            }
        }
    }

    else if (qrt2 == 3)
    {
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 128 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = thirdQuarter[i][j-128][c];
                }
            }
        }
    }

    else if (qrt2 == 4)
    {
        for (int i = 0 ; i < 128 ; i++)
        {
            for (int j = 128 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = fourthQuarter[i][j-128][c];
                }
            }
        }
    }
    else
    {
        cout << "Not valid input";
    }
    // see quarter three conditions as it may be one or two or three or four
    if (qrt3 == 1)
    {
        for (int i = 128 ; i < 256 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = firstQuarter[i-128][j][c];
                }
            }
        }
    }

    else if (qrt3 == 2)
    {
        for (int i = 128 ; i < 256 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = secondQuarter[i-128][j][c];
                }
            }
        }
    }

    else if (qrt3 == 3)
    {
        for (int i = 128 ; i < 256 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = thirdQuarter[i-128][j][c];
                }
            }
        }
    }

    else if (qrt3 == 4)
    {
        for (int i = 128 ; i < 256 ; i++)
        {
            for (int j = 0 ; j < 128 ; j++)
            {
                for (int c = 0 ; c < 3 ; c++)
                {
                    image[i][j][c] = fourthQuarter[i-128][j][c];
                }
            }
        }
    }
    else
    {
        cout << "not valid input";
    }
    // see quarter four conditions as it may be one or two or three or four
    if (qrt4 == 1)
    {
        for (int i = 128 ; i < 256 ; i++)
        {
            for (int j = 128 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c ++)
                {
                    image[i][j][c] = firstQuarter[i-128][j-128][c];
                }
            }
        }
    }

    if (qrt4 == 2)
    {
        for (int i = 128 ; i < 256 ; i++)
        {
            for (int j = 128 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c ++)
                {
                    image[i][j][c] = secondQuarter[i-128][j-128][c];
                }
            }
        }
    }

    if (qrt4 == 3)
    {
        for (int i = 128 ; i < 256 ; i++)
        {
            for (int j = 128 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c ++)
                {
                    image[i][j][c] = thirdQuarter[i-128][j-128][c];
                }
            }
        }
    }

    if (qrt4 == 4)
    {
        for (int i = 128 ; i < 256 ; i++)
        {
            for (int j = 128 ; j < 256 ; j++)
            {
                for (int c = 0 ; c < 3 ; c ++)
                {
                    image[i][j][c] = fourthQuarter[i-128][j-128][c];
                }
            }
        }
    }
    else
    {
        cout << "Not valid input";
    }

}
void blur(){
    unsigned char new_image[SIZE][SIZE][RGB];
    // declare pixels average
    int pixels_average1;
    int pixels_average2;
    int pixels_average3;
    for (int i = 0; i < SIZE; i++ ){
        for (int j = 0; j< SIZE; j++) {
            // bluring the image

            pixels_average1 = (image[i][j][0]+image[i][j-1][0]+image[i][j-2][0]+image[i][j+1][0]+image[i][j+2][0]+image[i-1][j][0]+image[i-1][j-1][0]+image[i-1][j-2][0]+image[i-1][j+1][0]+image[i-1][j+2][0]+image[i-2][j][0]+image[i-2][j-1][0]+image[i-2][j-2][0]+image[i-2][j+1][0]+image[i-2][j+2][0]+image[i+1][j][0]+image[i+1][j-1][0]+image[i+1][j-2][0]+image[i+1][j+1][0]+image[i+1][j+2][0]+image[i+2][j][0]+image[i+2][j-1][0]+image[i+2][j-2][0]+image[i+2][j+1][0]+image[i+2][j+2][0])/25;
            pixels_average2 = (image[i][j][1]+image[i][j-1][1]+image[i][j-2][1]+image[i][j+1][1]+image[i][j+2][1]+image[i-1][j][1]+image[i-1][j-1][1]+image[i-1][j-2][1]+image[i-1][j+1][1]+image[i-1][j+2][1]+image[i-2][j][1]+image[i-2][j-1][1]+image[i-2][j-2][1]+image[i-2][j+1][1]+image[i-2][j+2][1]+image[i+1][j][1]+image[i+1][j-1][1]+image[i+1][j-2][1]+image[i+1][j+1][1]+image[i+1][j+2][1]+image[i+2][j][1]+image[i+2][j-1][1]+image[i+2][j-2][1]+image[i+2][j+1][1]+image[i+2][j+2][1])/25;
            pixels_average3 = (image[i][j][2]+image[i][j-1][2]+image[i][j-2][2]+image[i][j+1][2]+image[i][j+2][2]+image[i-1][j][2]+image[i-1][j-1][2]+image[i-1][j-2][2]+image[i-1][j+1][2]+image[i-1][j+2][2]+image[i-2][j][2]+image[i-2][j-1][2]+image[i-2][j-2][2]+image[i-2][j+1][2]+image[i-2][j+2][2]+image[i+1][j][2]+image[i+1][j-1][2]+image[i+1][j-2][2]+image[i+1][j+1][2]+image[i+1][j+2][2]+image[i+2][j][2]+image[i+2][j-1][2]+image[i+2][j-2][2]+image[i+2][j+1][2]+image[i+2][j+2][2])/25;
            new_image[i][j][0]=pixels_average1;
            new_image[i][j][1]=pixels_average2;
            new_image[i][j][2]=pixels_average3;

        }
    }
    //save the new image
    {
        char imageName[100];
        cout << "Please enter the filtered photo name : ";
        cin >> imageName;
        strcat(imageName, ".bmp");
        writeRGBBMP(imageName, new_image);
    }
}
