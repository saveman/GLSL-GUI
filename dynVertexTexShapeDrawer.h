#ifndef WAVETEXSHADER_H
#define WAVETEXSHADER_H

#include "drawable.h"
#include "ShapeDrawer.h"

class DynVertexTexShapeDrawer: public ShapeDrawer
{
private:	
	const char * backgroundTextureFile;
	const char * upperTextureFile;	
	Drawable *plane;
	int drawMode;
	int modeMask;
public:
    DynVertexTexShapeDrawer(GLSLProgram* prog, int t_DrawMode,  Drawable* t_shape)  ;
	~DynVertexTexShapeDrawer();
	void initScene();
    void render(vec3 translation, float rotation);
};

#endif // WAVETEXSHADER_H
