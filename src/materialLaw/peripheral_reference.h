#ifndef PERIPHERAL_REFERENCE_H
#define PERIPHERAL_REFERENCE_H

#include "..\win32Util\mouse.h"

class peripheral_reference
{
    private:
		static mouse* Mouse;
		peripheral_reference();

    public:
		static mouse* get_mosue();
};

#endif