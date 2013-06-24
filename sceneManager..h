#ifndef SCENCEMANAGER_H
#define SCENCEMANAGER_H

#include "globalSetting.h"
#include "scene.h"
#include "glslprogram.h"

//#include "sceneparticlesfeedback.h"
//#include "sceneparticles.h"
//#include "scenewave.h"
//#include "scenesmoke.h"
//#include "scenereflectcube.h"

#include "button.h"
#include "drawer.h"
#include "mouse.h"
#include "keyboard.h"

#include "singletexshader.h"
#include "multitexshader.h"

class SceneManager:public Scene
{
private:
	Button* button1;

	GLSLProgram* singleTextureProg;
	GLSLProgram* multiTextureProg;
	GLSLProgram* textProg;

	SingleTexShader* mSingleTex;
	MultiTexShader* mMultiTex;	
	MultiTexShader* mMultiTex1;


	Keyboard* keyboardObj;
	Mouse* mouseObj;
    GLSLProgram prog;

public:
    SceneManager();
	~SceneManager();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SCENCEMANAGER_H
