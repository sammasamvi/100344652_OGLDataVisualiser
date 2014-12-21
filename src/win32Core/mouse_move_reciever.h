#ifndef MOUSE_MOVE_RECIEVER
#define MOUSE_MOVE_RECIEVER

class mouse_move_reciever
{
    public:
		virtual void mouse_event_move(int x_coordinate, int y_coordinate, bool& handled) = 0;
};

#endif