#include "SceneManager.h"
#include "cookbookogl.h"
#include "vboplane.h"
SceneManager::SceneManager()
{    
	glClearColor(0.2f,0.2f,0.2f,0.0f); 	
	glEnable(GL_DEPTH_TEST);

	mouseObj=new Mouse(WIN_WIDTH,WIN_HEIGHT);
	keyboardObj=new Keyboard();

	singleTextureProg = new GLSLProgram("shader/texture");	
	multiTextureProg = new GLSLProgram("shader/multitex");
	textProg = new GLSLProgram("shader/textShader");

	mMultiTex1=new MultiTexShader(multiTextureProg, "./media/texture/brick1.bmp", "./media/texture/moss.bmp", new VBOPlane(0.5f, 0.5f, 2, 4) );
	mSingleTex=new SingleTexShader(singleTextureProg, "./media/texture/brick1.bmp", new VBOPlane(0.25f, 0.5f, 2, 4) );	

	button1=new Button(multiTextureProg, mouseObj, keyboardObj, 
		-0.1, -0.5, 0.3f, 0.1f,
		NULL,NULL,NULL,NULL,NULL,
		"button1", 18, 
		vec4(1, 0, 0,1), vec4(0, 1, 0,1),
		"./media/texture/brick1.bmp", "./media/texture/moss.bmp",
		0.01,-0.02,
		NULL,2);
}
SceneManager::~SceneManager()
{
	delete keyboardObj;
	delete mouseObj;
	delete singleTextureProg;
	delete multiTextureProg;
	delete textProg;

	delete mSingleTex;
	delete mMultiTex;
}
void SceneManager::initScene()
{  			
}

void SceneManager::update( float t )
{
	mouseObj->updateMouseStatus() ;
}

void SceneManager::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//button1->drawButton(vec3(-0.5f, -0.5f,0.0f), 0.0,vec3(0.2f, 0.2f,0.0f));
	button1->drawing(vec3(-0.5f, -0.5f,0.0f), 0.0,vec3(-0.2f, -0.2f,0.0f));
	//mMultiTex1->setTexStatus(true);
	//mMultiTex1->render(vec3(-0.1f, -0.2f,0.0f), 90.0);

	//mSingleTex->setTexStatus(true);
	//mSingleTex->render(vec3(0.3f,0.2f,0.0f), 0.0);

	//Drawer::GLSLDrawText(*textProg, 0, 0, vec4(0.5,0.5,0.0,1.0), "asdsadasdasd231312", 18); 
	//Drawer::GLSLDrawText(*textProg, 0.6, 0.9, vec4(0.9,0.9,0.0,1.0), "asdsadasdasd231312", 18); 
}

void SceneManager::resize(int w, int h)
{
	WIN_WIDTH=w;
	WIN_HEIGHT=h;
	glViewport(0,0,WIN_WIDTH,WIN_HEIGHT);
}