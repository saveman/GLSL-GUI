#ifndef BUTTON_H
#define BUTTON_H

#include "glslprogram.h"
#include "guiBaseClass.h"

#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
using glm::vec3;

class Button : public GuiBaseClass
{
private:
	GLSLProgram* textProg;

	const char* buttonText;
	int fontSize;

	vec4 textColor;
	vec4 buttonColor;

	const char * backgroundTextureFile;
	const char * upperTextureFile;

	float pressDownOffset_x;
	float pressDownOffset_y;

	int (*onMouseOn)(string event) ;

	int drawMode;

	int x0;
	int y0;

	vec4 renderTextColor;
	vec4 renderButtonColor;

	float rotation;
	vec3 fontOffset;

public:
	
	Button(GLSLProgram* t_prog, Mouse* t_mouse, Keyboard* t_keyboard,
		int t_x, int t_y, int t_width, int t_height,
		int (*t_onMouseDown)(string event) , int (*t_onMouseHold)(string event), 
		int (*t_onMouseUp)(string event),int (*t_onMouseOver)(string event),int (*t_onMouseOut)(string event),
		const char* t_buttonText, int t_fontSize, 
		vec4 t_textColor,   vec4 t_buttonColor,
		const char * t_backgroundTextureFile, const char * t_upperTextureFile,
		float t_pressDownOffset_x, float t_pressDownOffset_y,
		int (*t_onMouseOn)(string event) ,  int t_drawMode);
	
	~Button();
	inline void  setRotation(float t_rotation)
	{
		rotation=t_rotation;
	}
	inline void  setFontOffset(vec3 t_fontOffset)
	{
		fontOffset=t_fontOffset;
	}
	inline void Button::setRenderColor (vec4& t_renderTextColor, vec4& t_renderButtonColor, vec4& t_renderFillColor) {
		renderTextColor = t_renderTextColor;
		renderButtonColor = t_renderButtonColor;
	}
	inline int  getFontSize()
	{
		return fontSize;
	}

	inline vec4&  getTextColor()
	{
		return textColor;
	}
	inline vec4&   getButtonColor()
	{
		return buttonColor;
	}

	inline float  getPressDownOffset_x()
	{
		return pressDownOffset_x;
	}
	inline float  getPressDownOffset_y()
	{
		return pressDownOffset_y;
	}
	inline vec4&  getRenderTextColor()
	{
		return renderTextColor;
	}
	inline vec4&  getRenderButtonColor()
	{
		return renderButtonColor;
	}
	inline string Button::getButtonText (){
		return buttonText;
	}

	void drawing ();
	void drawing (vec3& pos, float rot, vec3 & fontOffset);

private:
	void drawButton();
	void updateButton();
};

#endif // BUTTON_H