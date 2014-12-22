#include "material_interactivity.h"

const renderContext* material_interactivity::_context = nullptr;

material_interactivity::material_interactivity(renderable* renderable)
{
	_click_enabled         = true;
	_drag_enabled          = true;
	_interactivity_enabled = true;
	_mouse                 = peripheral_reference::get_mosue();
	_mouse->x_coordinate   = &_mouse_x_coordinate;
	_mouse->y_coordinate   = &_mouse_y_coordinate;
	_mouse_in_bounds       = false;
	_renderable            = renderable;

	click_enabled         = &_click_enabled;
	drag_enabled          = &_drag_enabled;
	interactivity_enabled = &_interactivity_enabled;
	mouse_in_bounds       = &_mouse_in_bounds;

	input_event_handler::enrol(static_cast<mouse_button_reciever*>(this));
	input_event_handler::enrol(static_cast<mouse_move_reciever*>(this));
}

material_interactivity::~material_interactivity()
{
	input_event_handler::withdraw(static_cast<mouse_button_reciever*>(this));
	input_event_handler::withdraw(static_cast<mouse_move_reciever*>(this));
}

void material_interactivity::enable_click(bool enable)
{
	_click_enabled = enable;
}

void material_interactivity::enable_drag(bool enable)
{
	_drag_enabled = enable;
}

void material_interactivity::enable_interactivity(bool enable)
{
	_interactivity_enabled = enable;
}

void material_interactivity::mouse_event_left_button_down(int x_coordinate, int y_coordinate, bool& handled)
{
	set_if_mouse_in_bounds(x_coordinate, y_coordinate);
	on_mouse_left_button_down();

	if (_mouse_in_bounds)
	{
		_mouse_move_offset_x = _mouse_x_coordinate - _renderable->get_coordinate(X);
		_mouse_move_offset_y = _mouse_y_coordinate - _renderable->get_coordinate(Y);

		_verify_click = true;
	}

	_mouse->left_button_down = true;
	handled                  = true;
}

// Occasional click fire when mouse moves into bounds after lb_down outside bounds
void material_interactivity::mouse_event_left_button_up(int x_coordinate, int y_coordinate, bool& handled)
{
	set_if_mouse_in_bounds(x_coordinate, y_coordinate);
	on_mouse_left_button_up();

	if (_mouse_in_bounds && _verify_click)
	{
		_verify_click = false;
		on_mouse_click();
	}

	_mouse->left_button_down = false;
	handled                  = true;
}

void material_interactivity::mouse_event_move(int x_coordinate, int y_coordinate, bool& handled)
{
	if (_mouse_in_bounds && _mouse->left_button_down && _drag_enabled)
	{
		_mouse_x_coordinate = x_coordinate;
		_mouse_y_coordinate = (_context->get_dimention(Height) - y_coordinate);
		
		on_mouse_drag();
	}
	else
	{
		set_if_mouse_in_bounds(x_coordinate, y_coordinate);
		on_mouse_move();
	}
}

void material_interactivity::mouse_event_right_button_down(int x_coordinate, int y_coordinate, bool& handled)
{
	_mouse->right_button_down = true;
	set_if_mouse_in_bounds(x_coordinate, y_coordinate);
}

void material_interactivity::mouse_event_right_button_up(int x_coordinate, int y_coordinate, bool& handled)
{
	_mouse->right_button_down = false;
	set_if_mouse_in_bounds(x_coordinate, y_coordinate);
}

void material_interactivity::on_mouse_click()
{

}

void material_interactivity::on_mouse_drag()
{
	_renderable->set_coordinates((_mouse_x_coordinate - _mouse_move_offset_x),
		                         (_mouse_y_coordinate - _mouse_move_offset_y));

}

void material_interactivity::on_mouse_left_button_down()
{

}

void material_interactivity::on_mouse_left_button_up()
{

}

void material_interactivity::on_mouse_move()
{

}

void material_interactivity::on_mouse_right_button_down()
{

}

void material_interactivity::on_mouse_right_button_up()
{

}

void material_interactivity::set_if_mouse_in_bounds(int x_coordinate, int y_coordinate)
{
	if (_context)
	{
		_mouse_x_coordinate = x_coordinate;
		_mouse_y_coordinate = (_context->get_dimention(Height) - y_coordinate);

		bool within_x = false;
		bool within_y = false;

		if (_mouse_x_coordinate >= _renderable->get_coordinate(X) &&
			_mouse_x_coordinate <= (_renderable->get_coordinate(X) + _renderable->get_dimention(Width)))
			within_x = true;

		if (_mouse_y_coordinate >= _renderable->get_coordinate(Y) &&
			_mouse_y_coordinate <= (_renderable->get_coordinate(Y) + _renderable->get_dimention(Height)))
			within_y = true;

		if (within_x && within_y)
		{
			_mouse_in_bounds = true;
		}
		else
		{
			_mouse_in_bounds = false;
		}
	}
}

void material_interactivity::set_render_context(const renderContext* context)
{
	_context = context;
}