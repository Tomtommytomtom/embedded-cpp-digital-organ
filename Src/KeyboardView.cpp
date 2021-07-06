#include "KeyboardView.h"
#include "UI.h"
#include "lib.h"
#include "SoundButton.h"
#include "Tone.h"

KeyboardView::KeyboardView(
				char* name,
				cDevDisplayGraphic &disp,
				cDevControlPointer &pointer,
				SoundPlayer &sp
			): 
				UI(name),
				disp(disp),
				pointer(pointer),
				sp(sp){};
					
void KeyboardView::build(){
	for(int noteInt = A; noteInt <= Gs; noteInt++){
		Note note = static_cast<Note>(noteInt);
		int width = 320/Gs;
		int x = 0 + noteInt * width;
		Tone tone(note,1,16);
		SoundButton *btn = new SoundButton(x,240/2,width,240/2,tone.toString(),disp,pointer,tone,sp);
		buttons[noteInt] = btn;
		btn->draw();
	}
}

void KeyboardView::update(){
	int keyTouched;
	for(int noteInt = A; noteInt <= Gs; noteInt++) {
		buttons[noteInt]->update();
		keyTouched = buttons[noteInt]->isTouched() || keyTouched;
	}
	disp.printf(4,0,0,"x:%d , y:%d, delta; %d",pointer.get().posX,pointer.get().posY,pointer.get());
	disp.printf(5,0,0,"%d",keyTouched);
	if(pointer.get().flags && pointer.get().CTRL_UP){
		sp.setTone(0);
	}
}

void KeyboardView::del(){
	for(int noteInt = A; noteInt < Gs/2+1; noteInt = noteInt + 2) {
		delete buttons[noteInt];
	}
}
