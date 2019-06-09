#include "PPM.h"
PPM::PPM()
{

}

PPM::PPM(int w, int h)
{  //initialize width & height of image
    width = w;
    height = h;
}

void PPM::SetFontColor(unsigned int r, unsigned int g, unsigned int b)
{
    red = r;
    green = g;
    blue = b;
}

void PPM::SetBGColor(unsigned int r, unsigned int g, unsigned int b)
{
    bg_red = r;
    bg_green = g;
    bg_blue = b;
}

void PPM::DrawImage(std::string text, std::string fileName)
{
    std::ofstream file(fileName); //open file
    file << "P3" << std::endl; //enter magic number for plain ppm (P3)
    file << width << " " << height << '\n';
    file << 255 << '\n';
    int n = 0, m = 0;
    std::string word;
    for (unsigned int k = 0; k < text.length(); k++)
    { //get bits for the entire text
        word += font[text[k]-32][0];
    }
    for(unsigned int i = 0; i < height; i++) //draw pixels to create image
    {
        m = n;
        for(unsigned int j = 0; j < width; j++)
        {
            //draw pixels
            if(word[n] == '1') //draw pixel of font color
            {

                file << red << " " << green << " " << blue << " ";
            }
            else //draw pixel of background color
            {
                file << bg_red << " " << bg_green << " " << bg_blue << " ";
            }
            n += 8;
        }
        file << '\n';
        n = m+1;
    }
    file.close();
}

