#include "Commands/Autonomous/StillAutoCommand.h"

StillAutoCommand::StillAutoCommand() {

}

void StillAutoCommand::Initialize() {}

void StillAutoCommand::Execute() {}

bool StillAutoCommand::IsFinished() {
	return true;
}

void StillAutoCommand::End() {}

void StillAutoCommand::Interrupted() {
	End();
}
