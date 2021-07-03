#include "Tone.h"

Tone::Tone(Note n, char octave):note(n),octave(octave){}

char *Tone::toString(){
	char* ausgabe = new char[3];
	switch(note){
		case A: 	strcpy(ausgabe, "A "); break;
		case As:	strcpy(ausgabe, "As"); break;
		case B:		strcpy(ausgabe, "B "); break;
		case C:		strcpy(ausgabe, "C "); break;
		case Cs:	strcpy(ausgabe, "Cs"); break;
		case D:		strcpy(ausgabe, "D "); break;
		case Ds:	strcpy(ausgabe, "Ds"); break;
		case E: 	strcpy(ausgabe, "E "); break;
		case F: 	strcpy(ausgabe, "F "); break;
		case Fs: 	strcpy(ausgabe, "Fs"); break;
		case G: 	strcpy(ausgabe, "G "); break;
		case Gs: 	strcpy(ausgabe, "Gs"); break;
	}
	ausgabe[2] = (char)(octave + '0');
	return ausgabe;
}

void Tone::operator++(int){
	switch(note){
		case A :	note = As; break;
		case As:	note = B ; break;
		case B :	if(octave < 6)
			{
				note = C;
				++octave;
			}
			break;
		case C :	note = Cs; break;
		case Cs:	note = D ; break;
		case D :	note = Ds; break;
		case Ds:	note = E ; break;
		case E : 	note = F ; break;
		case F : 	note = Fs; break;
		case Fs: 	note = G ; break;
		case G : 	note = Gs; break;
		case Gs: 	note = A ; break;
		}
}

void Tone::operator--(int){
	switch(note){
		case A :	note = Gs;	break;
		case As:	note = A ;	break;
		case B :	note = As;	break;
		case C :		
			if(octave >1)
			{
				note = B;
				--octave;
			}
			break;
		case Cs:	note = C ;	break;
		case D :	note = Cs;	break;
		case Ds:	note = D ;	break;
		case E : 	note = Ds;	break;
		case F : 	note = E ;	break;
		case Fs: 	note = F ;	break;
		case G : 	note = Fs;	break;
		case Gs: 	note = G ;	break;
		}
}