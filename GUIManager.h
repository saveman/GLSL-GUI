#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include "glslprogram.h"
#include "scene.h"
#include "button.h"
#include "mouse.h"
#include "keyboard.h"
#include <vector>
class GUIManager:public Scene
{
private:
	float time;
	
	vector<GuiBaseClass*> guiComponentList;
	GLSLProgram* waveTextureProg;
	GLSLProgram* singleTextureProg;
	GLSLProgram* multiTextureProg;
	GLSLProgram* textProg;
	Keyboard* keyboardObj;
	Mouse* mouseObj;
	
public:
    GUIManager();
	~GUIManager();

	

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);;
};

#endif // GUIMANAGER_H
