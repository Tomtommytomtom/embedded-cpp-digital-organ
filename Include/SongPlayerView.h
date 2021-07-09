#ifndef _SONGPLAYERVIEW_H
#define _SONGPLAYERVIEW_H
#include "UI.h"
#include "SongPlayer.h"
#include "Song.h"
#include "VirtualTouchButton.h"
#include "lib.h"
#include "InputEvents.h"

class SongButton : public VirtualTouchButton {
	public:
		Song *song;
		SongButton(
			int x,
			int y,
			int width,
			int height,
			cDevDisplayGraphic &disp,
			Song *song,
			SongPlayer &sp
		); 
		SongPlayer &sp;
		void onClick();
};

class SongPlayerView : public UI{
private:
	SongPlayer &sp;
	Song *songs[3];
	int songCounts;
	VirtualTouchButton *buttons[3];
public:
	SongPlayerView(
			char* name,
			cDevDisplayGraphic &disp,
			SongPlayer &sp
	);
	void updateCurrentSongPlaying();
	void build();
	void update(InputEvents events);
	void del();
	void registerSong(Song *song, int index);
};
#endif