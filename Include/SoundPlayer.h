#ifndef _SOUND_PLAYER_H
#define _SOUND_PLAYER_H

#include "lib.h"
#include "Tone.h"

//root note frequencys
#define A1	55
#define As1	58.2705
#define B1	61.7354
#define C1	32.7032
#define Cs1	34.6478
#define D1	36.7081
#define Ds1	38.8909
#define E1	41.2034
#define F1	43.6535
#define Fs1	46.2493
#define G1	48.9994
#define Gs1	51.9131



class SoundPlayer: public cTaskHandler::Task{
	
	public: // functions
	
		SoundPlayer(cTaskHandler &taskHandler, int timerFrequency, cDevAnalogOutDAC &dac);
	
		int getVolume();
		void setVolume(int value);
	
		Tone *getTone();
		void setTone(Tone *tone);
	
	private: //functions
		float calculateScalarFrequency(float frequency, char octave);
		float getFrequencyOfNote(Note n);
	
		void update();
	
	// variables
		cTaskHandler &taskHandler;
		int envelopeCnt;
		int volume;
		Tone *currentTone;
		float amplitude;
		float frequencyScalar;
		float baseFrequency;
		cDevAnalogOutDAC &dac;
		
};
#endif
