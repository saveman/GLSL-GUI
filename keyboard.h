#ifndef KEYBOARD_H
#define KEYBOARD_H

class Keyboard
{
public:
	char keyChar; //ASCII code
	int keyStatus;//up 1, down 0
	int controlKey; //up 1, down 0
	int shiftKey; //up 1, down 0

	Keyboard();
	~Keyboard();
	void updateKeyboardStatus() ;
	void setPropertes (int t_controlKey, int t_shiftKey, char t_keyChar, int t_keyStatus);
	void onKeyDown(int t_controlKey, int t_shiftKey, int t_keyChar) ;
	void onKeyUp(int t_controlKey, int t_shiftKey, int t_keyChar) ;
	void onKeyPress(int t_controlKey, int t_shiftKey, int t_keyChar) ;
	void resetfunction () ;
};
#endif // KEYBOARD_H