#ifndef _UI_H
#define _UI_H

#include "InputEvents.h" 
#include "lib.h"

class UI {
	public:
		char* name;
		cDevDisplayGraphic &disp;
		UI(char* name,cDevDisplayGraphic &disp);
		virtual void build();
		virtual void del() = 0;
		virtual void update(InputEvents events) = 0;
};
#endif