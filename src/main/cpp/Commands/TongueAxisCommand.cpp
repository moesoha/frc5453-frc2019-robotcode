#include "Commands/TongueAxisCommand.h"

// should not be used!
TongueAxisCommand::TongueAxisCommand() {
	Requires(Robot::tongueSubsystem.get());
}

void TongueAxisCommand::Initialize() {}

void TongueAxisCommand::Execute() {
	Robot::tongueSubsystem->set(Robot::oi->getDriverRawAxis(1)*0.6);
}

bool TongueAxisCommand::IsFinished() {
	return false;
}

void TongueAxisCommand::End() {
	Robot::tongueSubsystem->set(0);
}

void TongueAxisCommand::Interrupted() {
	End();
}
