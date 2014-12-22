#include "peripheral_reference.h"

mouse* peripheral_reference::Mouse = nullptr;

mouse* peripheral_reference::get_mosue()
{
	if (!Mouse)
	{
		Mouse = new mouse();
		
		Mouse->forward_button_down = false;
		Mouse->left_button_down    = false;
		Mouse->return_button_down  = false;
		Mouse->right_button_down   = false;
		Mouse->scroll_button_down  = false;
	}

	return Mouse;
}