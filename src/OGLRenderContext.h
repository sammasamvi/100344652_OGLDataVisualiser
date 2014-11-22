#ifndef OGL_RENDER_CONTExT
#define OGL_RENDER_CONTExT

#include <Windows.h>
#include "OGLScene.h"

class OGLRenderContext final : public OGLScene
{
	private:
		int		  renderContextHeight;
		OGLScene* renderContextScene;
		int		  renderContextWidth;
		HGLRC	  renderingContextHandle;
		HDC		  renderingDeviceContextHandle;
		HWND	  windowHandle;
	
		void initOGLState();

	public:
		OGLRenderContext(HWND windowHandle);
		~OGLRenderContext();
	
		bool close();
		void initOGLRenderContext(int renderContextWidth, int renderContextHeight);
		bool render();
		void resize(int width, int height);
		bool setRenderScene(OGLScene* renderContextScene);
};

#endif