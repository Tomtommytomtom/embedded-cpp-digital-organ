#ifndef _KEYBOARDVIEW_H
#define _KEYBOARDVIEW_H
#include "UI.h"
#include "SoundPlayer.h"
#include "SoundButton.h"
#include "lib.h"
#include "Tone.h"

class KeyboardView : public UI{
private:
	cDevDisplayGraphic &disp;
	cDevControlPointer &pointer;
	SoundPlayer &sp;
	SoundButton *buttons[Gs + 1];
public:
	KeyboardView(
			char* name,
			cDevDisplayGraphic &disp,
			cDevControlPointer &pointer,
			SoundPlayer &sp
	);
	void build();
	void update();
	void del();
};
#endif