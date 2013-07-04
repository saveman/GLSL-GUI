#include "globalSetting.h"

#include "GUIManager.h"
#include "cookbookogl.h"
#include "vboplane.h"

GUIManager::GUIManager()
{    
	time=0;
	glEnable(GL_DEPTH_TEST);

	mouseObj=new Mouse(WIN_WIDTH,WIN_HEIGHT);
	keyboardObj=new Keyboard();

	allInOneTextureProg = new GLSLProgram("shader/allInOneTextureShader");
	multiTextureProg = new GLSLProgram("shader/multiTextureShader");
	waveTextureProg = new GLSLProgram("shader/dynVertexTexShapeDrawer");	
	singleTextureProg = new GLSLProgram("shader/singleTextureShader");	

	textProg = new GLSLProgram("shader/textShader");

	Button* button;
	LightInfo* light=new LightInfo();
	MaterialInfo* material=new MaterialInfo();

	button=new Button(waveTextureProg, mouseObj, keyboardObj, 
		40, 50, 360, 50,
		NULL,NULL,NULL,NULL,NULL,
		"Flashing Button", 18, 
		vec4(0.1, 0.1, 0,1), vec4(0, 0, 0,1),
		NULL, NULL,
		10,0,
		NULL,11);
	button->setFontOffset(vec3(80, 20, 0));
	light->Intensity=vec3(0.9f,0.0f,1.0f);light->Position = vec4(0.0f,-5.0f,5.0f,1.0);
	button->getShapeDrawer()->setLightInfo(*light);
	material->Ka=vec3(0.9f,0.0f,1.0f);material->Kd = vec3(0.9f, 0.9f, 0.9f);material->Ks=vec3(0.5f, 0.5f, 0.5f);material->Shininess=180.0f;
	button->getShapeDrawer()->setMaterialInfo(*material);
	guiComponentList.push_back(button);

	button=new Button(waveTextureProg, mouseObj, keyboardObj, 
		40, 150, 360, 50,
		NULL,NULL,NULL,NULL,NULL,
		"Flag-Style Button", 18, 
		vec4(0.1, 0.1, 0,1), vec4(0, 0, 0,1),
		NULL, NULL,
		10,0,
		NULL,11);
	button->setFontOffset(vec3(80, 20, 0));
	button->getShapeDrawer()->setLightInfo(*light);
	button->getShapeDrawer()->setMaterialInfo(*material);
	button->setRotation(5.0);
	guiComponentList.push_back(button);

	button=new Button(waveTextureProg, mouseObj, keyboardObj, 
		40, 250, 360, 50,
		NULL,NULL,NULL,NULL,NULL,
		"Screw-Style Button", 18, 
		vec4(0.1, 0.1, 0,1), vec4(0, 0, 0,1),
		NULL, NULL,
		10,0,
		NULL,12);
	button->setFontOffset(vec3(80, 20, 0));
	button->getShapeDrawer()->setLightInfo(*light);
	button->getShapeDrawer()->setMaterialInfo(*material);
	guiComponentList.push_back(button);

	button=new Button(singleTextureProg, mouseObj, keyboardObj, 
		40, 350, 100, 100,
		NULL,NULL,NULL,NULL,NULL,
		"<= Single-Texuture button", 18, 
		vec4(0, 1, 0,1), vec4(0, 0, 0,1),
		"./media/texture/brick1.bmp", NULL,
		0,-10,
		NULL,1);
	button->setFontOffset(vec3(100, 40,0));
	guiComponentList.push_back(button);

	button=new Button(multiTextureProg, mouseObj, keyboardObj, 
		40, 500, 100, 100,
		NULL,NULL,NULL,NULL,NULL,
		"<= Double-Texuture-Blended button", 18, 
		vec4(0.1,0.9, 0.9,1), vec4(0, 0, 0,1),
		"./media/texture/brick1.bmp", "./media/texture/moss.bmp",
		10,-10,
		NULL,2);
	button->setFontOffset(vec3(100, 40,0));
	guiComponentList.push_back(button);

	button=new Button(allInOneTextureProg, mouseObj, keyboardObj, 
		500, 50, 360, 225,
		NULL,NULL,NULL,NULL,NULL,
		"All-effect-in-one button 1", 18, 
		vec4(0.9,0.9, 0.9,1), vec4(0, 0, 0,1),
		"./media/texture/brick1.bmp", "./media/texture/moss.bmp",
		10,-10,
		NULL,20);
	button->setFontOffset(vec3(80, 20, 0));	
	light->Intensity=vec3(0.6f,0.6f,0.6f);light->Position = vec4(0.0f,-0.0f,5.0f,1.0);
	button->getShapeDrawer()->setLightInfo(*light);
	material->Ka=vec3(0.6f,0.6f,0.6f);material->Kd = vec3(0.3f, 0.3f, 0.3f);material->Ks=vec3(0.1f, 0.1f, 0.1f);material->Shininess=60.0f;
	button->getShapeDrawer()->setMaterialInfo(*material);
	guiComponentList.push_back(button);

	button=new Button(allInOneTextureProg, mouseObj, keyboardObj, 
		500, 350, 360, 225,
		NULL,NULL,NULL,NULL,NULL,
		"All-effect-in-one button2", 18, 
		vec4(0.9,0.9, 0.9,1), vec4(0, 0, 0,1),
		"./media/texture/brick1.bmp", "./media/texture/UCDavisFlag.bmp",
		10,-10,
		NULL,21);
	button->setFontOffset(vec3(80, 20, 0));
	button->setRotation(5.0);
	light->Intensity=vec3(0.9f,0.9f,0.9f);light->Position = vec4(4.0f,0.0f, 0.0f,1.0);
	button->getShapeDrawer()->setLightInfo(*light);
	material->Ka=vec3(0.9f,0.9f,0.9f);material->Kd = vec3(0.3f, 0.3f, 0.3f);material->Ks=vec3(0.8f, 0.8f, 0.9f);material->Shininess=180.0f;
	button->getShapeDrawer()->setMaterialInfo(*material);
	button->getShapeDrawer()->setAmp(0.4f);
	guiComponentList.push_back(button);

	button=new Button(allInOneTextureProg, mouseObj, keyboardObj, 
		500, 650, 360, 100,
		NULL,NULL,NULL,NULL,NULL,
		"All-effect-in-one button3", 18, 
		vec4(0.9,0.9, 0.9,1), vec4(0, 0, 0,1),
		"./media/texture/brick1.bmp", "./media/texture/ERITREA.bmp",
		10,0,
		NULL,22);
	button->setFontOffset(vec3(80, 50, 0));
	light->Intensity=vec3(0.9f,0.9f,0.9f);light->Position = vec4(4.0f,0.0f, 0.0f,1.0);
	button->getShapeDrawer()->setLightInfo(*light);
	material->Ka=vec3(0.8f,0.8f,0.9f);material->Kd = vec3(0.3f, 0.3f, 0.3f);material->Ks=vec3(0.4f, 0.4f, 0.9f);material->Shininess=10.0f;
	button->getShapeDrawer()->setMaterialInfo(*material);
	button->getShapeDrawer()->setVelocity(4.0f);
	guiComponentList.push_back(button);

	button=NULL;
}



GUIManager::~GUIManager()
{
	delete keyboardObj;
	delete mouseObj;
	delete singleTextureProg;
	delete multiTextureProg;
	delete textProg;
	guiComponentList.clear();
}

void GUIManager::initScene()
{  			
}

void GUIManager::update( float t )
{
	time=t;
	mouseObj->updateMouseStatus() ;
	keyboardObj->updateKeyboardStatus();
}

void GUIManager::render()
{	
	for(auto iter=guiComponentList.begin();iter< guiComponentList.end();iter++)
		(*iter)->drawing();
}

void GUIManager::resize(int w, int h)
{
	glViewport(0,0,w,h);
}