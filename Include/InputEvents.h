#ifndef _INPUTEVENTS_H
#define _INPUTEVENTS_H
#include "lib.h"

struct InputEvents{
		cDevControlPointer::cData pointerEvent;
		bool buttonPressed;
		cDevControlEncoderJoystick::tEvent joystickEvent;
		InputEvents(
			cDevControlPointer::cData pointerEvent,
			bool buttonPressed,
			cDevControlEncoderJoystick::tEvent joystickEvent
		);
};

struct Inputs{
		cDevControlPointer &pointer;
		cDevDigital &btn;
		cDevControlEncoderJoystick joystick;
		Inputs(
			cDevControlPointer &pointer,
			cDevDigital &btn,
			cDevControlEncoderJoystick joystick
		);
		InputEvents get();
};

#endif