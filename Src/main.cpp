//*******************************************************************
#include <stdio.h>
#include "Module/RTOS.h"
#include "VirtualTouchButton.h"
#include "Observer.h"
#include "SoundPlayer.h"

//*******************************************************************

#if defined _MCU_TYPE_LPC1758
  #include "configLPC1758.h"
#elif defined _MCU_TYPE_VIRTUAL
  #include "configVirtual.h"
#else
  #error "Device type not defined"
#endif

//This basically only calls soundPlayer.playSound() in a set interval.
class PlaySoundTask : public cTaskHandler::Task
{
  public:
    //---------------------------------------------------------------
		SoundPlayer &sp;
		unsigned cnt;
		cTaskHandler &pubTask;
    //---------------------------------------------------------------
    PlaySoundTask(cTaskHandler &taskHandler,SoundPlayer &sp)
    : Task(taskHandler),
			pubTask(taskHandler),
			sp(sp)
    {
			cnt = 0;
		};
  private:
    virtual void update(void)
    {
			cnt++;
			sp.playSound(cnt);
    }
};

//*******************************************************************
cTaskHandler taskHandler(&timer);
SoundPlayer sp(1.0/timer.getCycleTime() * 1000000 , dacA);
PlaySoundTask *playSoundTask = new PlaySoundTask(taskHandler,sp);

//*******************************************************************
int main(void)
{
  #ifdef USE_GRAPHIC_DISPLAY
    disp.setBackColor(cHwDisplayGraphic::Navy);
    disp.clear();
  #endif
	
	sp.setVolume(70);
  disp.printf(0,0,0,__DATE__ " " __TIME__);
	sp.setTone(SoundPlayer::A, 1);
	disp.printf(1,0,0,sp.getTone());
  while(1)
  {
		//use joystick to adjust tone
		switch( enc.get() )
    {
				case cDevControlEncoder::LEFT:
					disp.printf(1,0,0,sp.decrementTone());
					break;
        case cDevControlEncoder::RIGHT:
					disp.printf(1,0,0,sp.incrementTone());
					break;
        case cDevControlEncoder::CTRL_DWN: 
					sp.setTone(SoundPlayer::A, 1); 
					disp.printf(1,0,0,sp.getTone()); 
					break;
        default:
					break;
    }
  }
}

//EOF
