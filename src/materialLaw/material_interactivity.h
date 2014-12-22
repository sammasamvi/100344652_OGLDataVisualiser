#ifndef MATERIAL_INTERACTIVITY_H
#define MATERIAL_INTERACTIVITY_H

#include "..\openGLCore\renderable.h"
#include "..\openGLCore\renderContext.h"
#include "..\win32Core\input_event_handler.h"
#include "peripheral_reference.h"

class material_interactivity : public mouse_button_reciever, public mouse_move_reciever
{
    private:
		static const renderContext* _context;

		renderable* _renderable;
		mouse*      _mouse;
		bool        _mouse_in_bounds;
		int         _mouse_x_coordinate;
		int         _mouse_y_coordinate;
		int         _mouse_move_offset_x;
		int         _mouse_move_offset_y;
		bool        _verify_click;

		void mouse_event_left_button_down(int x_coordinate, int y_coordinate, bool& handled);
		void mouse_event_left_button_up(int x_coordinate, int y_coordinate, bool& handled);
		void mouse_event_move(int x_coordinate, int y_coordinate, bool& handled);
		void mouse_event_right_button_down(int x_coordinate, int y_coordinate, bool& handled);
		void mouse_event_right_button_up(int x_coordinate, int y_coordinate, bool& handled);
		void set_if_mouse_in_bounds(int x_coordinate, int y_coordinate);

    protected:
		const mouse* Mouse;
		bool        _click_enabled;
		bool        _drag_enabled;
		bool        _interactivity_enabled;

		virtual void on_mouse_click();
		virtual void on_mouse_drag();
		virtual void on_mouse_left_button_down();
		virtual void on_mouse_left_button_up();
		virtual void on_mouse_move();
		virtual void on_mouse_right_button_down();
		virtual void on_mouse_right_button_up();

    public:
		static void set_render_context(const renderContext* context);

		const bool* click_enabled;
		const bool* drag_enabled;
		const bool* interactivity_enabled;
		const bool* mouse_in_bounds;

		material_interactivity(renderable* renderable);
		~material_interactivity();

		void enable_click(bool enable);
		void enable_drag(bool enable);
		void enable_interactivity(bool enable);
};

#endif