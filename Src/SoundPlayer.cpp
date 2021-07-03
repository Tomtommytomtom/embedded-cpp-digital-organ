#include "SoundPlayer.h"
#include <cmath>

SoundPlayer::SoundPlayer(cTaskHandler &taskHandler, int timerFrequency, cDevAnalogOutDAC &dac):
	baseFrequency(timerFrequency),
	dac(dac),
	taskHandler(taskHandler),
	Task(taskHandler)
{
	amplitude = 0x8000;
	currentTone = new Tone(A, 1);
}

void SoundPlayer::update(){
	if(envelopeCnt != 1)
		envelopeCnt--;
	
	dac.setRaw(amplitude * ((0.05*((float)envelopeCnt/5000)) + (0.95*std::sin(taskHandler.getTics() / frequencyScalar))));
}

int SoundPlayer::getVolume(){
	return volume;
}

void SoundPlayer::setVolume(int value){
	if(value > 100 || value < 0){
		return;
	}
	volume = value;
	amplitude = 0xFFFF * ((float)value / 100);
}

Tone *SoundPlayer::getTone(){
	return currentTone;
}

void SoundPlayer::setTone(Tone *tone){
	currentTone = tone;
	frequencyScalar = calculateScalarFrequency(getFrequencyOfNote(currentTone->note),	currentTone->octave);
	envelopeCnt = 5000;
}

//private
float SoundPlayer::calculateScalarFrequency(float frequency, char octave){
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
