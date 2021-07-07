#include "InputEvents.h"
#include "lib.h"

InputEvents::InputEvents(
			cDevControlPointer::cData pointerEvent,
			bool buttonPressed,
			cDevControlEncoderJoystick::tEvent joystickEvent
		):
			pointerEvent(pointerEvent),
			buttonPressed(buttonPressed),
			joystickEvent(joystickEvent)
		{}

InputEvents Inputs::get(){
	return InputEvents(
				pointer.get(),
				btn.get(),
				joystick.get()
			);
}

Inputs::Inputs(
			cDevControlPointer &pointer,
			cDevDigital &btn,
			cDevControlEncoderJoystick joystick
		):
			pointer(pointer),
			btn(btn),
			joystick(joystick)
		{}
