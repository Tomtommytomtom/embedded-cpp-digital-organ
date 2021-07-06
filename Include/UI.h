#ifndef _UI_H
#define _UI_H


class UI {
	public:
		char* name;
		UI(char* name);
		virtual void build() = 0;
		virtual void del() = 0;
		virtual void update() = 0;
};
#endif