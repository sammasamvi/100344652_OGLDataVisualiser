#include "common_dialog_wrapper.h"

common_dialog_wrapper::common_dialog_wrapper(HWND window_handle)
{
	ZeroMemory(&_common_dialog_struct, sizeof(_common_dialog_struct));
	ZeroMemory(_file_name, sizeof(*_file_name));

	_common_dialog_struct.lStructSize     = sizeof(_common_dialog_struct);
	_common_dialog_struct.hwndOwner       = window_handle;
	_common_dialog_struct.lpstrFile       = _file_name;
	_common_dialog_struct.nMaxFile        = MAX_PATH;
	_common_dialog_struct.lpstrInitialDir = nullptr;
	_common_dialog_struct.lpstrFilter     = nullptr;
	_common_dialog_struct.nFilterIndex    = 0;
	_common_dialog_struct.Flags           = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	_common_dialog_struct.lpstrTitle      = _T("OPENFILENAME");
}

common_dialog_wrapper::~common_dialog_wrapper()
{
	ZeroMemory(&_common_dialog_struct, sizeof(_common_dialog_struct));

	delete[] _file_name;
}

TCHAR* common_dialog_wrapper::get_filename()
{
	return _file_name;
}

bool common_dialog_wrapper::open()
{
	return open_at(NULL);
}

bool common_dialog_wrapper::open_at(wchar_t* location)
{
	_common_dialog_struct.lpstrInitialDir = location;

	return GetOpenFileName(&_common_dialog_struct);
}

void common_dialog_wrapper::set_filename_container(TCHAR* container)
{
	ZeroMemory(container, sizeof(*container));

	_common_dialog_struct.lpstrFilter = container;
}

void common_dialog_wrapper::set_filters(wchar_t* filters)
{
	_common_dialog_struct.lpstrFilter  = filters;
	_common_dialog_struct.nFilterIndex = 1;
}

void common_dialog_wrapper::set_flags(int flags)
{
	_common_dialog_struct.Flags = flags;
}

void common_dialog_wrapper::set_title(const wchar_t* title)
{
	_common_dialog_struct.lpstrTitle = title;
}