#ifndef MOUSE_BUTTON_RECIEVER_H
#define MOUSE_BUTTON_RECIEVER_H

class mouse_button_reciever
{
    public:
    	virtual void mouse_event_left_button_down(int x_coordinate, int y_coordinate, bool& handled)  = 0;
    	virtual void mouse_event_left_button_up(int x_coordinate, int y_coordinate, bool& handled)    = 0;
    	virtual void mouse_event_right_button_down(int x_coordinate, int y_coordinate, bool& handled) = 0;
    	virtual void mouse_event_right_button_up(int x_coordinate, int y_coordinate, bool& handled)   = 0;
};

#endif