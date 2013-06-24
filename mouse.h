#ifndef MOUSE_H
#define MOUSE_H

class Mouse
{
public:
    int x;
    int y;
	int screenWidth;
    int screenHeight;
	float screenX;
	float screenY;
    int indicatorUpDown; //up 1, down 0

	Mouse(int & t_screenWidth, int & t_screenHeight) ;
	~Mouse();

    void setPos (int t_x, int t_y) ;
    void setIndicatorUpDown(int t_updown) ;
	void updateMouseStatus();
    void onMouseDown(int t_x, int t_y) ;
    void onMouseUp(int t_x, int t_y);
    void onMouseMove(int t_x, int t_y) ;
    void reset ();

private:
	void updateScreenCoordinate();
};
#endif // MOUSE_H