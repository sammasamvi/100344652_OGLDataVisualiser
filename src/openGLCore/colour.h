#ifndef COLOUR_H
#define COLOUR_H

#include "enums\eColour.h"

class colour final
{
    private:
		int _alpha;
		int _blue;
		int _green;
		int _red;

		void set_value(eColour colour, const int& value);
    public:
		colour();
		colour(int red, int green, int blue);
		colour(int red, int green, int blue, int alpha);
		colour(const colour& original);

		const int* get_alpha();
		const int* get_blue();
		const int* get_green();
		const int* get_red();

		float get_colour_channel(eColour colour);
};

#endif