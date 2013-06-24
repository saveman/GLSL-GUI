#include "guiBaseClass.h"


GuiBaseClass::GuiBaseClass(GLSLProgram* t_prog, Mouse* t_mouse, Keyboard* t_keyboard,
						   float t_x, float t_y, float t_width, float t_height,
						   int (*t_onMouseDown)(string event) , int (*t_onMouseHold)(string event),
						   int (*t_onMouseUp)(string event),int (*t_onMouseOver)(string event),int (*t_onMouseOut)(string event)
						   )
{
	drawer=NULL;
	prog=t_prog;
	mouse=t_mouse;
	keyboard=t_keyboard;	

	width=t_width;
	height=t_height;
	x=t_x-0.5*width; y=t_y-0.5*height;

	onMouseDown = (t_onMouseDown != NULL) ? t_onMouseDown : defaultEventReporter;
	onMouseHold = (t_onMouseHold != NULL) ? t_onMouseHold : defaultEventReporter;
	onMouseUp = (t_onMouseUp != NULL) ? t_onMouseUp : defaultEventReporter;
	onMouseOver = (t_onMouseOver != NULL) ? t_onMouseOver : defaultEventReporter;
	onMouseOut = (t_onMouseOut != NULL) ? t_onMouseOut : defaultEventReporter;

	downUpMouseStatus=-1;
	crossOverOutMouseStatus=-1;
	inOutMouseStatus=-1;
}
GuiBaseClass::~GuiBaseClass()
{
	cout<<"~GuiBaseClass() end"<<endl;
}
void GuiBaseClass::updateUI() 
{
	if (mouse->screenX < x || mouse->screenX > x + width || mouse->screenY < y || mouse->screenY > y + height) {
		downUpMouseStatus = -1;

		if (inOutMouseStatus == 0)
			crossOverOutMouseStatus = -1;
		else if (inOutMouseStatus == 1)
			crossOverOutMouseStatus = 4;
		inOutMouseStatus = 0;
	}
	else {
		if (mouse->indicatorUpDown == 0) {
			downUpMouseStatus = mouse->indicatorUpDown;
			onMouseDown("onMouseDown");
		} else if (mouse->indicatorUpDown == 1) {
			downUpMouseStatus = mouse->indicatorUpDown;
			onMouseUp("onMouseUp");
		}

		if (inOutMouseStatus == 1)
			crossOverOutMouseStatus = -1;
		else if (inOutMouseStatus == 0)
			crossOverOutMouseStatus = 3;
		inOutMouseStatus = 1;
	}
	if (downUpMouseStatus == 0)
		onMouseHold("onMouseHold");

	if (crossOverOutMouseStatus == 3)
		onMouseOver("onMouseOver");
	else if (crossOverOutMouseStatus == 4)
		onMouseOut("onMouseOut");
}