#ifndef MULTITEXSHADER_H
#define MULTITEXSHADER_H

#include "drawable.h"
#include "ShapeDrawer.h"

class MultiTexShapeDrawer: public ShapeDrawer
{
private:	
	const char * backgroundTextureFile;
	const char * upperTextureFile;	
	Drawable *plane;

public:
    MultiTexShapeDrawer(GLSLProgram* prog, const char * backgroundTextureFile, const char * upperTextureFile, Drawable* t_shape)  ;
	~MultiTexShapeDrawer();
	void initScene();
    void render(vec3 translation, float rotation);
};

#endif // MULTITEXSHADER_H
