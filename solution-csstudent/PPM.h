#ifndef PPM_H_INCLUDED
#define PPM_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include "font.h"

class PPM
{
    public:
        PPM();
        PPM(int w, int h);
        void DrawImage(std::string text, std::string fileName);
        void SetFontColor(unsigned int r, unsigned int g, unsigned int b);
        void SetBGColor(unsigned int r, unsigned int g, unsigned int b);

    private:
        unsigned int width, height;
        unsigned int red, green, blue;
        unsigned int bg_red, bg_green, bg_blue;

};

#endif // PPM_H_INCLUDED
