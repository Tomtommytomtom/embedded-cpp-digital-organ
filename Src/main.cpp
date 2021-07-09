//*******************************************************************
#include <stdio.h>
#include "Module/RTOS.h"
#include "SoundButton.h"
#include "Observer.h"
#include "SoundPlayer.h"
#include "Song.h"
#include "SongPlayer.h"
#include "KeyboardView.h"
#include "SongPlayerView.h"
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
	
	Song song2("The Beat","Tom");
	
	song2.add(new SongItem(new Tone(A, 1, 4)));
	song2.add(new SongItem(new Tone(B, 1, 4)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(F, 1, 4)));
	song2.add(new SongItem(new Tone(G, 1, 8)));
	song2.add(new SongItem(new Tone(F, 1, 8)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(G, 1, 16)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(C, 1, 4)));
	song2.add(new SongItem(new Tone(G, 1, 16)));
	song2.add(new SongItem(new Tone(F, 1, 4)));
	song2.add(new SongItem(new Tone(F, 1, 4)));
	song2.add(new SongItem(new Tone(F, 1, 4)));
	song2.add(new SongItem(new Tone(F, 1, 4)));
	song2.add(new SongItem(new Tone(E, 1, 8)));
	song2.add(new SongItem(new Tone(E, 1, 8)));
	song2.add(new SongItem(new Tone(D, 1, 4)));
	song2.add(new SongItem(new Tone(D, 1, 4)));
	song2.add(new SongItem(new Tone(D, 1, 4)));
	song2.add(new SongItem(new Tone(D, 1, 4)));
	song2.add(new SongItem(new Tone(C, 1, 16)));
	
	Song song3("The Music","Tom");
	
	song3.add(new SongItem(new Tone(A, 1, 4)));
	song3.add(new SongItem(new Tone(B, 1, 4)));
	song3.add(new SongItem(new Tone(C, 1, 4)));
	song3.add(new SongItem(new Tone(D, 1, 4)));
	song3.add(new SongItem(new Tone(E, 1, 8)));
	song3.add(new SongItem(new Tone(F, 1, 8)));
	song3.add(new SongItem(new Tone(G, 1, 4)));
	song3.add(new SongItem(new Tone(G, 1, 4)));
	song3.add(new SongItem(new Tone(F, 1, 4)));
	song3.add(new SongItem(new Tone(F, 1, 4)));
	song3.add(new SongItem(new Tone(E, 1, 16)));
	song3.add(new SongItem(new Tone(E, 1, 4)));
	song3.add(new SongItem(new Tone(C, 1, 4)));
	song3.add(new SongItem(new Tone(C, 1, 4)));
	song3.add(new SongItem(new Tone(B, 1, 4)));
	song3.add(new SongItem(new Tone(B, 1, 16)));
	song3.add(new SongItem(new Tone(A, 1, 4)));
	song3.add(new SongItem(new Tone(A, 1, 4)));
	song3.add(new SongItem(new Tone(C, 1, 4)));
	song3.add(new SongItem(new Tone(F, 1, 4)));
	song3.add(new SongItem(new Tone(E, 1, 8)));
	song3.add(new SongItem(new Tone(D, 1, 8)));
	song3.add(new SongItem(new Tone(D, 1, 4)));
	song3.add(new SongItem(new Tone(D, 1, 4)));
	song3.add(new SongItem(new Tone(D, 1, 4)));
	song3.add(new SongItem(new Tone(D, 1, 4)));
	song3.add(new SongItem(new Tone(Gs, 1, 16)));
	
	cHwTimer_N   timerTakt (cHwTimer_N::TIM_0,   SongPlayer::calcCycleTime(120)); // 120 bpm
	cTaskHandler playerHadler(&timerTakt);
	
	SongPlayer player(playerHadler, &timerTakt, &sp);
	//player.setSong(&song);
	//player.start();
	
	
  //disp.printf(0,0,0,__DATE__ " " __TIME__);
	
	KeyboardView *kb = new KeyboardView("Play Sounds!",disp,sp);
	SongPlayerView *spv = new SongPlayerView("Play Songs!",disp,player);
	spv->registerSong(&song,0);
	spv->registerSong(&song2,1);
	spv->registerSong(&song3,2);
	Navigation nav(disp);
	nav.registerUI(static_cast<UI*>(kb),0);
	nav.registerUI(static_cast<UI*>(spv),1);
	nav.build();
	
	int volume = 70;
	
	Inputs inputs(pointer,btn,enc);
	
  while(1)
  {
		InputEvents events = inputs.get();
		
		nav.update(events);
			
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
		disp.refresh();
  }
}

//EOF
