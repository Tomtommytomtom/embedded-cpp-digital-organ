#include "VirtualTouchButton.h"
#include "lib.h"
#include "Subject.h"

VirtualTouchButton::VirtualTouchButton(int x, int y, int width, int height, char* label, cDevDisplayGraphic &disp, cDevControlPointer &pointer)
	: x(x),
	  y(y),
		width(width),
		height(height),
		label(label),
		disp(disp),
		pointer(pointer)
		{};
			
void VirtualTouchButton::draw(){
	disp.drawFrame(x,y,width,height,2,cHwDisplayGraphic::White);
	disp.drawText(x+2,y + height/2 - 8,label);
	disp.refresh();
}

bool VirtualTouchButton::isTouched(){
	cDevControlPointer::cData event = pointer.get();
	int tX = event.posX;
	int tY = event.posY;
	return tX > x && 
				 tX < x + width &&
				 tY > y &&
				 tY < y + height &&
				 event.flags && event.CTRL_UP;
}

void VirtualTouchButton::update(){
	if(isTouched()){
		this->onClick();
	}
}

void VirtualTouchButton::onClick(){
	disp.printf(6,0,20,"Touched button %s",label);
}

