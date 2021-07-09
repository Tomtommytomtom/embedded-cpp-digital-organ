#ifndef _Virtual_Touch_Button_H
#define _Virtual_Touch_Button_H
#include "lib.h"
#include "InputEvents.h"

class VirtualTouchButton{
	public:
		int x;
		int y;
		int width;
		int height;
		char* label;
		bool touched;
		int touchedCount;
		cDevDisplayGraphic &disp;
		VirtualTouchButton(int x, int y, int length, int width, char *label, cDevDisplayGraphic &disp);
		void draw();
		void update(InputEvents events);
		virtual void onClick();
		bool isTouched(InputEvents events);
};
#endif
