//*******************************************************************
#include <stdio.h>
#include "Module/RTOS.h"
#include "VirtualTouchButton.h"
#include "Observer.h"
#include "SoundPlayer.h"
#include "Song.h"
#include "SongPlayer.h"

//*******************************************************************

#if defined _MCU_TYPE_LPC1758
  #include "configLPC1758.h"
#elif defined _MCU_TYPE_VIRTUAL
  #include "configVirtual.h"
#else
  #error "Device type not defined"
#endif

//*******************************************************************
cTaskHandler taskHandler(&timerSound);
SoundPlayer sp(taskHandler, 1.0/timerSound.getCycleTime() * 1000000 , dacA);

//*******************************************************************
int main(void)
{
  #ifdef USE_GRAPHIC_DISPLAY
    disp.setBackColor(cHwDisplayGraphic::Navy);
    disp.clear();
  #endif
	
	Song song;
	
	song.add(new SongItem(new Tone(C, 1, 4)));
	song.add(new SongItem(new Tone(D, 1, 4)));
	song.add(new SongItem(new Tone(E, 1, 4)));
	song.add(new SongItem(new Tone(F, 1, 4)));
	song.add(new SongItem(new Tone(G, 1, 8)));
	song.add(new SongItem(new Tone(G, 1, 8)));
	song.add(new SongItem(new Tone(A, 1, 4)));
	song.add(new SongItem(new Tone(A, 1, 4)));
	song.add(new SongItem(new Tone(A, 1, 4)));
	song.add(new SongItem(new Tone(A, 1, 4)));
	song.add(new SongItem(new Tone(G, 1, 16)));
	song.add(new SongItem(new Tone(A, 1, 4)));
	song.add(new SongItem(new Tone(A, 1, 4)));
	song.add(new SongItem(new Tone(A, 1, 4)));
	song.add(new SongItem(new Tone(A, 1, 4)));
	song.add(new SongItem(new Tone(G, 1, 16)));
	song.add(new SongItem(new Tone(F, 1, 4)));
	song.add(new SongItem(new Tone(F, 1, 4)));
	song.add(new SongItem(new Tone(F, 1, 4)));
	song.add(new SongItem(new Tone(F, 1, 4)));
	song.add(new SongItem(new Tone(E, 1, 8)));
	song.add(new SongItem(new Tone(E, 1, 8)));
	song.add(new SongItem(new Tone(D, 1, 4)));
	song.add(new SongItem(new Tone(D, 1, 4)));
	song.add(new SongItem(new Tone(D, 1, 4)));
	song.add(new SongItem(new Tone(D, 1, 4)));
	song.add(new SongItem(new Tone(C, 1, 16)));
	
	cHwTimer_N   timerTakt (cHwTimer_N::TIM_0,   SongPlayer::calcCycleTime(120)); // 120 bpm
	cTaskHandler playerHadler(&timerTakt);
	
	SongPlayer player(playerHadler, &timerTakt, &sp);
	player.setSong(&song);
	player.start();
	
	
  disp.printf(0,0,0,__DATE__ " " __TIME__);
	
	disp.printf(1,0,0,sp.getTone()->toString());
	int volume = 70;
  while(1)
  {
		disp.printf(1,0,20,"Volume: %d",volume);
		disp.printf(2,0,0,player.getCurrentTone()->toString());
		if(btn.get())
		{
			disp.printf(5,0,0,"hi");
			//start song
		}
			
		//use joystick to adjust tone
		switch( enc.get() )
    {
				case cDevControlEncoder::LEFT:
					sp.setVolume(volume--);
					break;
        case cDevControlEncoder::RIGHT:
					sp.setVolume(volume++);
					break;
        case cDevControlEncoder::CTRL_DWN:
					break;
        default:
					break;
    }
  }
}

//EOF
