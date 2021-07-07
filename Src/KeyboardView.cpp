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
				UI(name),
				disp(disp),
				sp(sp){};
					
void KeyboardView::build(){
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
	int keyTouched;
	for(int noteInt = C; noteInt <= B; noteInt++) {
		buttons[noteInt]->update(events);
		keyTouched = buttons[noteInt]->isTouched(events) || keyTouched;
	}
	disp.printf(4,0,0,"x:%d , y:%d, delta; %d",events.pointerEvent.posX,events.pointerEvent.posY,events.pointerEvent);
	disp.printf(5,0,0,"%d",keyTouched);
	if(events.pointerEvent.flags && events.pointerEvent.CTRL_UP){
		sp.setTone(0);
	}
}

void KeyboardView::del(){
	for(int noteInt = C; noteInt < B/2+1; noteInt = noteInt + 2) {
		delete buttons[noteInt];
	}
}
