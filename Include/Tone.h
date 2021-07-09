#ifndef _TONE_H
#define _TONE_H

#include "lib.h"

enum Note{C, Cs, D, Ds, E, F, Fs, G, Gs, A, As, B};

class Tone{
public:
	static Note fromString(char* notStr){
		if(notStr == "A"){
			return A;
		}
		if(notStr == "As"){
			return As;
		}
		if(notStr == "B"){
			return B;
		}
		if(notStr == "C"){
			return C;
		}
		if(notStr == "Cs"){
			return C;
		}
		if(notStr == "D"){
			return D;
		}
		if(notStr == "Ds"){
			return Ds;
		}
		if(notStr == "E"){
			return E;
		}
		if(notStr == "F"){
			return F;
		}
		if(notStr == "Fs"){
			return Fs;
		}
		if(notStr == "G"){
			return G;
		}
		if(notStr == "Gs"){
			return Gs;
		}
	};
	
	Note note;
	char octave;
	char length; // in 16th
	
	Tone(Note n, char octave, char length);
	char *toString();
	void operator++(int);
	void operator--(int);
};
#endif