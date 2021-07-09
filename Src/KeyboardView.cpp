#include "KeyboardView.h"
#include "UI.h"
#include "lib.h"
#include "SoundButton.h"
#include "Tone.h"

KeyboardView::KeyboardView(
				char* name,
				cDevDisplayGraphic &disp,
				SoundPlayer &sp
			): 
				UI(name,disp),
				sp(sp){};
					
void KeyboardView::build(){
	UI::build();
	for(int noteInt = C; noteInt <= B; noteInt++){
		Note note = static_cast<Note>(noteInt);
		int width = 320/B;
		int x = 0 + noteInt * width;
		Tone tone(note,1,16);
		SoundButton *btn = new SoundButton(x,240/2,width,240/2,tone.toString(),disp,tone,sp);
		buttons[noteInt] = btn;
		btn->draw();
	}
}

void KeyboardView::update(InputEvents events){
	bool keyTouched = false;
	for(int noteInt = C; noteInt <= B; noteInt++) {
		buttons[noteInt]->update(events);
		keyTouched = buttons[noteInt]->touched || keyTouched;
	}
	if(!keyTouched){
		sp.setTone(0);
	}
}

void KeyboardView::del(){
}
