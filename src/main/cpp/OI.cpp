#include "OI.h"

#include "Commands/HamRaisingCommand.h"
#include "Commands/HamLyingCommand.h"
#include "Commands/FootRollerCommand.h"

OI::OI() {
	joystickDriver.reset(new frc::Joystick(0));

	(new frc::JoystickButton(joystickDriver.get(), 4))->WhileHeld(new HamRaisingCommand());
	(new frc::JoystickButton(joystickDriver.get(), 2))->WhileHeld(new HamLyingCommand());
	(new frc::JoystickButton(joystickDriver.get(), 1))->WhileHeld(new FootRollerCommand(1)); //push
	(new frc::JoystickButton(joystickDriver.get(), 3))->WhileHeld(new FootRollerCommand(-0.4));
	(new frc::JoystickButton(joystickDriver.get(), 5))->WhileHeld(new FootRollerCommand(-0.05));
}

std::shared_ptr<frc::Joystick> OI::getJoystickDriver(){
	return joystickDriver;
}

double OI::getDriverRawAxis(int axis){
	return joystickDriver->GetRawAxis(axis);
}
