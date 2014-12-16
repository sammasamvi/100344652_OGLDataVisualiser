#include "win32Core\applicationWindow.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	if (!win32ApplicationWindow::initApplicationWindow(hInstance))
	{
		MessageBox(NULL, _T("Application failed to instantiate."), _T("OGL_DataVisualizer"), NULL);
	}
	else
	{
		return win32ApplicationWindow::run(nCmdShow, 1024, 768);
	}

	return -1;
}