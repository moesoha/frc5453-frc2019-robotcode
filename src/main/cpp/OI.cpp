#include "OI.h"

#include "Commands/HamRaisingCommand.h"
#include "Commands/FootRollerClockwiseCommand.h"

OI::OI() {
	joystickDriver.reset(new frc::Joystick(0));

	(new frc::JoystickButton(joystickDriver.get(), 4))->WhileHeld(new HamRaisingCommand(-0.3));
	(new frc::JoystickButton(joystickDriver.get(), 2))->WhileHeld(new HamRaisingCommand(0.3));
	(new frc::JoystickButton(joystickDriver.get(), 1))->WhileHeld(new FootRollerClockwiseCommand(1)); //push
	(new frc::JoystickButton(joystickDriver.get(), 3))->WhileHeld(new FootRollerClockwiseCommand(-0.4));
	(new frc::JoystickButton(joystickDriver.get(), 5))->WhileHeld(new FootRollerClockwiseCommand(-0.05));
}

std::shared_ptr<frc::Joystick> OI::getJoystickDriver(){
	return joystickDriver;
}

double OI::getDriverRawAxis(int axis){
	return joystickDriver->GetRawAxis(axis);
}
