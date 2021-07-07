#ifndef _UI_H
#define _UI_H

#include "InputEvents.h" 

class UI {
	public:
		char* name;
		UI(char* name);
		virtual void build() = 0;
		virtual void del() = 0;
		virtual void update(InputEvents events) = 0;
};
#endif