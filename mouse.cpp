#include "globalSetting.h"

#include "mouse.h"
#include <GL/glfw.h>
#include <stdio.h>

Mouse::Mouse(int& t_screenWidth, int& t_screenHeight) 
{ 
	x = -1; 
	y = -1; 
	indicatorUpDown=-1;

	screenWidth=t_screenWidth;
	screenHeight=t_screenHeight;

	screenX=0.0;
	screenY=0.0;
}
Mouse::~Mouse()
{
}
void Mouse::updateScreenCoordinate(bool pixelCoodinate)
{
	if(pixelCoodinate)
	{
		screenX=x;
	    screenY=WIN_HEIGHT-y;
	}
	else
	{
		screenX=(float)x/((float)screenWidth)*2-1;
		screenY=-(float)y/((float)screenHeight)*2+1;
	}

}
void Mouse::setPos (int t_x, int t_y) 
{ 
	x = t_x; 
	y = t_y; 
	//updateScreenCoordinate();
}
void Mouse::setIndicatorUpDown(int t_updown) 
{ 
	indicatorUpDown = t_updown; 
}
void Mouse::updateMouseStatus() 
{ 
	glfwGetMousePos(&x, &y);
	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_1)==1)
		onMouseDown(x, y) ;
	else if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_1)==0)
		onMouseUp(x, y) ;

	updateScreenCoordinate(true);
	//printf("xpos %d  ypos %d \n", x, y);
	//printf("xpos %f  ypos %f \n", screenX, screenY);
	//printf("MouseButton %d \n", indicatorUpDown); 
}
void Mouse::onMouseDown(int t_x, int t_y) 
{
	setIndicatorUpDown(0);
	setPos(t_x, t_y);
}
void Mouse::onMouseUp(int t_x, int t_y) 
{
	setIndicatorUpDown(1);
	setPos(t_x, t_y);
}
void Mouse::reset () {
	indicatorUpDown = -1; //up 1, down 0
}