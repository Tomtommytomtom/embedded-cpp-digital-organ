#include "SongPlayerView.h"
#include "UI.h"
#include "lib.h"
#include "SoundButton.h"
#include "Tone.h"

SongButton::SongButton(
			int x,
			int y,
			int width,
			int height,
			cDevDisplayGraphic &disp,
			Song *song,
			SongPlayer &sp
		):
			VirtualTouchButton(x,y,width,height,"",disp),
			song(song),
			sp(sp)
	{
		VirtualTouchButton::label = song->name;
	};

void SongButton::onClick(){
	sp.setSong(song);
	sp.start();
}

SongPlayerView::SongPlayerView(
				char* name,
				cDevDisplayGraphic &disp,
				SongPlayer &sp
			): 
				UI(name,disp),
				songCounts(3),
				sp(sp)
			{};


void SongPlayerView::updateCurrentSongPlaying(){
	disp.drawText(0,240-20,0,"Currently Playing: %s",sp.getSong()->name);
	disp.drawLine(0,240-30,320,240-30,2,cHwDisplayGraphic::White);
}

void SongPlayerView::build(){
	UI::build();
	int x = 20;
	int y = 40;
	int width = 280;
	int height = 40;
	for(int i = 0; i < songCounts;i++){
		SongButton *sb = new SongButton(x,y+height*i+10,width,height,disp,songs[i],sp);
		buttons[i] = sb;
	}
	
	for(int i = 0; i < songCounts;i++){
		buttons[i]->draw();
	}
}

void SongPlayerView::update(InputEvents events){
	bool buttonTouched = false;
	for(int i = 0; i< songCounts;i++){
		buttons[i]->update(events);
		buttonTouched = buttonTouched || buttons[i]->touched;
	}
	if(buttonTouched){
		updateCurrentSongPlaying();
	}
}

void SongPlayerView::del(){
}

void SongPlayerView::registerSong(Song *song, int index){
	songs[index] = song;
}
