#ifndef _TONE_H
#define _TONE_H

#include "lib.h"

enum Note{A, As, B, C, Cs, D, Ds, E, F, Fs, G, Gs};

class Tone{
public:
	Note note;
	char octave;
	
	Tone(Note n, char octave);
	char *toString();
	void operator++(int);
	void operator--(int);
};
#endif