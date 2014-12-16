#ifndef WIN32_APPLICATION_WINDOW_H
#define WIN32_APPLICATION_WINDOW_H

#include <tchar.h>
#include <Windows.h>

#include "..\openGLCore\renderContext.h"

class win32ApplicationWindow
{
    private:
		void*          _file_reader;

    	HINSTANCE      _applicationInstance;
		OPENFILENAME   _common_dialog;
		char           _common_dialog_szFile[MAX_PATH + 1];
		HMENU          _menu;
		renderContext* _oGLRenderContext;
    	bool           _open;
    	WNDCLASSEX     _windowExClassStruct;
    	HWND           _windowHandle;
    
		win32ApplicationWindow();
		~win32ApplicationWindow();
    
		void                    read_file();
		void                    createApplicationWindow(int nCmdShow, int width, int height);
    	void                    createWindowExClassStruct();
		static LRESULT CALLBACK WndProc_menu_handle(HWND _windowHandle, UINT message, WPARAM _WPARAM, LPARAM _LPARAM);
    	bool                    registerWindowExClassStruct();
    
    public:
		static win32ApplicationWindow* applicationWindowInstance;
    	static bool                    initApplicationWindow(HINSTANCE applicationInstance);
    	static int                     run(int nCmdShow, int width, int height);
    	static LRESULT CALLBACK        WndProc(HWND windowHandle, UINT message, WPARAM _WPARAM, LPARAM _LPARAM);
};

#endif