#include "applicationWindow.h"
#include "application_window_resources.h"

win32ApplicationWindow::win32ApplicationWindow()
{
	_oGLRenderContext  = nullptr;
	_open_dialog       = nullptr;
	_menu              = LoadMenu(_applicationInstance, MAKEINTRESOURCE(IDR_MENU));
}

win32ApplicationWindow::~win32ApplicationWindow()
{
	if (_oGLRenderContext)
		delete _oGLRenderContext;

	if (_open_dialog)
		delete _open_dialog;

	_oGLRenderContext = nullptr;
	_open_dialog      = nullptr;
}

win32ApplicationWindow* win32ApplicationWindow::applicationWindowInstance = NULL;

void win32ApplicationWindow::createApplicationWindow(int nCmdShow, int width, int height)
{
	_windowHandle = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, L"100344652_OGL_DataVisualizer", L"100344652_OGL_DataVisualizer",
		                          WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN , CW_USEDEFAULT, CW_USEDEFAULT, 
								  width, height, NULL, NULL, _applicationInstance, NULL);

	if (!_windowHandle)
		MessageBox(NULL, _T("Call to CreateWindow() failed!"), _T("ApplicationWindow"), NULL);

	_oGLRenderContext = new renderContext(_windowHandle);
	_oGLRenderContext->init_renderContext(width, height);
	_oGLRenderContext->set_colour(255, 255, 255, 255);

	_open_dialog = new common_dialog_wrapper(_windowHandle);
	_open_dialog->set_title(L"Open Data File");
	_open_dialog->set_filters(L"CSV\0*.csv\0XML\0*.xml\0\0");
	
	SetMenu(_windowHandle, _menu);
	ShowWindow(_windowHandle, nCmdShow); 
	UpdateWindow(_windowHandle);
}

void win32ApplicationWindow::createWindowExClassStruct()
{
	_windowExClassStruct.cbSize        = sizeof(WNDCLASSEX);
    _windowExClassStruct.style         = CS_HREDRAW | CS_VREDRAW;
    _windowExClassStruct.lpfnWndProc   = WndProc;
    _windowExClassStruct.cbClsExtra    = 0;
    _windowExClassStruct.cbWndExtra    = 0;
	_windowExClassStruct.hInstance     = _applicationInstance;
	_windowExClassStruct.hIcon         = LoadIcon(_applicationInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    _windowExClassStruct.hCursor       = LoadCursor(NULL, IDC_ARROW);
    _windowExClassStruct.hbrBackground = NULL;
	_windowExClassStruct.lpszMenuName  = NULL;
    _windowExClassStruct.lpszClassName = L"100344652_OGL_DataVisualizer";
	_windowExClassStruct.hIconSm       = LoadIcon(_windowExClassStruct.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
}

bool win32ApplicationWindow::initApplicationWindow(HINSTANCE _applicationInstance)
{
	if (!applicationWindowInstance)
	{
		applicationWindowInstance = new win32ApplicationWindow();

		applicationWindowInstance->_applicationInstance = _applicationInstance;
		applicationWindowInstance->createWindowExClassStruct();

		return RegisterClassEx(&applicationWindowInstance->_windowExClassStruct);
	}

	return false;
}

#include "..\win32Util\text_file_reader.h"

LRESULT CALLBACK win32ApplicationWindow::WndProc_menu_handle(HWND _windowHandle, UINT message, WPARAM _WPARAM, LPARAM _LPARAM)
{
	switch (_WPARAM)
	{
	    case ID_CHARTMENU_BARCHART:
			// unimplimented 
		    return 0;

	    case ID_FILEMENU_ITEM_EXIT:
			PostMessage(_windowHandle, WM_CLOSE, 0, 0);
	    	return 0;

		case ID_FILEMENU_ITEM_OPENFILE:
			applicationWindowInstance->_open_dialog->open();
			return 0;

	    default:
			return DefWindowProc(_windowHandle, message, _WPARAM, _LPARAM);
	}
}

int win32ApplicationWindow::run(int nCmdShow, int width, int height)
{
	applicationWindowInstance->createApplicationWindow(nCmdShow, width, height);

	MSG message;
	
	applicationWindowInstance->_open = true;
	while (applicationWindowInstance->_open)
	{
		if (PeekMessage(&message, applicationWindowInstance->_windowHandle, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				applicationWindowInstance->_open = false;
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

LRESULT CALLBACK win32ApplicationWindow::WndProc(HWND _windowHandle, UINT message, WPARAM _WPARAM, LPARAM _LPARAM)
{
	switch (message)
	{
	    case WM_QUIT:
		case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		case WM_COMMAND:
			return WndProc_menu_handle(_windowHandle, message, _WPARAM, _LPARAM);

		case WM_HOTKEY:
			MessageBox(NULL, _T("Hotkey 'ALT+b' used from WndProc\n"), _T("ApplicationWindow"), NULL);
			return 0;

		case WM_PAINT:
			applicationWindowInstance->_oGLRenderContext->render();
			return 0;

		case WM_SIZE:
			applicationWindowInstance->_oGLRenderContext->resize(LOWORD(_LPARAM) + 100.0f, HIWORD(_LPARAM) + 100.0f);
			return 0;

		default:
			return DefWindowProc(_windowHandle, message, _WPARAM, _LPARAM);
	}

	return 0;
}

