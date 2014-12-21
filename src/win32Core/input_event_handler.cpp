#include "input_event_handler.h"

input_event_handler*                        input_event_handler::event_handler           = nullptr;
generic_linked_list<mouse_button_reciever>* input_event_handler::_mouse_button_recievers = nullptr;
generic_linked_list<mouse_click_reciever>*  input_event_handler::_mouse_click_recievers  = nullptr;
generic_linked_list<mouse_move_reciever>*   input_event_handler::_mouse_move_recievers   = nullptr;

void input_event_handler::close()
{
	if (_mouse_button_recievers)
		delete _mouse_button_recievers;

	if (_mouse_click_recievers)
		delete _mouse_click_recievers;

	if (_mouse_move_recievers)
		delete _mouse_move_recievers;

	if (event_handler)
		delete event_handler;
}

void input_event_handler::init()
{
	if (event_handler)
		event_handler = new input_event_handler();
}

void input_event_handler::enrol(mouse_click_reciever* mc_reciver)
{
	if (!_mouse_click_recievers)
		_mouse_click_recievers = new generic_linked_list<mouse_click_reciever>();

	_mouse_click_recievers->add(mc_reciver);
}

void input_event_handler::enrol(mouse_button_reciever* mb_reciver)
{
	if (!_mouse_button_recievers)
		_mouse_button_recievers = new generic_linked_list<mouse_button_reciever>();

	_mouse_button_recievers->add(mb_reciver);
}

void input_event_handler::enrol(mouse_move_reciever* mm_reciver)
{
	if (!_mouse_move_recievers)
		_mouse_move_recievers = new generic_linked_list<mouse_move_reciever>();

	_mouse_move_recievers->add(mm_reciver);
}

void input_event_handler::raise_mouse_event_click(int x_coordinate, int y_coordinate)
{
	if (_mouse_click_recievers)
	{
		bool event_handled = false;

		while (!event_handled)
		{
			mouse_click_reciever* mc_reciever = _mouse_click_recievers->get_next_pointer();

			if (!mc_reciever)
				break;

			mc_reciever->mouse_event_click(x_coordinate, y_coordinate, event_handled);
		}

		_mouse_click_recievers->reset_pointer_next();
	}
}

void input_event_handler::raise_mouse_event_left_button_down(int x_coordinate, int y_coordinate)
{
	if (_mouse_button_recievers)
	{
		bool event_handled = false;

		while (!event_handled)
		{
			mouse_button_reciever* mb_reciever = _mouse_button_recievers->get_next_pointer();

			if (!mb_reciever)
				break;

			mb_reciever->mouse_event_left_button_down(x_coordinate, y_coordinate, event_handled);
		}

		_mouse_button_recievers->reset_pointer_next();
	}
}

void input_event_handler::raise_mouse_event_left_button_up(int x_coordinate, int y_coordinate)
{
	if (_mouse_button_recievers)
	{
		bool event_handled = false;

		while (!event_handled)
		{
			mouse_button_reciever* mb_reciever = _mouse_button_recievers->get_next_pointer();

			if (!mb_reciever)
				break;

			mb_reciever->mouse_event_left_button_up(x_coordinate, y_coordinate, event_handled);
		}

		_mouse_button_recievers->reset_pointer_next();
	}
}

void input_event_handler::raise_mouse_event_move(int x_coordinate, int y_coordinate)
{
	if (_mouse_move_recievers)
	{
		bool event_handled = false;

		while (!event_handled)
		{
			mouse_move_reciever* mm_reciever = _mouse_move_recievers->get_next_pointer();

			if (!mm_reciever)
				break;

			mm_reciever->mouse_event_move(x_coordinate, y_coordinate, event_handled);
		}

		_mouse_move_recievers->reset_pointer_next();
	}
}

void input_event_handler::raise_mouse_event_right_button_down(int x_coordinate, int y_coordinate)
{
	if (_mouse_button_recievers)
	{
		bool event_handled = false;

		while (!event_handled)
		{
			mouse_button_reciever* mb_reciever = _mouse_button_recievers->get_next_pointer();

			if (!mb_reciever)
				break;

			mb_reciever->mouse_event_right_button_down(x_coordinate, y_coordinate, event_handled);
		}

		_mouse_button_recievers->reset_pointer_next();
	}
}

void input_event_handler::raise_mouse_event_right_button_up(int x_coordinate, int y_coordinate)
{
	if (_mouse_button_recievers)
	{
		bool event_handled = false;

		while (!event_handled)
		{
			mouse_button_reciever* mb_reciever = _mouse_button_recievers->get_next_pointer();

			if (!mb_reciever)
				break;

			mb_reciever->mouse_event_right_button_up(x_coordinate, y_coordinate, event_handled);
		}

		_mouse_button_recievers->reset_pointer_next();
	}
}

void input_event_handler::withdraw(mouse_button_reciever* mb_reciever)
{
	if (_mouse_button_recievers)
	{
		_mouse_button_recievers->remove(mb_reciever);
	}
}

void input_event_handler::withdraw(mouse_click_reciever* mc_reciever)
{
	if (_mouse_click_recievers)
	{
		_mouse_click_recievers->remove(mc_reciever);
	}
}

void input_event_handler::withdraw(mouse_move_reciever* mm_reciever)
{
	if (_mouse_move_recievers)
	{
		_mouse_move_recievers->remove(mm_reciever);
	}
}