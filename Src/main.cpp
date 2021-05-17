//*******************************************************************
#include <stdio.h>
#include "lib.h"
#include "Module/RTOS.h"
#include "VirtualTouchButton.h"
#include "Observer.h"
#include "SoundPlayer.h"

//*******************************************************************
#if defined _MCU_TYPE_STM32L1XX
  #include "configSTM32L1xx.h"
#elif defined _MCU_TYPE_STM32F7XX
  #include "configSTM32F7xx.h"
#elif defined _MCU_TYPE_LPC1758
		#include "configLPC1758.h"
#elif defined _MCU_TYPE_VIRTUAL
  #include "configVirtual.h"
#else
  #error "Device type not defined"
#endif

//*******************************************************************
class cTask_Example : public cTaskHandler::Task
{
  public:
    //---------------------------------------------------------------
    unsigned cnt;
    //---------------------------------------------------------------
    cTask_Example(cTaskHandler &taskHandler)
    : Task(taskHandler)
    {
      cnt = 0;
    }

  private:
    //---------------------------------------------------------------
    virtual void update(void)
    {
      cnt++;
    }
};

//This basically only calls soundPlayer.playSound() in a set interval.
class PlaySoundTask : public cTaskHandler::Task
{
  public:
    //---------------------------------------------------------------
		SoundPlayer &sp;
    int intervalMs;
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
		
    //---------------------------------------------------------------
    virtual void update(void)
    {
			cnt++;
      sp.playSound(static_cast<float>(cnt)/pubTask.getCycleTime());
    }
};

//*******************************************************************
class cRtosTask_Example : public cRTOS::Task
{
  public:
    //---------------------------------------------------------------
    cRtosTask_Example(cRTOS &rtosIn )

    : cRTOS::Task( rtosIn, 500/* stack size*/ )

    {
      sec = 0;
      Start();
    }

    //---------------------------------------------------------------
    virtual ~cRtosTask_Example()
    {
    }

    //---------------------------------------------------------------
    virtual void update( )
    {
      while( 1 )
      {
        Pause( 10 );
        if( timer.timeout() )
        {
          sec+=0.1f;
        }
      }
    }

    //---------------------------------------------------------------
    virtual void OnStop(void)
    {
    }

    //---------------------------------------------------------------
    virtual void OnStart(void)
    {
      timer.start( 100 );
    }

    //---------------------------------------------------------------
    float   sec;

    cRTOS::Timer timer;
};


//*******************************************************************
cTaskHandler  taskHandler(&timer);

//cTask_Example task_Example(taskHandler);

SoundPlayer sp(440 , dacA );
PlaySoundTask *playSoundTask = new PlaySoundTask(taskHandler,sp);


//*******************************************************************
cRTOS_RR<3> rtos( 100/*time per task [ms]*/ );

cRtosTask_Example  rtos_task_Example( rtos );

//*******************************************************************
int main(void)
{

  #ifdef USE_GRAPHIC_DISPLAY
    disp.setBackColor(cHwDisplayGraphic::Navy);
    disp.clear();
  #endif

  disp.printf(0,0,0,__DATE__ " " __TIME__);
	int frequency = 440;
  while(1)
  {
		//use joystick to adjust frequency
		switch( enc.get() )
    {
				case cDevControlEncoder::LEFT:     frequency -= 10; break;
        case cDevControlEncoder::RIGHT:    frequency += 10; break;
        case cDevControlEncoder::CTRL_DWN: frequency  = 440; break;
        default:                                     break;
    }
		sp.setFrequency(frequency);
		disp.printf(1,0,0,"Frequency: %d",frequency);
  }
}

//EOF
