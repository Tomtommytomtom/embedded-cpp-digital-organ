#include "SoundPlayer.h"
#include <cmath>

SoundPlayer::SoundPlayer(cTaskHandler &taskHandler, int timerFrequency, cDevAnalogOutDAC &dac):
	baseFrequency(timerFrequency),
	dac(dac),
	taskHandler(taskHandler),
	Task(taskHandler)
{
	amplitude = 0x8000;
};

void SoundPlayer::update(){
	
	dac.setRaw(amplitude * std::sin(taskHandler.getTics() / frequencyScalar));
}

int SoundPlayer::getVolume(){
	return volume;
}

void SoundPlayer::setVolume(int value){
	if(value > 100){
		return;
	}
	volume = value;
	amplitude = 0xFFFF * ((float)value / 100);
}

char* SoundPlayer::getTone(){
	return toneToString();
}

void SoundPlayer::setTone(Note note, int octave){
	currentNote = note;
	currentOctave = octave;
	frequencyScalar = calculateScalarFrequency(getFrequencyOfNote(note),	octave); 
}

char* SoundPlayer::decrementTone(){
	switch(currentNote){
		case A :	setTone(Gs , currentOctave);	break;
		case As:	setTone(A , currentOctave);	break;
		case B :	setTone(As, currentOctave);	break;
		case C :		
			if(currentOctave >1)
			{
				setTone(B, --currentOctave);
			}
			break;
		case Cs:	setTone(C , currentOctave);	break;
		case D :	setTone(Cs, currentOctave);	break;
		case Ds:	setTone(D , currentOctave);	break;
		case E : 	setTone(Ds, currentOctave);	break;
		case F : 	setTone(E , currentOctave);	break;
		case Fs: 	setTone(F , currentOctave);	break;
		case G : 	setTone(Fs, currentOctave);	break;
		case Gs: 	setTone(G , currentOctave);	break;
		}
	return toneToString();
}

char* SoundPlayer::incrementTone(){
	switch(currentNote){
		case A :	setTone(As, currentOctave); break;
		case As:	setTone(B , currentOctave); break;
		case B :	if(currentOctave < 6)
			{
				setTone(C, ++currentOctave);
			}
			break;
		case C :	setTone(Cs, currentOctave); break;
		case Cs:	setTone(D , currentOctave); break;
		case D :	setTone(Ds, currentOctave); break;
		case Ds:	setTone(E , currentOctave); break;
		case E : 	setTone(F , currentOctave); break;
		case F : 	setTone(Fs, currentOctave); break;
		case Fs: 	setTone(G , currentOctave); break;
		case G : 	setTone(Gs, currentOctave); break;
		case Gs: 	setTone(A , currentOctave); break;
			
		}
	return toneToString();
}

//private
char* SoundPlayer::toneToString(){
	char* ausgabe = new char[9];
	strcpy(ausgabe, "Note: ");
	switch(currentNote){
		case A: 	strcat(ausgabe, "A "); break;
		case As:	strcat(ausgabe, "As"); break;
		case B:		strcat(ausgabe, "B "); break;
		case C:		strcat(ausgabe, "C "); break;
		case Cs:	strcat(ausgabe, "Cs"); break;
		case D:		strcat(ausgabe, "D "); break;
		case Ds:	strcat(ausgabe, "Ds"); break;
		case E: 	strcat(ausgabe, "E "); break;
		case F: 	strcat(ausgabe, "F "); break;
		case Fs: 	strcat(ausgabe, "Fs"); break;
		case G: 	strcat(ausgabe, "G "); break;
		case Gs: 	strcat(ausgabe, "Gs"); break;
	}
	ausgabe[8] = (char)(currentOctave + 48);
	return ausgabe;
}

float SoundPlayer::calculateScalarFrequency(float frequency, int octave){
	return baseFrequency / (frequency * (2 << (octave - 1)) * 6.2831);
}

float SoundPlayer::getFrequencyOfNote(Note n){
	switch(n){
		case A: 	return A1;
		case As:	return As1;
		case B:		return B1;
		case C:		return C1;
		case Cs:	return Cs1;
		case D:		return D1;
		case Ds:	return Ds1;
		case E: 	return E1;
		case F: 	return F1;
		case Fs: 	return Fs1;
		case G: 	return G1;
		case Gs: 	return Gs1;
	}
	return 0.0;
}
