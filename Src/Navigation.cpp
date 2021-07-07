#include "Navigation.h"
#include "VirtualTouchButton.h"
#include "UI.h"
#include "InputEvents.h"

NavigationButton::NavigationButton(
	int x,
	int y,
	int width,
	int height,
	char* label,
	cDevDisplayGraphic &disp,
	Navigation *nav,
	UI *nextUI
) :
	VirtualTouchButton(x,y,width,height,label,disp),
	nav(nav),
	nextUI(nextUI)
{
};
				
void NavigationButton::onClick(){
	disp.printf(3,0,0,"CLICKED");
	nav->currentUI->del();
	nav->currentUI = nextUI;
	disp.clear();
	nav->currentUI->build();
}

Navigation::Navigation(cDevDisplayGraphic &disp)
: UI("Navigation"),
	disp(disp)
{
	currentUI = static_cast<UI*>(this);
}

void Navigation::registerUI(UI *ui, int i){
	uis[i] = ui;
}

void Navigation::build(){
	int x = 20;
	int y = 100;
	int width = 280;
	int height = 40;
	for(int i = 0; i < 1;i++){
		disp.printf(4,0,0,uis[i]->name);
		NavigationButton *btn = new NavigationButton(x,y,width,height*(i+1),uis[i]->name,disp,this,uis[i]);
		btn->draw();
		buttons[i] = btn;
	}
}

void Navigation::update(InputEvents events){
	if(events.buttonPressed){
		currentUI->del();
		currentUI = this;
		disp.clear();
		currentUI->build();
		return;
	}
	if(currentUI == static_cast<UI*>(this)){
		for(int i = 0; i < 1;i++){
			buttons[i]->update(events);
		}
	} else {
		currentUI->update(events);
	}
}

void Navigation::del(){
}




