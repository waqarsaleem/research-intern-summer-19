#include <stdio.h>
#include <string.h>
#include "AlphaMap.h"
#include <time.h>
#include <stdlib.h>

struct Color
{
	Color(int R, int G, int B)
	{
		this->r = R % 256;
		this->g = G % 256;
		this->b = B % 256;
	}
	Color()
	{
        this->r = 0;
		this->g = 0;
		this->b = 0;
	}
	int r = 0;
	int g = 0;
	int b = 0;
};

// Each Character is to be 50 by 30 pixels in dimensions
class Word
{
public:
	Word(char* Name, Color fg, Color bg)
	{
		name = Name;
		color.r = fg.r;
		color.g = fg.g;
		color.b = fg.b;
		bgColor.r = bg.r;
		bgColor.g = bg.g;
		bgColor.b = bg.b;
	}
	void Render(FILE* outputfile){
		if (outputfile != NULL)
		{
		    for (int k = 0; k < 50; k++)
            {
                for (int i = 0; i < 7 * 2; i++) {
                    fprintf(outputfile, "%d %d %d ", bgColor.r, bgColor.g, bgColor.b);
                }

                for (int j = 0; j < strlen(name); j++)
                {
                    for (int i = 0; i < 57; i++)
                    {
                        if (name[j] == '\0') break;
                        if (alpha[name[j]-97][currentrow][i])		{fprintf(outputfile, "%d %d %d ", color.r, color.g, color.b);}
                        else if (!alpha[name[j]-97][currentrow][i])	{fprintf(outputfile, "%d %d %d ", bgColor.r, bgColor.g, bgColor.b);}
                    }
                }

                for (int i = 0; i < 7 * 2; i++) {
                    fprintf(outputfile, "%d %d %d ", bgColor.r, bgColor.g, bgColor.b);
                }

                currentrow++;
			}
			currentrow = 0;
		}
	}
	char* name;
	Color color;
	int currentrow = 0;
	Color bgColor;

};

int main(int argc, char** argv)
{
	srand(time(NULL));
	FILE* fp = fopen("name.ppm","w");
	char* toPrint = "gryphus";
	printf("%d\n", argc);
	if (argc >= 2) {toPrint = argv[1];}
	int length = strlen(toPrint);
	int pjj = length*57 + 28;
	fprintf(fp, "P3 \n%d 50 \n255\n",pjj);
	Word p(toPrint, Color(0, 0, 0), Color(255, 0, 0));
	p.Render(fp);
	return 0;
}
