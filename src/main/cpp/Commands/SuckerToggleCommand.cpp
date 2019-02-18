#include "Commands/SuckerToggleCommand.h"

SuckerToggleCommand::SuckerToggleCommand() {
	Requires(Robot::suckerSubsystem.get());
}

void SuckerToggleCommand::Initialize() {}

void SuckerToggleCommand::Execute() {
	Robot::suckerSubsystem->toggle();
}

bool SuckerToggleCommand::IsFinished() {
	return true;
}

void SuckerToggleCommand::End() {}

void SuckerToggleCommand::Interrupted() {
	End();
}
