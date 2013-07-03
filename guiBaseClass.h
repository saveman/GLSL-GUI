#ifndef GUIBASECLASS_H
#define GUIBASECLASS_H

#include "glslprogram.h"
#include "keyboard.h"
#include "mouse.h"
#include "ShapeDrawer.h"

#include<iostream>
using  namespace std;
inline int defaultEventReporter (string event) 
{//used for debug to report UI events
	cout<<"defaultEventReporter: "<<event<<"\n";
	return -1;
}


class GuiBaseClass
{
protected:
	ShapeDrawer* drawer;
	GLSLProgram* prog;
	Mouse* mouse;
	Keyboard* keyboard;
	int x;
	int y;
	int width;
	int height;
	int (*onMouseDown)(string event);
	int (*onMouseHold)(string event);
	int (*onMouseUp)(string event);
	int (*onMouseOver)(string event);
	int (*onMouseOut)(string event);

private:
	int	downUpMouseStatus;
	int crossOverOutMouseStatus;
	int inOutMouseStatus;

public:
	GuiBaseClass(GLSLProgram* t_prog, Mouse* t_mouse, Keyboard* t_keyboard,
		int t_x, int t_y, int t_width, int t_height,
		int (*t_onMouseDown)(string event) , int (*t_onMouseHold)(string event),
		int (*t_onMouseUp)(string event),int (*t_onMouseOver)(string event),int (*t_onMouseOut)(string event)
		);
	virtual ~GuiBaseClass(); //prog, mouse, keyboard are supposed to be deleted in the class where intiated them, rather than in this desctructor

	void GuiBaseClass::updateUI() ;
	inline GLSLProgram* getGLSLProgram()
	{
		return prog;
	}
	inline ShapeDrawer* getShapeDrawer()
	{
		return drawer;
	}
	inline int getDownUpMouseStatus()
	{
		return downUpMouseStatus;
	}
	inline int getCrossOverOutMouseStatus ()
	{
		return crossOverOutMouseStatus;
	}
	inline int getInOutMouseStatus ()
	{
		return inOutMouseStatus;
	}
	virtual void drawing()=0;
};

#endif // GUIBASECLASS_H