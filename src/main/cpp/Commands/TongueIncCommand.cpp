#include "Commands/TongueIncCommand.h"

TongueIncCommand::TongueIncCommand(double d) {
    delta=d;
}

void TongueIncCommand::Initialize() {}

void TongueIncCommand::Execute() {
	Robot::tongueSubsystem->incFixedPosition(delta);
}

bool TongueIncCommand::IsFinished() {
	return false;
}

void TongueIncCommand::End() {}

void TongueIncCommand::Interrupted() {
	End();
}
