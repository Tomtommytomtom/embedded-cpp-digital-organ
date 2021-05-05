#ifndef _Virtual_Touch_Button_H
#define _Virtual_Touch_Button_H
#include "lib.h"
#include "Subject.h"

class VirtualTouchButton : public Subject{
	public:
		int x;
		int y;
		int width;
		int height;
		cDevDisplayGraphic &disp;
		cDevControlPointer &pointer;
		VirtualTouchButton(int x, int y, int length, int width,cDevDisplayGraphic &disp, cDevControlPointer &pointer);
		void Draw();
		void update();
		bool isTouched();
};
#endif
