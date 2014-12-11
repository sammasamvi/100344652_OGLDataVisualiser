#include "open_dialog_wrapper.h"

open_dialog_wrapper::open_dialog_wrapper(HWND& window_handle)
{
	_dialog_struct      = { 0 };
	_filters            = nullptr;
	_starting_directory = new char[MAX_PATH + 1];
	_struct_vars_filled = false;
	_window_handle      = &window_handle;

	memset(_path,               '\0', sizeof(*_path));
	memset(_starting_directory, '\0', sizeof(*_starting_directory));
}

open_dialog_wrapper::~open_dialog_wrapper()
{

	if (_filters)
		delete _filters;

	delete _path;
	delete _starting_directory;

	_filters            = nullptr;
	_starting_directory = nullptr;
	_window_handle      = nullptr;
}

void open_dialog_wrapper::fill_struct_vals()
{
	ZeroMemory(&_dialog_struct, sizeof(_dialog_struct));
	_dialog_struct.lStructSize     = sizeof(OPENFILENAME);
	_dialog_struct.hwndOwner       = *_window_handle;
	_dialog_struct.lpstrFile       = (LPWSTR)_path;
	_dialog_struct.nMaxFile        = MAX_PATH + 1;
	_dialog_struct.lpstrFilter     = (_filters) ? (LPWSTR)*_filters : (LPWSTR)NULL;
	_dialog_struct.nFilterIndex    = 0;
	_dialog_struct.lpstrFileTitle  = NULL;
	_dialog_struct.nMaxFileTitle   = 0;
	_dialog_struct.lpstrInitialDir = (LPCWSTR)*_starting_directory;
	_dialog_struct.Flags           = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
}

bool open_dialog_wrapper::open()
{
	if (!_struct_vars_filled)
	{
		fill_struct_vals();
		_struct_vars_filled = true;
	}

	bool result = GetOpenFileName(&_dialog_struct);

	return result;
}

HANDLE open_dialog_wrapper::get_file_handle()
{
	return CreateFile(_dialog_struct.lpstrFile, GENERIC_READ,
		              0, (LPSECURITY_ATTRIBUTES)NULL, OPEN_EXISTING,
		              FILE_ATTRIBUTE_NORMAL, (HANDLE)NULL);
}

void open_dialog_wrapper::set_filters(char* filters, size_t buffer_size)
{
	if (_filters)
	{
		delete _filters;
		_filters = nullptr;
	}

	_filters = (char*)malloc(buffer_size * sizeof(char));
	_filters = filters;
}

void open_dialog_wrapper::set_initial_directory(const char& path)
{
	*_starting_directory = path;
}
