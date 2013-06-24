#include "globalSetting.h"

#include "GUIManager.h"
#include "cookbookogl.h"
#include "vboplane.h"
GUIManager::GUIManager()
{    
	glEnable(GL_DEPTH_TEST);

	mouseObj=new Mouse(WIN_WIDTH,WIN_HEIGHT);
	keyboardObj=new Keyboard();

	singleTextureProg = new GLSLProgram("shader/singleTextureShader");	
	multiTextureProg = new GLSLProgram("shader/multiTextureShader");
	textProg = new GLSLProgram("shader/textShader");

	button0=new Button(multiTextureProg, mouseObj, keyboardObj, 
		-0.6, 0.5, 0.4f, 0.1f,
		NULL,NULL,NULL,NULL,NULL,
		"RGBA button", 18, 
		vec4(0.5, 0.4, 0,4), vec4(0, 1, 0,1),
		"./media/texture/brick1.bmp", "./media/texture/moss.bmp",
		0.01,0.02,
		NULL,0);
	button0->setFontOffset(vec3(-0.25,-0.15,0));

	button1=new Button(singleTextureProg, mouseObj, keyboardObj, 
		-0.55, -0.0, 0.5f, 0.1f,
		NULL,NULL,NULL,NULL,NULL,
		"Single-Texuture button", 18, 
		vec4(0, 1, 0,1), vec4(0, 1, 0,1),
		"./media/texture/brick1.bmp", "./media/texture/moss.bmp",
		-0.01,0.02,
		NULL,1);
	button1->setFontOffset(vec3(-0.38,-0.15,0));

	button2=new Button(multiTextureProg, mouseObj, keyboardObj, 
		-0.45, -0.5, 0.7, 0.1f,
		NULL,NULL,NULL,NULL,NULL,
		"Double-Texuture-Blended button", 18, 
		vec4(1,1, 1,1), vec4(0, 1, 0,1),
		"./media/texture/brick1.bmp", "./media/texture/moss.bmp",
		0.01,-0.02,
		NULL,2);
	button2->setFontOffset(vec3(-0.4,-0.15,0));
}
GUIManager::~GUIManager()
{
	delete keyboardObj;
	delete mouseObj;
	delete singleTextureProg;
	delete multiTextureProg;
	delete textProg;
	delete button1;
}
void GUIManager::initScene()
{  			
}

void GUIManager::update( float t )
{
	mouseObj->updateMouseStatus() ;
	keyboardObj->updateKeyboardStatus();
}

void GUIManager::render()
{	
	button0->drawing();
	button1->drawing();
	button2->drawing();
}

void GUIManager::resize(int w, int h)
{
	WIN_WIDTH=w;
	WIN_HEIGHT=h;
	glViewport(0,0,WIN_WIDTH,WIN_HEIGHT);
}