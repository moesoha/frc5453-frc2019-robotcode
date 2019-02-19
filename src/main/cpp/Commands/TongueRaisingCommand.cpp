#include "Commands/TongueRaisingCommand.h"

TongueRaisingCommand::TongueRaisingCommand() {
	Requires(Robot::tongueSubsystem.get());
}

void TongueRaisingCommand::Initialize() {}

void TongueRaisingCommand::Execute() {
	Robot::tongueSubsystem->set(0.07);
}

bool TongueRaisingCommand::IsFinished() {
	return false;
}

void TongueRaisingCommand::End() {
	Robot::tongueSubsystem->set(0);
}

void TongueRaisingCommand::Interrupted() {
	End();
}
