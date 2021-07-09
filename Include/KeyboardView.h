#ifndef _KEYBOARDVIEW_H
#define _KEYBOARDVIEW_H
#include "UI.h"
#include "SoundPlayer.h"
#include "SoundButton.h"
#include "lib.h"
#include "Tone.h"
#include "InputEvents.h"

class KeyboardView : public UI{
private:
	SoundPlayer &sp;
	SoundButton *buttons[Gs + 1];
public:
	KeyboardView(
			char* name,
			cDevDisplayGraphic &disp,
			SoundPlayer &sp
	);
	void build();
	void update(InputEvents events);
	void del();
};
#endif