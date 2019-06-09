#include <stdio.h>
#include <string.h>
#include "Word.h"

// Sample Colors defined for ease of use
#define RED Color(255, 0, 0)
#define BLACK Color(0, 0, 0)
#define BLUE Color(0, 0, 255)
#define GREEN Color(0, 255, 0)
#define WHITE Color(255, 255, 255)

int main(int argc, char** argv)
{
	char inputstr[40];
	FILE* fp = fopen("name.ppm","w");
	printf("Input Text:\n");
	scanf ("%39s",inputstr);
	Word p(inputstr, WHITE, RED); // White Foreground and Blue Background
	p.Render(fp); // Write the Text onto the PPM File
	return 0;
}