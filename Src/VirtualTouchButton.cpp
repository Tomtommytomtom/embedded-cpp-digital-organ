#include "VirtualTouchButton.h"
#include "lib.h"
#include "Subject.h"

VirtualTouchButton::VirtualTouchButton(int x, int y, int width, int height, cDevDisplayGraphic &disp, cDevControlPointer &pointer)
	: x(x),
	  y(y),
		width(width),
		height(height),
		disp(disp),
		pointer(pointer)
		{};
			
void VirtualTouchButton::Draw(){
	disp.drawFrame(x,y,width,height,2, cHwDisplayGraphic::White	);
	disp.drawText(x + width/2 - 36,y + height/2 - 8,"Click Me!");
	disp.refresh();
}

bool VirtualTouchButton::isTouched(){
	cDevControlPointer::cData event = pointer.get();
	int tX = event.posX;
	int tY = event.posY;
	return tX > x && 
				 tX < x + width &&
				 tY > y &&
				 tY < y + height;
}

void VirtualTouchButton::update(){
	if(isTouched()){
		notify();
	}
}
