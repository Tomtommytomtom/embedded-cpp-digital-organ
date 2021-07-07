#ifndef _NAVIGATION_H
#define _NAVIGATION_H
#include "UI.h"
#include "InputEvents.h"
#include "lib.h"
#include "VirtualTouchButton.h"

class Navigation : public UI{
private:
	cDevDisplayGraphic &disp;
	UI *uis[1];
	VirtualTouchButton *buttons[2];
	 
public:
	UI *currentUI;
	Navigation(
		cDevDisplayGraphic &disp
	);
	void update(InputEvents events);
	void build();
	void del();
	void registerUI(UI *ui, int i);
};

class NavigationButton : public VirtualTouchButton{
public:
	Navigation *nav;
	UI *nextUI;
	NavigationButton(
			int x,
			int y,
			int width,
			int height,
			char* label,
			cDevDisplayGraphic &disp,
			Navigation *nav,
			UI *nextUI
	);
	void onClick();
};

#endif