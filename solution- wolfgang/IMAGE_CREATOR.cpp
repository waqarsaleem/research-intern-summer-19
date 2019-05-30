#include "IMAGE_CREATOR.h"

IMAGE_CREATOR::IMAGE_CREATOR(string input)
{

    this->input_text = input;
    // inserting image vectors, corresponding to text, in dictionary
    for (auto i : input_text)
    {
        switch(i)
        {
        case 'A':
            dictionary['A'] = A;
            break;
        case 'B':
            dictionary['B'] = B;
            break;
        case 'C':
            dictionary['C'] = C;
            break;
        case 'D':
            dictionary['D'] = D;
            break;
        case 'E':
            dictionary['E'] = E;
            break;
        case 'F':
            dictionary['F'] = F;
            break;
        case 'G':
            dictionary['G'] = G;
            break;
        case 'H':
            dictionary['H'] = H;
            break;
        case 'I':
            dictionary['I'] = I;
            break;
        case 'J':
            dictionary['J'] = J;
            break;
        case 'K':
            dictionary['K'] = K;
            break;
        case 'L':
            dictionary['L'] = L;
            break;
        case 'M':
            dictionary['M'] = M;
            break;
        case 'N':
            dictionary['N'] = N;
            break;
        case 'O':
            dictionary['O'] = O;
            break;
        case 'P':
            dictionary['P'] = P;
            break;
        case 'Q':
            dictionary['Q'] = Q;
            break;
        case 'R':
            dictionary['R'] = R;
            break;
        case 'S':
            dictionary['S'] = S;
            break;
        case 'T':
            dictionary['T'] = T;
            break;
        case 'U':
            dictionary['U'] = U;
            break;
        case 'V':
            dictionary['V'] = V;
            break;
        case 'W':
            dictionary['W'] = W;
            break;
        case 'X':
            dictionary['X'] = X;
            break;
        case 'Y':
            dictionary['Y'] = Y;
            break;
        case 'Z':
            dictionary['Z'] = Z;
            break;
        }
    }
}


void IMAGE_CREATOR::Create()
{
    // calculating dimensions of the image
    int image_width = calculate_width();
    int image_height = A.size();

    // opening file stream
    ofstream myfile ;
    // opening file to write on
    myfile.open("Image.ppm");
    // writing the header section of the image
    myfile << "P3 \n";
    // writing the dimensions of the image
    myfile << image_width << " " << image_height << "\n";
    // writing the max value of pixel intensity
    myfile << 255 << "\n";


    // WRITING PIXEL INFORMATION
    for (int i = 0 ; i != image_height ; i++ )
    {
        for (auto j: input_text)
        {
            //writing the first row of ith character
            int length  = dictionary[j][0].size();

            for (int k = 0 ; k != length ; k++)
            {
                if (dictionary[j][i][k] == '1')
                    {myfile << 255 <<" "<< 255 << " " << 255 << " ";}

                else if ( dictionary[j][i][k] == '0' )
                    {myfile << 125 + int(1.40 * i) << " " << 71 - int(0.5 * i) << " " << 180 << " ";} // creating color gradient
            }
        }
        myfile << "\n" ;
    }
    myfile.close();
    return ;
}


int IMAGE_CREATOR::calculate_width( )
{
    int width = 0;
    for( auto i : input_text)
    {
        width += dictionary[i][0].size();
    }
    return width;
}
















