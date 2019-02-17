#include "Commands/LegAxisCommand.h"

// should not be used!
LegAxisCommand::LegAxisCommand() {
	Requires(Robot::footSubsystem.get());
}

void LegAxisCommand::Initialize() {}

void LegAxisCommand::Execute() {
	Robot::footSubsystem->roll(Robot::oi->getDriverRawAxis(1));
	Robot::footSubsystem->ham(Robot::oi->getDriverRawAxis(3));
}

bool LegAxisCommand::IsFinished() {
	return false;
}

void LegAxisCommand::End() {
	Robot::footSubsystem->roll(0);
}

void LegAxisCommand::Interrupted() {
	End();
}
