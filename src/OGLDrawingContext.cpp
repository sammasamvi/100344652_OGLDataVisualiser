#include "OGLDrawingContext.h"

OGLDrawingContext::OGLDrawingContext(HWND windowHandle)
{
	// get device context handle for a window
	winHandle			= windowHandle;
	deviceContextHandle = GetDC(winHandle);

	// null pointer for reference check integrity
	Scene = NULL;
}

OGLDrawingContext::~OGLDrawingContext()
{
	if (Scene)
	{
		Scene->Close();
		Scene = NULL;
	}

	if (renderingContextHandle)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(renderingContextHandle);
		renderingContextHandle = NULL;
	}

	ReleaseDC(winHandle, deviceContextHandle);
}

// assign a scene to be rendered by the context
void OGLDrawingContext::assignScene(OGLScene* Scene)
{
	if (this->Scene)
		this->Scene->Close();

	this->Scene = Scene;
}

// get a rendering context handle for OGL
void OGLDrawingContext::initOGLRenderContext(int width, int height)
{
	unsigned int pixelformat;

	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Support Window
		PFD_SUPPORT_OPENGL |						// Format Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request RGBA Format
		32,											// Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits mask
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// Z-Buffer depth
		0,											// Stencil Buffer
		0,											// Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	pixelformat = ChoosePixelFormat(deviceContextHandle, &pfd);

	SetPixelFormat(deviceContextHandle, pixelformat, &pfd);

	renderingContextHandle = wglCreateContext(deviceContextHandle);

	wglMakeCurrent(deviceContextHandle, renderingContextHandle);
}

void OGLDrawingContext::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	if (Scene)
	{
		Scene->Render();
	}

	glFlush();
	SwapBuffers(deviceContextHandle);
	return;
}

// resize draw area 
void OGLDrawingContext::resize(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.5*width, 0.5*width, -0.5*height, 0.5*height, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return;
}