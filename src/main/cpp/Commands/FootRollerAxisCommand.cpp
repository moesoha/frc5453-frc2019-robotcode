#include "Commands/FootRollerAxisCommand.h"

// should not be used!
FootRollerAxisCommand::FootRollerAxisCommand() {
	Requires(Robot::footSubsystem.get());
}

void FootRollerAxisCommand::Initialize() {}

void FootRollerAxisCommand::Execute() {
	Robot::footSubsystem->roll(Robot::oi->getDriverRawAxis(1));
}

bool FootRollerAxisCommand::IsFinished() {
	return false;
}

void FootRollerAxisCommand::End() {
	Robot::footSubsystem->roll(0);
}

void FootRollerAxisCommand::Interrupted() {
	End();
}
