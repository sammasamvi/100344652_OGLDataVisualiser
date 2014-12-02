#ifndef MARGIN_H
#define MARGIN_H

#include "EMargin.h"

// an immutable class representing padding between an object in 2D space and it's container
class Margin final
{
    private:
		int _bottom;
		int _left;
		int _right;
		int _top;

    public:
		Margin();
		Margin(int left_right, int bottom_top);
		Margin(int left, int bottom, int right, int top);

		int getBottom() const;
		int getLeft()   const;
		int getRight()  const;
		int getTop()    const;
};

#endif