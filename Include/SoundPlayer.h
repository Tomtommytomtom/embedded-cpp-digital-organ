#ifndef _SOUND_PLAYER_H
#define _SOUND_PLAYER_H

#include "lib.h"

class SoundPlayer {
	private:
		int frequency;
		int angularFrequency;
	  cDevAnalogOutDAC &dac;
	public:
		SoundPlayer(int frequency, cDevAnalogOutDAC &dac);
		void playSound(float time);
		void playSound(unsigned int cnt);
		int getFrequency();
		void setFrequency(int frequency);
		
};
#endif