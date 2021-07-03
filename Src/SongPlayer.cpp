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
		lengthCnt = currentItem->getTone()->length;
		isPlaying = 1;
	}

	int SongPlayer::calcCycleTime(int bpm)
	{
		//60s/min * 1000.000us/s / bpm1/min = cycleTime in us
		// /4 to get 16th
		return 60000000 / bpm / 4;
	}
	
	void SongPlayer::update(){
		if(isPlaying)
		{
			if(! --lengthCnt)
			{
				if(currentItem->getHasNext())
				{
					currentItem = currentItem->getNext();
					lengthCnt = currentItem->getTone()->length;
					sp->setTone(currentItem->getTone());
				}
				else
				{
					isPlaying = 0;
					sp->setTone(0);
				}
			}
		}
	}