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
void SoundPlayer::playSound(unsigned int cnt){
	float amplitude = 0x1000;
	float offset = 0x8000;
	dac.setRaw(amplitude * std::sin(6.282 * (float)cnt / (10000.0 / (float)frequency) + offset));
}

int SoundPlayer::getFrequency(){
	return frequency;
};

void SoundPlayer::setFrequency(int value){
	frequency = value;
	angularFrequency = 6.282 * value;
}

