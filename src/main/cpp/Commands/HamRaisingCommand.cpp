#include "Commands/HamRaisingCommand.h"

HamRaisingCommand::HamRaisingCommand(double s) {
    speed=s;
	Requires(Robot::footSubsystem.get());
}

void HamRaisingCommand::Initialize() {

}

void HamRaisingCommand::Execute() {
	Robot::footSubsystem->ham(speed);
}

bool HamRaisingCommand::IsFinished() {
	return false;
}

void HamRaisingCommand::End() {
    Robot::footSubsystem->ham(0);
}

void HamRaisingCommand::Interrupted() {
	End();
}
