#ifndef WIN32_APPLICATION_WINDOW_H
#define WIN32_APPLICATION_WINDOW_H

#include <tchar.h>
#include <Windowsx.h>

#include "..\openGLCore\renderContext.h"
#include "common_dialog_wrapper.h"

class win32ApplicationWindow
{
    private:
    	HINSTANCE              _applicationInstance;
		HMENU                  _menu;
		renderContext*         _oGLRenderContext;
    	bool                   _open;
		common_dialog_wrapper* _open_dialog;
    	WNDCLASSEX             _windowExClassStruct;
    	HWND                   _windowHandle;
    
		win32ApplicationWindow();
		~win32ApplicationWindow();

		void                    createApplicationWindow(int nCmdShow, int width, int height);
    	void                    createWindowExClassStruct();
    	bool                    registerWindowExClassStruct();
		static LRESULT CALLBACK WndProc_menu_handle(HWND _windowHandle, UINT message, WPARAM _WPARAM, LPARAM _LPARAM);
    
    public:
		static win32ApplicationWindow* applicationWindowInstance;
    	static bool                    initApplicationWindow(HINSTANCE applicationInstance);
    	static int                     run(int nCmdShow, int width, int height);
    	static LRESULT CALLBACK        WndProc(HWND windowHandle, UINT message, WPARAM _WPARAM, LPARAM _LPARAM);
};

#endif