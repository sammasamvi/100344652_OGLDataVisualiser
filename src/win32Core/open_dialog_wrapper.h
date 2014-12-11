#ifndef OPEN_DIALOG_WRAPPER_H
#define OPEN_DIALOG_WRAPPER_H

#include <Windows.h>

class open_dialog_wrapper final
{
private:
	char* _filters;
	char  _path[MAX_PATH + 1];
	char* _starting_directory;
	bool  _struct_vars_filled;
	HWND* _window_handle;

	void fill_struct_vals();
public:
	OPENFILENAME  _dialog_struct;

	open_dialog_wrapper(HWND& window_handle);
	~open_dialog_wrapper();

	bool    open();
	HANDLE get_file_handle();
	void    set_filters(char* filters, size_t buffer_size);
	void    set_initial_directory(const char& path);
};

#endif