#ifndef OGL_SCENE_H
#define OGL_SCENE_H

class OGLScene
{
public:
	virtual void Close()  = 0;
	virtual void Render() = 0;
};

#endif