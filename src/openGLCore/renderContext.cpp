#include "renderContext.h"
#include <gl\GL.h>
#include "..\openGLShapes\material_rectangle.h"
#include "..\materialLaw\material_interactivity.h"

renderContext::renderContext(HWND& windowHandle)
{
	_renderingDeviceContextHandle = GetDC(windowHandle);
	_scene                        = new material_rectangle(this);
	_windowHandle                 = &windowHandle;

	_scene->set_coordinates(10, 10);
	_scene->set_height(200);
	_scene->set_width(60);
	_scene->set_colour(255, 255, 255);

	material_interactivity::set_render_context(this);
}

renderContext::~renderContext()
{
	wglMakeCurrent(NULL, NULL);

	if (_renderingContextHandle)
		wglDeleteContext(_renderingContextHandle);

	if (_renderingDeviceContextHandle)
		ReleaseDC(*_windowHandle, _renderingDeviceContextHandle);
}

void renderContext::assert_glClearColor()
{
	glClearColor(_colour.get_colour_channel(Red),
		         _colour.get_colour_channel(Green),
		         _colour.get_colour_channel(Blue),
		         _colour.get_colour_channel(Alpha));
}

void renderContext::init_renderContext(int renderContextWidth, int rederContextHeight)
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

	pixelFormat = ChoosePixelFormat(_renderingDeviceContextHandle, &pixelFormatDescriptor);

	SetPixelFormat(_renderingDeviceContextHandle, pixelFormat, &pixelFormatDescriptor);

	_renderingContextHandle = wglCreateContext(_renderingDeviceContextHandle);

	wglMakeCurrent(_renderingDeviceContextHandle, _renderingContextHandle);

	set_ogl_vars();
}

bool renderContext::render()
{
	bool rendered = true;
	
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	if (_scene)
		rendered = _scene->render();

	glFlush();
	SwapBuffers(_renderingDeviceContextHandle);

	return rendered;
}

bool renderContext::resize(float width, float height)
{
	renderable::resize(width, height);

	bool rendered = true;

	glViewport(0, 0, _width, _height);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glOrtho(0.0f,   //left
            _width, //right
			0.0f,   //bottom
			_height,//top
			-5.0f,  //near
			5.0f);  //far

	//if (_scene)
	//	rendered = _scene->resize(_width, _height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return true;
}

void renderContext::set_colour(int red, int green, int blue, int alpha)
{
	renderable::set_colour(red, green, blue, alpha);

	assert_glClearColor();
}

void renderContext::set_colour(const colour& value)
{
	renderable::set_colour(value);

	assert_glClearColor();
}

void renderContext::set_ogl_vars()
{
	assert_glClearColor();

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void renderContext::set_render_scene(renderable& scene)
{
	if (_scene)
	{
		if (_scene != &scene)
		{
			delete _scene;
			_scene = &scene;
		}
	}
	else
	{
		_scene = &scene;
	}
}
