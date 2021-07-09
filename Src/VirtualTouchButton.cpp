#include "VirtualTouchButton.h"
#include "lib.h"
#include "Subject.h"
#include "InputEvents.h"

VirtualTouchButton::VirtualTouchButton(int x, int y, int width, int height, char* label, cDevDisplayGraphic &disp)
	: x(x),
	  y(y),
		width(width),
		height(height),
		label(label),
		disp(disp)
		{
			touched = false;
			touchedCount = 0;
		};
			
void VirtualTouchButton::draw(){
	disp.drawFrame(x,y,width,height,2,cHwDisplayGraphic::White);
	disp.drawText(x+2,y + height/2 - 8,label);
}

bool testFlag(int flags,int flag){
	return (flags & flag) == flag;
}

bool VirtualTouchButton::isTouched(InputEvents events){
	cDevControlPointer::cData event = events.pointerEvent;
	int tX = event.posX;
	int tY = event.posY;
	touched = tX > x && 
				 (tX < x + width) &&
				 tY > y &&
				 (tY < y + height) &&
				 (testFlag(event.flags,event.CTRL_DWN) || testFlag(event.flags,event.PRESSED));
	return touched;
}

void VirtualTouchButton::update(InputEvents events){
	bool prev = touched;
	bool now = isTouched(events);
	if(!prev && now){
		touchedCount++;
		this->onClick();
	}
}

void VirtualTouchButton::onClick(){
}

