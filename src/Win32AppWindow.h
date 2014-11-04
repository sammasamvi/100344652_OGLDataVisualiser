#ifndef WIN32_APP_WINDOW_H
#define WIN32_APP_WINDOW_H

#include "OGLDrawingContext.h"
#include <tchar.h>
#include <Windows.h>

class AppWindow final
{
	private:
		//variables
		OGLDrawingContext* _OGLDrawingContext;
		HWND			   winHandle;
		HINSTANCE		   appInstance;
		WNDCLASSEX		   winexClassStruct;

		//constructors
		AppWindow();
		~AppWindow();

		//methods
		void createWNDCLASSEX();
		bool registerWNDCLASSEX();
		void showAppWindow(int nCmdShow, int width, int height);
	
	public:
		static AppWindow*		appWindowInstance;
		static bool				initAppWindow(HINSTANCE appInstance);
		static int				run(int nCmdShow, int width, int height);
		static LRESULT CALLBACK WndProc(HWND winHandle, UINT msg, WPARAM _WPARAM, LPARAM _LPARAM);
};

#endif