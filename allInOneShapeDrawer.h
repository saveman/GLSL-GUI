#ifndef ALLINONETEXSHADER_H
#define ALLINONETEXSHADER_H

#include "drawable.h"
#include "ShapeDrawer.h"

class AllInOneShapeDrawer: public ShapeDrawer
{
private:	
	const char * backgroundTextureFile;
	const char * upperTextureFile;
	Drawable *plane;

public:
    AllInOneShapeDrawer(GLSLProgram* prog, const char * backgroundTextureFile, const char * upperTextureFile, int t_DrawMode, Drawable* t_shape)  ;
	~AllInOneShapeDrawer();
	void initScene();
    void render(vec3 translation, float rotation);
};

#endif // MULTITEXSHADER_H
