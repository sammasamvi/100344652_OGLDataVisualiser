#include "Win32AppWindow.h"

// null pointer for reference check integrity
AppWindow* AppWindow::appWindowInstance = NULL;

AppWindow::AppWindow() { }

AppWindow::~AppWindow()
{
	if (_OGLDrawingContext)
		delete _OGLDrawingContext;
}

void AppWindow::createWNDCLASSEX()
{
	winexClassStruct.cbSize		   = sizeof(WNDCLASSEX);
    winexClassStruct.style         = CS_HREDRAW | CS_VREDRAW;
    winexClassStruct.lpfnWndProc   = WndProc;
    winexClassStruct.cbClsExtra    = 0;
    winexClassStruct.cbWndExtra    = 0;
    winexClassStruct.hInstance     = appInstance;
    winexClassStruct.hIcon         = LoadIcon(appInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    winexClassStruct.hCursor       = LoadCursor(NULL, IDC_ARROW);
    winexClassStruct.hbrBackground = NULL;
	winexClassStruct.lpszMenuName  = NULL;
    winexClassStruct.lpszClassName = L"OGL_DataVisualizer";
	winexClassStruct.hIconSm       = LoadIcon(winexClassStruct.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
}

//create and display application window
void AppWindow::showAppWindow(int nCmdShow, int width, int height)
{
	winHandle = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, L"OGL_DataVisualizer", L"OGL_DataVisualizer", 
							   WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, 
							   width, height, NULL, NULL, appInstance, NULL);
	if (!winHandle)
	{
		MessageBox(NULL, _T("Call to CreateWindow() failed!"), _T("ApplicationWindow"), NULL);
	}

	_OGLDrawingContext = new OGLDrawingContext(winHandle);
	_OGLDrawingContext->initOGLRenderContext(width, height);

	ShowWindow(winHandle, nCmdShow);
	UpdateWindow(winHandle);
}

// register window class structure with window manager
bool AppWindow::registerWNDCLASSEX()
{
	if (!RegisterClassEx(&winexClassStruct))
	{
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("ApplicationWindow"), NULL);
		
		return false;
	}

	return true;
}

//
// static methods.
//

bool AppWindow::initAppWindow(HINSTANCE appInstance)
{
	if (!appWindowInstance)
	{
		appWindowInstance = new AppWindow();

		appWindowInstance->appInstance = appInstance;
		appWindowInstance->createWNDCLASSEX();

		return appWindowInstance->registerWNDCLASSEX();
	}

	return false;
}

int AppWindow::run(int nCmdShow, int width, int height)
{
	appWindowInstance->showAppWindow(nCmdShow, width, height);

	MSG _MSG;

	//main messaging loop
	while (true)
	{
		if (PeekMessage(&_MSG, NULL, 0, 0, PM_REMOVE))
		{
			if (_MSG.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&_MSG);
				DispatchMessage(&_MSG);
			}
		}
		else
		{
			appWindowInstance->_OGLDrawingContext->render();
		}
	}

	delete appWindowInstance;

	return (int)_MSG.wParam;
}

// message handling
LRESULT CALLBACK AppWindow::WndProc(HWND winHandle, UINT msg, WPARAM _WPARAM, LPARAM _LPARAM)
{
	switch (msg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_SIZE:
		appWindowInstance->_OGLDrawingContext->resize(LOWORD(_LPARAM), HIWORD(_LPARAM));
		break;

	default:
		return DefWindowProc(winHandle, msg, _WPARAM, _LPARAM);
	}

	return 0;
}