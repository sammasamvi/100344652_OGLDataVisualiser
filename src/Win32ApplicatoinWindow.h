#ifndef WIN32_APPLICATION_WINDOW_H
#define WIN32_APPLICATION_WINDOW_H

#include "OGLRenderContext.h"
#include <tchar.h>
#include <Windows.h>

class Win32ApplicationWindow final
{
private:
	HINSTANCE         applicationInstance;
	OGLRenderContext* oglRenderContext;
	bool              open;
	WNDCLASSEX        windowExClassStruct;
	HWND              windowHandle;

	Win32ApplicationWindow();
	~Win32ApplicationWindow();

	void createApplicationWindow(int nCmdShow, int width, int height);
	void createWindowExClassStruct();
	bool registerWindowExClassStruct();

public:
	static Win32ApplicationWindow* applicationWindowInstance;
	static bool                    initApplicationWindow(HINSTANCE applicationInstance);
	static int                     run(int nCmdShow, int width, int height);
	static LRESULT CALLBACK WndProc(HWND windowHandle, UINT message, WPARAM _WPARAM, LPARAM _LPARAM);
};

#endif