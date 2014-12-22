#ifndef WIN32_UTIL_MOUSE_H
#define WIN32_UTIL_MOUSE_H

struct mouse
{
	bool forward_button_down;
	bool left_button_down;
	bool return_button_down;
	bool right_button_down;
	bool scroll_button_down;
	int* x_coordinate;
	int* y_coordinate;
};

#endif