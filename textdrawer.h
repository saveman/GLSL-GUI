#ifndef TEXTDRAWER_H
#define TEXTDRAWER_H

#include "glslprogram.h"
#include <string>

class TextDrawer
{
private:
	static void GLPrintf(int size, const char *fmt, ...);
public:
	static void GLSLDrawText(GLSLProgram &prog, float x, float y, vec4 color, const char *text, int size);
	
};

#endif // TEXTDRAWER_H