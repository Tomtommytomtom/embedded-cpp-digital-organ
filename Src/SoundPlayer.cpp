#include "SoundPlayer.h"
#include "lib.h"
#include <cmath>

SoundPlayer::SoundPlayer(int timerFrequency, cDevAnalogOutDAC &dac): baseFrequency(timerFrequency), dac(dac) {
	amplitude = 0x8000;
};
	
void SoundPlayer::playSound(unsigned int cnt){
	if(frequency == 0)
	{
		dac.setRaw(0);
		return;
	}
	dac.setRaw(amplitude * std::sin(6.282 * cnt / frequencyScalar));
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

int SoundPlayer::getFrequency(){
	return frequency;
};

void SoundPlayer::setFrequency(int value){
	frequency = value;
	frequencyScalar = (float)baseFrequency / frequency;
}