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
			if(cnt == 10000)
			{
				cnt = 0;
			}
			else
			{
			cnt++;
			}
			sp.playSound(cnt);
    }
};

//*******************************************************************
cTaskHandler taskHandler(&timer);
SoundPlayer sp(0 , dacA );
PlaySoundTask *playSoundTask = new PlaySoundTask(taskHandler,sp);

//*******************************************************************
int main(void)
{

  #ifdef USE_GRAPHIC_DISPLAY
    disp.setBackColor(cHwDisplayGraphic::Navy);
    disp.clear();
  #endif

  disp.printf(0,0,0,__DATE__ " " __TIME__);
	int frequency = 0;
  while(1)
  {
		//use joystick to adjust frequency
		switch( enc.get() )
    {
				case cDevControlEncoder::LEFT:     frequency -= 10; break;
        case cDevControlEncoder::RIGHT:    frequency += 10; break;
        case cDevControlEncoder::CTRL_DWN: frequency  = 0; break;
        default:                                     break;
    }
		sp.setFrequency(frequency);
		disp.printf(1,0,0,"Frequency: %d\t\t\t\t\t",frequency);
  }
}

//EOF
