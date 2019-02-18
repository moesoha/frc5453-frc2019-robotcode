#include "Commands/ElevatorAxisCommand.h"

// should not be used!
ElevatorAxisCommand::ElevatorAxisCommand() {
	Requires(Robot::elevatorSubsystem.get());
}

void ElevatorAxisCommand::Initialize() {}

void ElevatorAxisCommand::Execute() {
	Robot::elevatorSubsystem->set(Robot::oi->getDriverRawAxis(1)*0.4);
}

bool ElevatorAxisCommand::IsFinished() {
	return false;
}

void ElevatorAxisCommand::End() {
	Robot::elevatorSubsystem->stopMotors();
}

void ElevatorAxisCommand::Interrupted() {
	End();
}
