#include "keyboard.h"
#include <GL/glfw.h>
#include <stdio.h>

Keyboard::Keyboard() 
{
	resetfunction ();
}
Keyboard::~Keyboard() 
{
}
void Keyboard::updateKeyboardStatus() 
{ 
	resetfunction () ;
	bool foundKey=false;
	//0~9
	for(int key=33;key<=126;key++)
	{
		if(glfwGetKey(key)==1)
		{
			keyChar = key;
			keyStatus=0;
			foundKey=true;
			break;
		}
	}
	if(foundKey==false)
		return;

	//shift
	if(glfwGetKey(GLFW_KEY_LSHIFT)==1 || glfwGetKey(GLFW_KEY_RSHIFT)==1)
		shiftKey = 1;
	else
		shiftKey = 0;
	//control
	if(glfwGetKey(GLFW_KEY_LCTRL)==1 || glfwGetKey(GLFW_KEY_RCTRL)==1)
		controlKey = 1;
	else
		controlKey = 0;
	
	//capital character
	if(keyChar>='A' && keyChar<='Z')
		if(controlKey==1)
			keyChar=keyChar;//keep cap character
		else
		{
			if(shiftKey==0)
				keyChar+=32;
			else
				keyChar=keyChar;
		}


	printf("keyChar %c \n", keyChar);	
	//printf("shiftKey %d \n", shiftKey); 
	//printf("controlKey %d \n", controlKey); 
}
void Keyboard::setPropertes (int t_controlKey, int t_shiftKey, char t_keyChar, int t_keyStatus) {
	controlKey = controlKey;
	shiftKey = shiftKey;
	keyChar = t_keyChar;
	keyStatus = keyStatus;
}
void Keyboard::onKeyDown(int t_controlKey, int t_shiftKey, int t_keyChar) {
	setPropertes(t_controlKey, t_shiftKey, t_keyChar, 0);
}
void Keyboard::onKeyUp(int t_controlKey, int t_shiftKey, int t_keyChar) {
	setPropertes(t_controlKey, t_shiftKey, t_keyChar, 1);
}
void Keyboard::onKeyPress(int t_controlKey, int t_shiftKey, int t_keyChar) {
	setPropertes(t_controlKey, t_shiftKey, t_keyChar, 2);
}
void Keyboard::resetfunction () {
	keyChar = -1; //ASCII code
	keyStatus = -1;//up 1, down 0
	controlKey = -1; //up 1, down 0
	shiftKey = -1; //up 1, down 0
}