#ifndef _SOUNDBUTTON_H
#define _SOUNDBUTTON_H

#include "lib.h"
#include "VirtualTouchButton.h"
#include "Tone.h"
#include "SoundPlayer.h"

class SoundButton : public VirtualTouchButton{
	public:
		SoundButton(
			int x,
			int y,
			int width,
			int height,
			char* label,
			cDevDisplayGraphic &disp,
			cDevControlPointer &pointer,
			Tone tone,
			SoundPlayer &sp
		); 
		SoundPlayer &sp;
		Tone tone;
		void onClick();
};
#endif