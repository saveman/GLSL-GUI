#include "singleTexShapeDrawer.h"

#include "bmpreader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>

using glm::vec3;

SingleTexShapeDrawer::SingleTexShapeDrawer(GLSLProgram* t_prog,  const char * t_backgroundTextureFile, Drawable* t_shape) :ShapeDrawer()
{
	setGLSLProgram(t_prog);
	backgroundTextureFile=t_backgroundTextureFile;
	plane =t_shape;
	initScene();
}

SingleTexShapeDrawer::~SingleTexShapeDrawer()
{
	delete plane;
	delete backgroundTextureFile;
};
void SingleTexShapeDrawer::initScene()
{
	getGLSLProgram().use();
	glEnable(GL_DEPTH_TEST);    

	getGLSLProgram().setUniform("Light.Intensity", vec3(1.0f,1.0f,1.0f) );

	// Load texture file
	const char * texName = backgroundTextureFile;
	GLuint w, h;
	glActiveTexture(GL_TEXTURE2);
	GLuint tid = BMPReader::loadTex(texName, w, h);

	getGLSLProgram().setUniform("Tex1", 2);
}

void SingleTexShapeDrawer::render(vec3 translation, float rotation)
{
	getGLSLProgram().use();
	mat4  model = mat4(1.0f);
    model =model* glm::translate(translation)*glm::rotate(-0.0f, vec3(1.0f,0.0f,0.0f));
	model *= glm::rotate(rotation, vec3(0.0f,0.0f,1.0f));
	getGLSLProgram().setUniform("MVP", model);
	getGLSLProgram().setUniform("attachTexture", getTexStatus());
    getGLSLProgram().setUniform("Light.Position", getLightInfo().Position );
	getGLSLProgram().setUniform("Material.Kd", getMaterialInfo().Kd);
    getGLSLProgram().setUniform("Material.Ks", getMaterialInfo().Ks);
    getGLSLProgram().setUniform("Material.Ka", getMaterialInfo().Ka);
    getGLSLProgram().setUniform("Material.Shininess", getMaterialInfo().Shininess);

	plane->render();
}