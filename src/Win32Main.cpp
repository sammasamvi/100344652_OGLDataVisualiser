#include "Win32AppWindow.h"
#include "Win32Main.h"

// Application entry point (main).
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	if (!AppWindow::initAppWindow(hInstance))
	{
		MessageBox(NULL, _T("Application failed to instantiate."), _T("OGL_DataVisualizer"), NULL);
	}
	else
	{
		return AppWindow::run(nCmdShow, 1024, 700);
	}

	return 0;
}