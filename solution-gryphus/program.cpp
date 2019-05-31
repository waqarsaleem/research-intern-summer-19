#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	srand(time(NULL));
	int i;
	// this is the header of the ppm file
	printf("P6\n 50 50 255\n"); // width = 400, height = 400

	// image data: loops over all the pixels and sets them all to bright yellow
	for (i = 0; i < 50 * 50; i++) {
	printf("%c%c%c", 255, i % 256, 255); // g = 255, b = 255, r = 0
	}
	return 0;
}

class Color
{
public:
	Color(int R, int G, int B)
	{
		this->r = R % 256;
		this->g = G % 256;
		this->b = B % 256;
	}
	void setColor(int R = -1, int G = -1, int B = -1) // Use -1 for a color if you don't wanna change it
	{
		if (R < 256 && R > 0) this->r = R;
		if (G < 256 && G > 0) this->g = G;
		if (B < 256 && B > 0) this->b = B;
	}
private:
	int r,g,b;
};

// Each Character is to be 50 by 50 pixels in dimensions
class Character
{
public:
	static const int width = 50;
	static const int height = 50;
	Color color(255,255,255); // White by Default
	Color backgroundColor(0,0,0);	// Black by Default
};

