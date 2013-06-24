#ifndef SINGLETEXSHADER_H
#define SINGLETEXSHADER_H

#include "glslprogram.h"
#include "drawable.h"
#include "ShapeDrawer.h"

class SingleTexShapeDrawer: public ShapeDrawer
{
private:	
	const char * backgroundTextureFile;
    Drawable *plane;

public:
    SingleTexShapeDrawer(GLSLProgram* t_prog, const char * backgroundTextureFile, Drawable* t_shape );
	~SingleTexShapeDrawer();

	void initScene();
    void render(vec3 translation, float rotation);
};

#endif // SINGLETEXSHADER_H
