#include "Commands/TongueIncCommand.h"

TongueIncCommand::TongueIncCommand(double d) {
    delta=d;
}

TongueIncCommand::TongueIncCommand(double d,double maxPosition) {
    delta=d;
	specificMaxPosition=maxPosition;
	stopAtSpecificPosition=true;
}

void TongueIncCommand::Initialize() {}

void TongueIncCommand::Execute() {
	Robot::tongueSubsystem->incFixedPosition(delta);
}

bool TongueIncCommand::IsFinished() {
	if(stopAtSpecificPosition){
		return Robot::tongueSubsystem->getFixedPosition()>=specificMaxPosition;
	}
	return false;
}

void TongueIncCommand::End() {}

void TongueIncCommand::Interrupted() {
	End();
}
