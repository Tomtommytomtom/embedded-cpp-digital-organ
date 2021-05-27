//*******************************************************************
#include <stdio.h>
#include "lib.h"
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

	bool frequencyShifted = false;
	
	sp.setVolume(70);
  disp.printf(0,0,0,__DATE__ " " __TIME__);
	int frequency = 440;
	disp.printf(1,0,0,"Frequency: %d\t\t\t\t\t",frequency);
  while(1)
  {
		//use joystick to adjust frequency
		switch( enc.get() )
    {
				case cDevControlEncoder::LEFT:     frequency -= 10; frequencyShifted = true; break;
        case cDevControlEncoder::RIGHT:    frequency += 10; frequencyShifted = true; break;
        case cDevControlEncoder::CTRL_DWN: frequency  = 0; frequencyShifted = true; break;
        default:                                     break;
    }
		sp.setFrequency(frequency);
		if(frequencyShifted)
		{
			disp.printf(1,0,0,"Frequency: %d\t\t\t\t\t",frequency);
			frequencyShifted = false;
		}
  }
}

//EOF
