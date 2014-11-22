#include "Win32ApplicatoinWindow.h"

Win32ApplicationWindow::Win32ApplicationWindow()
{

}

Win32ApplicationWindow::~Win32ApplicationWindow()
{
	if (oglRenderContext)
	{
		oglRenderContext->close();
		delete oglRenderContext;
	}
}

Win32ApplicationWindow* Win32ApplicationWindow::applicationWindowInstance = NULL;

void Win32ApplicationWindow::createApplicationWindow(int nCmdShow, int width, int height)
{
	windowHandle = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, L"100344652_OGL_DataVisualizer", L"100344652_OGL_DataVisualizer",
		                          WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN , CW_USEDEFAULT, CW_USEDEFAULT, 
								  width, height, NULL, NULL, applicationInstance, NULL);

	if (!windowHandle)
		MessageBox(NULL, _T("Call to CreateWindow() failed!"), _T("ApplicationWindow"), NULL);

	oglRenderContext = new OGLRenderContext(windowHandle);
	oglRenderContext->initOGLRenderContext(width, height);

	ShowWindow(windowHandle, nCmdShow); 
	UpdateWindow(windowHandle);
}

void Win32ApplicationWindow::createWindowExClassStruct()
{
	windowExClassStruct.cbSize		  = sizeof(WNDCLASSEX);
    windowExClassStruct.style         = CS_HREDRAW | CS_VREDRAW;
    windowExClassStruct.lpfnWndProc   = WndProc;
    windowExClassStruct.cbClsExtra    = 0;
    windowExClassStruct.cbWndExtra    = 0;
	windowExClassStruct.hInstance     = applicationInstance;
	windowExClassStruct.hIcon         = LoadIcon(applicationInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    windowExClassStruct.hCursor       = LoadCursor(NULL, IDC_ARROW);
    windowExClassStruct.hbrBackground = NULL;
	windowExClassStruct.lpszMenuName  = NULL;
    windowExClassStruct.lpszClassName = L"100344652_OGL_DataVisualizer";
	windowExClassStruct.hIconSm       = LoadIcon(windowExClassStruct.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
}

bool Win32ApplicationWindow::initApplicationWindow(HINSTANCE applicationInstance)
{
	if (!applicationWindowInstance)
	{
		applicationWindowInstance = new Win32ApplicationWindow();

		applicationWindowInstance->applicationInstance = applicationInstance;
		applicationWindowInstance->createWindowExClassStruct();

		return RegisterClassEx(&applicationWindowInstance->windowExClassStruct);
	}

	return false;
}



int Win32ApplicationWindow::run(int nCmdShow, int width, int height)
{
	applicationWindowInstance->createApplicationWindow(nCmdShow, width, height);

	MSG message;
	
	applicationWindowInstance->open = true;
	while (applicationWindowInstance->open)
	{
		if (PeekMessage(&message, applicationWindowInstance->windowHandle, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				applicationWindowInstance->open = false;
			}
			else
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
	}

	delete applicationWindowInstance;
	return (int)message.wParam;
}

LRESULT CALLBACK Win32ApplicationWindow::WndProc(HWND windowHandle, UINT message, WPARAM _WPARAM, LPARAM _LPARAM)
{
	switch (message)
	{
		case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_PAINT:
			applicationWindowInstance->oglRenderContext->render();
			return 0;
			break;

		default:
			return DefWindowProc(windowHandle, message, _WPARAM, _LPARAM);
	}

	return 0;
}

