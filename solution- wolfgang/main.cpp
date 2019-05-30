#include <iostream>
#include <algorithm>
#include <IMAGE_CREATOR.h>
using namespace std;

// forward decls
bool valid_Input(string input);



int main()
{
    // to hold text
    string input_text = "";

    // getting input from console
    cout << "Please enter text: ";
    getline(cin , input_text);

    // authenticating the given input
    if ( valid_Input(input_text) == false )
    {
        return -1;
    }

    // converting input text to uppercase
    transform(input_text.begin(), input_text.end(), input_text.begin(), ::toupper);

    // creating an object of IMAGE_CREATOR
    IMAGE_CREATOR img = IMAGE_CREATOR( input_text );

    // creating image
    img.Create();

    // end
    return 0;
}


bool valid_Input(string input)
{
    // checking for length of string:
    if (input.length() > 24)
    {
        cerr << "Input should not have more than 24 characters!" << endl;
        return false;
    }

    //checking for white spaces:
    for(auto i: input)
    {
        if (i == ' ')
        {
            cout << "Input should not have white spaces!" << endl;
            return false;
        }
    }

    //checking if every character is in English alphabet:
    for(auto j: input)
    {
        int ascii = int(j);

        if ( (ascii >= 97 && ascii <= 122) || (ascii >= 65 && ascii <= 90) )
        {
            continue;
        }
        else {
            cerr << "Input must only contain english alphabets!" << endl;
            return false;
        }
    }
    // the input string matches all the criteria:
    return true;
}













































