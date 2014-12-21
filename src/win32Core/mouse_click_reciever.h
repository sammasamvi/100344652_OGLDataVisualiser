#ifndef MOUSE_CLICK_RECIEVER_H
#define MOUSE_CLICK_RECIEVER_H

class mouse_click_reciever
{
    public:
    	virtual void mouse_event_click(int x_coordinate, int y_coordinate, bool& handled) = 0;
};

#endif