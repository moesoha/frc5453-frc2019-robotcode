#include "Commands/FootRollerCommand.h"

FootRollerCommand::FootRollerCommand(double s) {
    speed=s;
	Requires(Robot::footSubsystem.get());
}

void FootRollerCommand::Initialize() {

}

void FootRollerCommand::Execute() {
	Robot::footSubsystem->roll(speed);
}

bool FootRollerCommand::IsFinished() {
	return false;
}

void FootRollerCommand::End() {
	Robot::footSubsystem->roll(0);
}

void FootRollerCommand::Interrupted() {
	End();
}
