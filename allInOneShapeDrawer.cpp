#include "globalSetting.h"
#include "allInOneShapeDrawer.h"
#include "bmpreader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
using glm::vec3;

AllInOneShapeDrawer::AllInOneShapeDrawer(GLSLProgram* t_prog, const char * t_backgroundTextureFile, const char * t_upperTextureFile, int t_DrawMode, Drawable* t_shape) :ShapeDrawer()
{	
	setGLSLProgram(t_prog);
	backgroundTextureFile=t_backgroundTextureFile;
	upperTextureFile=t_upperTextureFile;
	plane = t_shape;
	modeMask=20;
	drawMode=t_DrawMode%modeMask;

	initScene();
}
AllInOneShapeDrawer::~AllInOneShapeDrawer()
{
	delete plane;
	delete backgroundTextureFile;
	delete upperTextureFile;
};
void AllInOneShapeDrawer::initScene()
{    
	getGLSLProgram().use();
    glEnable(GL_DEPTH_TEST);    

    getGLSLProgram().setUniform("Light.Intensity", vec3(1.0f,1.0f,1.0f) );

    GLuint w,h;
    // Load lower texture file into channel 3
    glActiveTexture(GL_TEXTURE3);
    backTexID=BMPReader::loadTex(backgroundTextureFile, w, h);

    // Load upper texture file into channel 4
    glActiveTexture(GL_TEXTURE4);
    frontTexID=BMPReader::loadTex(upperTextureFile, w, h);

    getGLSLProgram().setUniform("BackTex", 3);
    getGLSLProgram().setUniform("FrondTex", 4);
}

void AllInOneShapeDrawer::render(vec3 translation, float rotation)
{
	getGLSLProgram().use();
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, backTexID);
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, frontTexID);

	getGLSLProgram().setUniform("mode",drawMode );
	getGLSLProgram().setUniform("Time", TIME);
	getGLSLProgram().setUniform("Freq", getFreq());
	getGLSLProgram().setUniform("Velocity", getVelocity());
	getGLSLProgram().setUniform("Amp", getAmp());

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
