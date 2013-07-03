#include "globalSetting.h"
#include "dynVertexTexShapeDrawer.h"
#include "bmpreader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
using glm::vec3;
#include "vboplane.h"
DynVertexTexShapeDrawer::DynVertexTexShapeDrawer(GLSLProgram* t_prog, int t_DrawMode, Drawable* t_shape) :ShapeDrawer()
{	
	setGLSLProgram(t_prog);
	getGLSLProgram().use();
	plane = t_shape;	
	modeMask=10;
	drawMode=t_DrawMode%modeMask;
	initScene();
}
DynVertexTexShapeDrawer::~DynVertexTexShapeDrawer()
{
	delete plane;
};
void DynVertexTexShapeDrawer::initScene()
{    
	getGLSLProgram().use();	
    glEnable(GL_DEPTH_TEST);    
}

void DynVertexTexShapeDrawer::render(vec3 translation, float rotation)
{		
	getGLSLProgram().use();
	getGLSLProgram().setUniform("mode", drawMode);
	getGLSLProgram().setUniform("Time", TIME);
	mat4  model = mat4(1.0f);
    model =model* glm::translate(translation)*glm::rotate(rotation, vec3(1.0f,0.0f,0.0f));
	getGLSLProgram().setUniform("MVP", model);
	getGLSLProgram().setUniform("Light.Intensity",  getLightInfo().Intensity );
    getGLSLProgram().setUniform("Light.Position", getLightInfo().Position );
	getGLSLProgram().setUniform("Material.Kd", getMaterialInfo().Kd);
    getGLSLProgram().setUniform("Material.Ks", getMaterialInfo().Ks);
    getGLSLProgram().setUniform("Material.Ka", getMaterialInfo().Ka);
    getGLSLProgram().setUniform("Material.Shininess", getMaterialInfo().Shininess);

    plane->render();
}
