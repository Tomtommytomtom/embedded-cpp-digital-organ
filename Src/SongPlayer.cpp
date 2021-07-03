#include "SongPlayer.h"

SongPlayer::SongPlayer(cTaskHandler &taskHandler, cHwTimer_N *timer, SoundPlayer *sp):
	timer(timer),
	taskHandler(taskHandler),
	Task(taskHandler),
	sp(sp)
	{
		timer = 0;
	}

	
	Tone *SongPlayer::getCurrentTone(){
		return currentItem->getTone();
	}
	
	void SongPlayer::setSong(Song *s){
		song = s;
	}
	
	Song *SongPlayer::getSong(){
		return song;
	}
	
	void SongPlayer::start(){
		currentItem = song->getFirst();
		sp->setTone(currentItem->getTone());
		isPlaying = 1;
	}

	int SongPlayer::calcCycleTime(int bpm)
	{
		//60s/min * 1000.000us/s / bpm1/min = cycleTime in us
		return 60000000 / bpm;
	}
	
	void SongPlayer::update(){
		if(isPlaying)
		{
			if(currentItem->getHasNext())
			{
				currentItem = currentItem->getNext();
				sp->setTone(currentItem->getTone());
			}
			else
			{
				isPlaying = 0;
			}
		}
	}