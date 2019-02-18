#include "Commands/HamSetpointCommand.h"

HamSetpointCommand::HamSetpointCommand(double p) {
    point=p;
	Requires(Robot::hamSubsystem.get());
}

void HamSetpointCommand::Initialize() {

}

void HamSetpointCommand::Execute() {
	// Robot::hamSubsystem->SetSetpoint(point);
}

bool HamSetpointCommand::IsFinished() {
	return true;
}

void HamSetpointCommand::End() {}

void HamSetpointCommand::Interrupted() {
	End();
}