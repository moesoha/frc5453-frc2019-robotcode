#include "OI.h"

#include "Commands/HamControlCommand.h"
#include "Commands/TongueRaisingCommand.h"
#include "Commands/TongueLyingCommand.h"
#include "Commands/NewtonLovesGroundCommand.h"
#include "Commands/TongueEncoderResetCommand.h"
#include "Commands/TongueIncCommand.h"
#include "Commands/FootRollerCommand.h"
#include "Commands/ElevatorSetCommand.h"
#include "Commands/SuckerToggleCommand.h"

OI::OI() {
	joystickDriver.reset(new frc::Joystick(0));
	joystickNewton.reset(new frc::Joystick(1));
	joystickOperator.reset(new frc::Joystick(2));
	joystickOperator2.reset(new frc::Joystick(3));

	// (new frc::JoystickButton(joystickOperator.get(), 9))->WhileHeld(new TongueRaisingCommand());
	// (new frc::JoystickButton(joystickOperator.get(), 10))->WhileHeld(new TongueLyingCommand());
	(new frc::JoystickButton(joystickOperator.get(), 9))->WhileHeld(new TongueIncCommand(1));
	(new frc::JoystickButton(joystickOperator.get(), 10))->WhileHeld(new TongueIncCommand(-1));
	(new frc::JoystickButton(joystickOperator2.get(), 9))->WhileHeld(new TongueIncCommand(3));
	(new frc::JoystickButton(joystickOperator2.get(), 10))->WhileHeld(new TongueIncCommand(-3));
	(new frc::JoystickButton(joystickOperator.get(), 6))->WhileHeld(new TongueEncoderResetCommand());

	(new frc::JoystickButton(joystickOperator.get(), 3))->WhileHeld(new HamControlCommand(true,true));
	(new frc::JoystickButton(joystickOperator.get(), 4))->WhileHeld(new HamControlCommand(false,true));
	(new frc::JoystickButton(joystickOperator.get(), 5))->WhileHeld(new HamControlCommand(false,false));
	(new frc::JoystickButton(joystickOperator.get(), 1))->WhileHeld(new FootRollerCommand(1)); //push
	(new frc::JoystickButton(joystickOperator.get(), 2))->WhileHeld(new FootRollerCommand(-0.4));
	// (new frc::JoystickButton(joystickOperator.get(), 5))->WhileHeld(new FootRollerCommand(-0.05));

	(new frc::JoystickButton(joystickOperator.get(), 8))->WhenPressed(new SuckerToggleCommand(false));
	(new frc::JoystickButton(joystickOperator.get(), 8))->WhenReleased(new SuckerToggleCommand(false));
	(new frc::JoystickButton(joystickOperator.get(), 7))->WhenPressed(new SuckerToggleCommand(true));
	(new frc::JoystickButton(joystickOperator.get(), 7))->WhenReleased(new SuckerToggleCommand(true));

	(new frc::JoystickButton(joystickOperator2.get(), 8))->WhenPressed(new NewtonLovesGroundCommand(true));
	(new frc::JoystickButton(joystickOperator2.get(), 8))->WhenReleased(new NewtonLovesGroundCommand(false));

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

std::shared_ptr<frc::Joystick> OI::getJoystickNewton(){
	return joystickNewton;
}

double OI::getDriverRawAxis(int axis){
	return joystickDriver->GetRawAxis(axis);
}

bool OI::getDriverRawButton(int id){
	return joystickDriver->GetRawButton(id);
}

double OI::getNewtonRawAxis(int axis){
	return joystickNewton->GetRawAxis(axis);
}

bool OI::getNewtonRawButton(int id){
	return joystickNewton->GetRawButton(id);
}