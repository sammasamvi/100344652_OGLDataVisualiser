#include "OGLRenderContext.h"
#include "OGLBarChart.h"

OGLRenderContext::OGLRenderContext(HWND _windowHandle)
{
	windowHandle                 = _windowHandle;
	renderingDeviceContextHandle = GetDC(windowHandle);
	renderContextScene = new OGLBarChart(*this);
	renderContextScene->setBackgroudColour(255, 0, 0);
}

OGLRenderContext::~OGLRenderContext()
{
	
}

void OGLRenderContext::assertBackgroundColour()
{
    glClearColor(_bColour->getOGLColourVal(Red),
                 _bColour->getOGLColourVal(Green),
                 _bColour->getOGLColourVal(Blue),
                 1.0f); // Alpha channel
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
	setBackgroudColour(255, 255, 255);

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
	OGLScene::resize(width, height);

	glViewport(0, 0, _width, _height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,     //left
            _width,  //right
            0.0,     //bottom
            _height, //top
            -1.0,    //near
            1.0);    //far

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (renderContextScene)
		renderContextScene->resize(_width, _height);

	return;
}

void OGLRenderContext::setBackgroudColour(int red, int green, int blue)
{
	OGLScene::setBackgroudColour(red, green, blue);
	assertBackgroundColour();
}

void OGLRenderContext::setBackgroudColour(Colour& colour)
{
	OGLScene::setBackgroudColour(colour);
	assertBackgroundColour();
}

bool OGLRenderContext::setRenderScene(OGLScene* renderContextScene)
{
	if (this->renderContextScene)
		this->renderContextScene->close();

	this->renderContextScene = renderContextScene;

	return this->renderContextScene;
}