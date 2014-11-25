#include "OGLRenderContext.h"

OGLRenderContext::OGLRenderContext(HWND _windowHandle)
{
	windowHandle                 = _windowHandle;
	renderingDeviceContextHandle = GetDC(windowHandle);
	renderContextScene			 = NULL;
}

OGLRenderContext::~OGLRenderContext()
{
	
}

bool OGLRenderContext::close()
{


	return false;
}

void OGLRenderContext::initOGLRenderContext(int renderContextWidth, int rederContextHeight)
{
	static PIXELFORMATDESCRIPTOR pixelFormatDescriptor =
	{
		sizeof(PIXELFORMATDESCRIPTOR), // Size Of This Pixel Format Descriptor
		1,							   // Version Number
		PFD_DRAW_TO_WINDOW |		   // Format Support Window
		PFD_SUPPORT_OPENGL |		   // Format Support OpenGL
		PFD_DOUBLEBUFFER,			   // Must Support Double Buffering
		PFD_TYPE_RGBA,				   // Request RGBA Format
		32,							   // Color Depth
		0, 0, 0, 0, 0, 0,			   // Color Bits mask
		0,							   // No Alpha Buffer
		0,							   // Shift Bit Ignored
		0,							   // No Accumulation Buffer
		0, 0, 0, 0,					   // Accumulation Bits Ignored
		16,							   // Z-Buffer depth
		0,							   // Stencil Buffer
		0,							   // Auxiliary Buffer
		PFD_MAIN_PLANE,				   // Main Drawing Layer
		0,							   // Reserved
		0, 0, 0						   // Layer Masks Ignored
	};


	unsigned int pixelFormat;

	pixelFormat = ChoosePixelFormat(renderingDeviceContextHandle, &pixelFormatDescriptor);

	SetPixelFormat(renderingDeviceContextHandle, pixelFormat, &pixelFormatDescriptor);

	renderingContextHandle = wglCreateContext(renderingDeviceContextHandle);

	wglMakeCurrent(renderingDeviceContextHandle, renderingContextHandle);

	initOGLState();
}

void OGLRenderContext::initOGLState()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
}

bool OGLRenderContext::render()
{
	bool rendered = false;

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	if (renderContextScene)
		rendered = renderContextScene->render();

	glFlush();
	SwapBuffers(renderingDeviceContextHandle);
	
	return rendered;
}

void OGLRenderContext::resize(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,    //left
		    width,  //right
			0.0,    //bottom
			height, //top
			-1.0,   //near
			1.0);   //far

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return;
}

bool OGLRenderContext::setRenderScene(OGLScene* renderContextScene)
{
	if (this->renderContextScene)
		this->renderContextScene->close();

	this->renderContextScene = renderContextScene;

	return this->renderContextScene;
}