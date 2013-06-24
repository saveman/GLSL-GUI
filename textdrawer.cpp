#include "textdrawer.h"
#include <GL/glut.h>
#include <stdarg.h>

void TextDrawer::GLSLDrawText(GLSLProgram & prog, float x, float y, vec4 color, const char *text, int size) {	
	prog.use();
	//glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();
	//glLoadIdentity();
	prog.setUniform("TextColor", color);
	glRasterPos2f(x, y);
	GLPrintf(size, text);

	//glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();
}
void TextDrawer::GLPrintf(int size, const char *fmt, ...){

	char		text[256];								// Holds Our String
	va_list		ap;										// Pointer To List Of Arguments

	if (fmt == NULL)									// If There's No Text
		return;											// Do Nothing

	va_start(ap, fmt);									// Parses The String For Variables
	vsprintf_s(text, fmt, ap);						// And Converts Symbols To Actual Numbers
	va_end(ap);											// Results Are Stored In Text

	glDisable(GL_DEPTH_TEST);
	int len = (int) strlen(text);
	for (int i = 0; i < len; i++)
	{
		switch(size)
		{
		case 10:
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, text[i]);
			break;
		case 18:
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
			break;
		default:
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
			break;
		}
	}

}