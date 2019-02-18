#include "OI.h"

#include "Commands/HamRaisingCommand.h"
#include "Commands/HamLyingCommand.h"
#include "Commands/FootRollerCommand.h"
#include "Commands/ElevatorSetCommand.h"
#include "Commands/SuckerToggleCommand.h"

OI::OI() {
	joystickDriver.reset(new frc::Joystick(0));
	joystickOperator.reset(new frc::Joystick(1));
	joystickOperator2.reset(new frc::Joystick(2));

	(new frc::JoystickButton(joystickOperator.get(), 4))->WhileHeld(new HamRaisingCommand());
	(new frc::JoystickButton(joystickOperator.get(), 2))->WhileHeld(new HamLyingCommand());
	(new frc::JoystickButton(joystickOperator.get(), 1))->WhileHeld(new FootRollerCommand(1)); //push
	(new frc::JoystickButton(joystickOperator.get(), 3))->WhileHeld(new FootRollerCommand(-0.4));
	// (new frc::JoystickButton(joystickOperator.get(), 5))->WhileHeld(new FootRollerCommand(-0.05));

	(new frc::JoystickButton(joystickOperator.get(), 8))->WhileHeld(new SuckerToggleCommand(false));
	(new frc::JoystickButton(joystickOperator.get(), 7))->WhileHeld(new SuckerToggleCommand(true));

	(new frc::JoystickButton(joystickOperator2.get(), 1))->WhileHeld(new ElevatorSetCommand(0.8));
	(new frc::JoystickButton(joystickOperator2.get(), 2))->WhileHeld(new ElevatorSetCommand(0.5));
	(new frc::JoystickButton(joystickOperator2.get(), 3))->WhileHeld(new ElevatorSetCommand(0.2));
	(new frc::JoystickButton(joystickOperator2.get(), 4))->WhileHeld(new ElevatorSetCommand(-0.2));
	(new frc::JoystickButton(joystickOperator2.get(), 5))->WhileHeld(new ElevatorSetCommand(-0.5));
	(new frc::JoystickButton(joystickOperator2.get(), 6))->WhileHeld(new ElevatorSetCommand(-0.8));
}

std::shared_ptr<frc::Joystick> OI::getJoystickDriver(){
	return joystickDriver;
}

double OI::getDriverRawAxis(int axis){
	return joystickDriver->GetRawAxis(axis);
}

bool OI::getDriverRawButton(int id){
	return joystickDriver->GetRawButton(id);
}
