#ifndef _SOUND_PLAYER_H
#define _SOUND_PLAYER_H

#include "lib.h"

class SoundPlayer {
	private:
		int volume;
		int frequency;
	  float amplitude;
		float frequencyScalar;
		unsigned int baseFrequency;
	  cDevAnalogOutDAC &dac;
	public:
		SoundPlayer(int timerFrequency, cDevAnalogOutDAC &dac);
	
		void playSound(float time);
		void playSound(unsigned int cnt);
	
		int getVolume();
	  void setVolume(int value);
	
		int getFrequency();
		void setFrequency(int frequency);
		
};
#endif