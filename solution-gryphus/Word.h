#include "AlphaMap.h"
#include <ctype.h>

struct Color //Handy Color Class for coloring
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


int lower(char* Name, char* name)
{
	int length = -1;
	for (int i = 0; i < 24; i++)
	{
		if (Name[i] >= 65 && Name[i] <= 90)
		{
			name[i] = (char)(Name[i] + 32);
			length++;
		}
		else if ((Name[i] >= 97 && Name[i] <= (97+25)) || Name[i] == '\0')
		{
			name[i] = Name[i];
			length++;
			if (Name[i] == '\0') break;
		}
	}
	return length;
}

// Each Character is to be 50 by 30 pixels in dimensions
class Word
{
public:
	Word(char* Name, Color fg, Color bg)
	{
		length = lower(Name, this->name);
		color.r = fg.r;
		color.g = fg.g;
		color.b = fg.b;
		bgColor.r = bg.r;
		bgColor.g = bg.g;
		bgColor.b = bg.b;
		offset = 14;
	}
	void Render(FILE* outputfile){
		if (outputfile != NULL)
		{
			int width = length*57 + offset * 2; // Compute the total width
			fprintf(outputfile, "P3 \n%d 50 \n255\n",width);
			int filelength = 0; // For maintaining less than 70 characters per line
		    for (int k = 0; k < 50; k++)
            {
                for (int i = 0; i < offset; i++) {
                    fprintf(outputfile, "%d %d %d ", bgColor.r, bgColor.g, bgColor.b); // Give a little Space on the left
                    filelength += 12;
                    if(filelength > 58) {
                    	fprintf(outputfile, "\n"); 	// For maintaining less than 70 characters per line
                    	filelength = 0;				// This Block is used for the same purpose wherever it is in the code
                    }
                }

                for (int j = 0; j < strlen(name); j++)
                {
                	if ((name[j] >= 97 && name[j] <= (97 + 25)) || (name[j] >= 65 && name[j] <= (65 + 25)))
                	{
	                    for (int i = 0; i < 57; i++)
	                    {
	                        if (alpha[tolower(name[j])-97][currentrow][i])			// Double Check for lowercasing the input text
                        	{
                        		fprintf(outputfile, "%d %d %d ", color.r, color.g, color.b); 
                        		filelength += 12;
                				if(filelength > 58) {
                					fprintf(outputfile, "\n");
                					filelength = 0;
                				}
                			}
	                        else if (!alpha[tolower(name[j])-97][currentrow][i])	// Double Check for lowercasing the input text
                        	{
                        		fprintf(outputfile, "%d %d %d ", bgColor.r, bgColor.g, bgColor.b); 
                        		filelength += 12;
                				if(filelength > 58) {
                					fprintf(outputfile, "\n");
                					filelength = 0;
                				}
                			}
	                    }
                	}
                }

                for (int i = 0; i < offset; i++) {
                    fprintf(outputfile, "%d %d %d ", bgColor.r, bgColor.g, bgColor.b); // Give a little Space on the right
                    filelength += 12;
                    if(filelength > 58) {
                    	fprintf(outputfile, "\n");
                    	filelength = 0;
                    }
                }
                currentrow++;
			}
			currentrow = 0;
		}
	}
private:
	char name[24];
	int length;
	Color color;
	int currentrow = 0;
	Color bgColor;
	int offset;

};