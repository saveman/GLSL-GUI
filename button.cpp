#include "button.h"
#include "globalSetting.h"

#include "vboplane.h"
#include "textdrawer.h"

#include "singleTexShapeDrawer.h"
#include "multiTexShapeDrawer.h"
#include "dynVertexTexShapeDrawer.h"
#include "allInOneShapeDrawer.h"

using glm::vec3;

Button::Button(GLSLProgram* t_prog, Mouse* t_mouse, Keyboard* t_keyboard,
			   int t_x, int t_y, int t_width, int t_height,
			   int (*t_onMouseDown)(string event) , int (*t_onMouseHold)(string event), 
			   int (*t_onMouseUp)(string event),int (*t_onMouseOver)(string event),int (*t_onMouseOut)(string event),
			   const char* t_buttonText, int t_fontSize, 
			   vec4 t_textColor,    vec4 t_buttonColor,
			   const char * t_backgroundTextureFile, const char * t_upperTextureFile,
			   float t_pressDownOffset_x, float t_pressDownOffset_y,
			   int (*t_onMouseOn)(string event) ,  int t_drawMode )
			   :
GuiBaseClass(t_prog, t_mouse, t_keyboard,  t_x, t_y, t_width, t_height,  t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut)
{
	buttonText = t_buttonText;
	fontSize = (t_fontSize!=0)?t_fontSize:18;
	textColor = (t_textColor != vec4(0.0)) ? t_textColor : vec4(1, 0, 0,1);
	buttonColor = (t_buttonColor != vec4(0.0)) ? t_buttonColor : vec4(0, 1, 0,1);
	const char * backgroundTextureFile=t_backgroundTextureFile;
	const char * upperTextureFile=t_upperTextureFile;
	pressDownOffset_x = (t_pressDownOffset_x != 0.0) ? t_pressDownOffset_x : 0.1;
	pressDownOffset_y = (t_pressDownOffset_y != 0.0) ? t_pressDownOffset_y : 0.1;

	onMouseOn = (t_onMouseOn != NULL) ? t_onMouseOn : defaultEventReporter;
	drawMode  = t_drawMode;

	x0 = x;
	y0 = y;

	renderTextColor = (t_textColor != vec4(0.0)) ? t_textColor : vec4(1, 0, 0,1);
	renderButtonColor = (t_buttonColor != vec4(0.0)) ? t_buttonColor : vec4(0, 1, 0,1);
	float w=(float)width/(float)WIN_WIDTH*2.0;
	float h=(float)height/(float)WIN_HEIGHT*2.0;

	if(drawMode==1)
	{
		drawer=new SingleTexShapeDrawer(t_prog, t_backgroundTextureFile, new VBOPlane(w, h, 10, 10));	
	}
	else if(drawMode==2)
	{
		drawer=new MultiTexShapeDrawer(t_prog, t_backgroundTextureFile, t_upperTextureFile, new VBOPlane(w, h, 10, 10) );
	}
	else if(drawMode<=19)
	{
		drawer=new DynVertexTexShapeDrawer(t_prog, drawMode, new VBOPlane(w, h, 10, 10));
	}
	else if(drawMode<=29)
	{
		drawer=new AllInOneShapeDrawer(t_prog, t_backgroundTextureFile, t_upperTextureFile, drawMode, new VBOPlane(w, h, 10, 10));
	}

	textProg = new GLSLProgram("shader/textShader");

	rotation=0.0;
	fontOffset=vec3(-0.2, -0.2,0);
}

Button::~Button()
{
	delete textProg;
	delete drawer;
	cout<<"~Button() end"<<endl;
}

//define privatemember method to draw a button instance
void Button::drawButton() {
	drawer->render(vec3((float(x+0.5*width))/WIN_WIDTH*2.0-1.0, (float(y+0.5*height))/WIN_HEIGHT*2.0-1.0,0),rotation);
	TextDrawer::GLSLDrawText(*textProg, (float(x+fontOffset.x))/WIN_WIDTH*2.0-1.0, (float(y+fontOffset.y))/WIN_HEIGHT*2.0-1.0, textColor, buttonText, fontSize); 
}

//define private member method to update a button status
void Button::updateButton() {
	if (getInOutMouseStatus() == 0) {
		x = x0;
		y = y0;
		renderTextColor = textColor;
		renderButtonColor = buttonColor;
	}
	else {
		if (mouse->indicatorUpDown == 0) {
			x = x0 + pressDownOffset_x;
			y = y0 + pressDownOffset_y;
		}
		else if (mouse->indicatorUpDown == 1) {
			x = x0;
			y = y0;
		}
		onMouseOn("onMouseOn");
	}
}

//define priviledge member method to update a button instance
void Button::drawing (vec3& t_pos, float t_rot, vec3 & t_fontOffset) {
	x=t_pos.x-0.5*width; y=t_pos.y-0.5*height;
	x0=x; y0=y;
	rotation=t_rot;
	fontOffset=t_fontOffset;

	updateUI();
	updateButton();
	drawButton();
}
void Button::drawing () {
	updateUI();
	updateButton();
	drawButton();
}