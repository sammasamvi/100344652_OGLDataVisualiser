#ifndef COLOUR_H
#define COLOUR_H

#include "EColour.h"

// An immutable class for representing colour
// Each primary colour value is represented as an intager between 0 and 255
class Colour
{
private:
	int _red;
	int _green;
	int _blue;

	// ensures that any value below 0 is represented as 0 and beyond 255 is represented as 255
	int boundInputVal(int value);

public:
	Colour();
	Colour(int red, int green, int blue);

	// returns an int between 0 and 255 describing the input colour param contained in this instance.
	int   getColourVal(EColour colour)    const;
	
	//returns a float between 0.0f and 1.0f describing the input colour param contained in this instance.
	float getOGLColourVal(EColour colour) const;
};

#endif