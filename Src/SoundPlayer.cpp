#include "SoundPlayer.h"
#include "lib.h"
#include <cmath>

SoundPlayer::SoundPlayer(int frequency, cDevAnalogOutDAC &dac): frequency(frequency), dac(dac) {};
	
void SoundPlayer::playSound(float time){
	float amplitude = 0x1000;
	float offset = 0x8000;
	float x = amplitude * std::sin(6.282 * frequency * time) + offset;
	dac.setRaw(x);
}

int SoundPlayer::getFrequency(){
	return frequency;
};

void SoundPlayer::setFrequency(int value){
	frequency = value;
	angularFrequency = 6.282 * value;
}

