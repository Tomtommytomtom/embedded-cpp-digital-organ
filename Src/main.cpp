//*******************************************************************
#include <stdio.h>
#include "Module/RTOS.h"
#include "SoundButton.h"
#include "Observer.h"
#include "SoundPlayer.h"
#include "Song.h"
#include "SongPlayer.h"
#include "KeyboardView.h"
#include "Navigation.h"
#include "InputEvents.h"

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
	
	Song song("The Sound","MLStudio");
	
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
	
	//SongPlayer player(playerHadler, &timerTakt, &sp);
	//player.setSong(&song);
	//player.start();
	
	
  disp.printf(0,0,0,__DATE__ " " __TIME__);
	
	KeyboardView *kb = new KeyboardView("Play Sounds!",disp,sp);
	Navigation nav(disp);
	nav.registerUI(static_cast<UI*>(kb),0);
	nav.build();
	
	disp.printf(1,0,0,sp.getTone()->toString());
	int volume = 70;
	
	Inputs inputs(pointer,btn,enc);
	
  while(1)
  {
		InputEvents events = inputs.get();
		
		disp.printf(1,0,20,"Volume: %d",volume);
		disp.printf(2,0,0,sp.getTone()->toString());
		
		nav.update(events);
		
		//sp.setTone(new Tone(A,1,16));
			
		//use joystick to adjust tone
		switch( events.joystickEvent )
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
