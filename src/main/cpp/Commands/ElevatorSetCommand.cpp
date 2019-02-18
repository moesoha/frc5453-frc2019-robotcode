#include "Commands/ElevatorSetCommand.h"

ElevatorSetCommand::ElevatorSetCommand(double s) {
    speed=s;
	Requires(Robot::elevatorSubsystem.get());
}

void ElevatorSetCommand::Initialize() {}

void ElevatorSetCommand::Execute() {
	Robot::elevatorSubsystem->set(speed);
}

bool ElevatorSetCommand::IsFinished() {
	return false;
}

void ElevatorSetCommand::End() {
	Robot::elevatorSubsystem->softStop();
	// Robot::elevatorSubsystem->stopMotors();
}

void ElevatorSetCommand::Interrupted() {
	End();
}
