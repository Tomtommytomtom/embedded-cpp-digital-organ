#ifndef _SUBJECT_H
#define _SUBJECT_H

#include "Observer.h"

class Subject {
	private:
		Observer *observer;
	public:
		void add(Observer *o);
		void notify();
};
#endif
