#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "PPM.h"

using namespace std;

bool checkInput(string); //checks if the input is valid
string convertCase(string); //converts the input to uppercase if it is lowercase

int main(int argc, char* argv[])
{
    string input;
    cout << "Enter your name: " << endl;
    getline(cin, input);
    if (!checkInput(input))
    {
        cout << "Input text is not valid." << endl;
        return 0;
    }
    input = convertCase(input);
    PPM* img = nullptr;
    img = new PPM(input.length()*6,8); //initialize a new PPM image object
    img->SetFontColor(255, 255, 255); //set font color to white
    img->SetBGColor(0, 0, 0); //set background color to black
    img->DrawImage(input,"picture.ppm");
    return 0;
}

bool checkInput(string input)
{
    if (input.length() > 24) //check input length
    {
        return false;
    }
    for (unsigned int i = 0; i < input.length(); i++) //check for white space and alphabets
    {
        if ((input[i] >= 65 && input[i] <= 90) || (input[i] >=97 && input[i] <= 122))
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

string convertCase(string text)
{
    for (unsigned int i = 0; i < text.length(); i++)
    {
        char chr = text[i];
        if (islower(chr))
        {
            text[i] = toupper(chr);
        }
    }
    return text;
}
