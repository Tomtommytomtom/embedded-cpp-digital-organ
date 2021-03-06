#include "SoundButton.h"
#include "VirtualTouchButton.h"
#include "Tone.h"
#include "SoundPlayer.h"
#include "lib.h"

SoundButton::SoundButton(
			int x,
			int y,
			int width,
			int height,
			char* label,
			cDevDisplayGraphic &disp,
			Tone tone,
			SoundPlayer &sp
		):
			VirtualTouchButton(x,y,width,height,label,disp),
			tone(tone),
			sp(sp)
	{};
		
void SoundButton::onClick(){
	disp.printf(6,0,20,"Playing Sound %s",label);
	this->sp.setTone(&tone);
};