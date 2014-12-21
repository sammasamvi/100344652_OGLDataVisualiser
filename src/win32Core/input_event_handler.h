#ifndef INPUT_EVENT_HANDLER_h
#define INPUT_EVENT_HANDLER_h

#include "..\win32Util\generic_linked_list.h"
#include "mouse_click_reciever.h"
#include "mouse_button_reciever.h"
#include "mouse_move_reciever.h"

class input_event_handler final
{
    private:
		static generic_linked_list<mouse_button_reciever>* _mouse_button_recievers;
		static generic_linked_list<mouse_click_reciever>*  _mouse_click_recievers;
		static generic_linked_list<mouse_move_reciever>*   _mouse_move_recievers;

    public:
		static input_event_handler* event_handler;

		static void close();
		static void init();

		static void enrol(mouse_click_reciever* mc_reciever);
		static void enrol(mouse_button_reciever* mb_reciever);
		static void enrol(mouse_move_reciever* mm_reciever);
		static void withdraw(mouse_click_reciever* mc_reciever);
		static void withdraw(mouse_button_reciever* mb_reciever);
		static void withdraw(mouse_move_reciever* mm_reciever);


		void raise_mouse_event_click(int x_coordinate, int y_coordinate);
		void raise_mouse_event_left_button_down(int x_coordinate, int y_coordinate);
		void raise_mouse_event_left_button_up(int x_coordinate, int y_coordinate);
		void raise_mouse_event_move(int x_coordinate, int y_coordinate);
		void raise_mouse_event_right_button_down(int x_coordinate, int y_coordinate);
		void raise_mouse_event_right_button_up(int x_coordinate, int y_coordinate);
};

#endif