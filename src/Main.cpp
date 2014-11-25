#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <Windows.h>

#include "Win32ApplicatoinWindow.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	if (!Win32ApplicationWindow::initApplicationWindow(hInstance))
	{
		MessageBox(NULL, _T("Application failed to instantiate."), _T("OGL_DataVisualizer"), NULL);
	}
	else
	{
		return Win32ApplicationWindow::run(nCmdShow, 1024, 768);
	}

	return -1;
}