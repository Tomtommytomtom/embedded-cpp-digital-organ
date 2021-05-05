#include "Subject.h"

void Subject::add(Observer *o){
	observer = o;
}

void Subject::notify() {
	observer->update();
}
