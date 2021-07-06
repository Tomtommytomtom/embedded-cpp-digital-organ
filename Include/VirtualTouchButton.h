#ifndef _Virtual_Touch_Button_H
#define _Virtual_Touch_Button_H
#include "lib.h"

class VirtualTouchButton{
	public:
		int x;
		int y;
		int width;
		int height;
		char* label;
		cDevDisplayGraphic &disp;
		cDevControlPointer &pointer;
		VirtualTouchButton(int x, int y, int length, int width, char *label, cDevDisplayGraphic &disp, cDevControlPointer &pointer);
		void draw();
		void update();
		virtual void onClick();
		bool isTouched();
};
#endif
