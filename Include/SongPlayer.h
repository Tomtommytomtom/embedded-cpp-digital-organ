#ifndef _SONG_PLAYER_H
#define _SONG_PLAYER_H

#include "lib.h"
#include "SoundPlayer.h"
#include "Song.h"

class SongPlayer: public cTaskHandler::Task
{
	
private:
	cHwTimer_N *timer;
	cTaskHandler &taskHandler;
	Song *song;
	SongItem *currentItem;
	SoundPlayer *sp;
	char isPlaying;
	
	
public:
	SongPlayer(cTaskHandler &taskHandler, cHwTimer_N *timer, SoundPlayer *sp);

	Tone *getCurrentTone(); 
	
	void setSong(Song *s);
	Song *getSong();

	void start();

	static int calcCycleTime(int bpm);
private:
	
	void update(void);
	
};


#endif