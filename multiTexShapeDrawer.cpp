#include "globalSetting.h"
#include "multiTexShapeDrawer.h"
#include "bmpreader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
using glm::vec3;

MultiTexShapeDrawer::MultiTexShapeDrawer(GLSLProgram* t_prog, const char * t_backgroundTextureFile, const char * t_upperTextureFile, Drawable* t_shape) :ShapeDrawer()
{	
	setGLSLProgram(t_prog);
	backgroundTextureFile=t_backgroundTextureFile;
	upperTextureFile=t_upperTextureFile;
	plane = t_shape;
	initScene();
}
MultiTexShapeDrawer::~MultiTexShapeDrawer()
{
	delete plane;
	delete backgroundTextureFile;
	delete upperTextureFile;
};
void MultiTexShapeDrawer::initScene()
{    
	getGLSLProgram().use();
    glEnable(GL_DEPTH_TEST);    

    getGLSLProgram().setUniform("Light.Intensity", vec3(1.0f,1.0f,1.0f) );

    GLuint w,h;
    // Load lower texture file into channel 0
    glActiveTexture(GL_TEXTURE0);
    BMPReader::loadTex(backgroundTextureFile, w, h);

    // Load upper texture file into channel 1
    glActiveTexture(GL_TEXTURE1);
    BMPReader::loadTex(upperTextureFile, w, h);

    getGLSLProgram().setUniform("BrickTex", 0);
    getGLSLProgram().setUniform("MossTex", 1);
}

void MultiTexShapeDrawer::render(vec3 translation, float rotation)
{
	getGLSLProgram().use();
	
	mat4  model = mat4(1.0f);
    model =model* glm::translate(translation)*glm::rotate(-0.0f, vec3(1.0f,0.0f,0.0f));
	model *= glm::rotate(rotation, vec3(0.0f,0.0f,1.0f));
	getGLSLProgram().setUniform("MVP", model);
	getGLSLProgram().setUniform("attachTexture", getTexStatus());
	getGLSLProgram().setUniform("Light.Intensity",  getLightInfo().Intensity );
    getGLSLProgram().setUniform("Light.Position", getLightInfo().Position );
	getGLSLProgram().setUniform("Material.Kd", getMaterialInfo().Kd);
    getGLSLProgram().setUniform("Material.Ks", getMaterialInfo().Ks);
    getGLSLProgram().setUniform("Material.Ka", getMaterialInfo().Ka);
    getGLSLProgram().setUniform("Material.Shininess", getMaterialInfo().Shininess);

    plane->render();
}
