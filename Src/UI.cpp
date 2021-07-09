#include "UI.h"

UI::UI(char* name, cDevDisplayGraphic &disp):name(name),disp(disp){}
	
void UI::build(){
	disp.drawText(10,10,0,name);
	disp.drawLine(0,30,320,30,2,cHwDisplayGraphic::White);
}