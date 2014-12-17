#ifndef COMMON_DIALOG_WRAPPER_H
#define COMMON_DIALOG_WRAPPER_H

#include <Windows.h>
#include <commdlg.h>
#include <tchar.h>

class common_dialog_wrapper
{
    private:
		OPENFILENAME _common_dialog_struct;
		TCHAR*       _file_name            = new TCHAR[MAX_PATH];

		void configure_dialog(HWND window_handle, const wchar_t* location);

    public:
		common_dialog_wrapper(HWND window_handle);
		~common_dialog_wrapper();

		TCHAR* get_filename();
		bool   open();
		bool   open_at(wchar_t* location);
		void   set_filename_container(TCHAR* container);
		void   set_filters(wchar_t* filters);
		void   set_flags(int flags);
		void   set_title(const wchar_t* title);
};

#endif