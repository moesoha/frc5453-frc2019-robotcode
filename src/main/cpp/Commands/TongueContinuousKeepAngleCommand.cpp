#include "Commands/TongueContinuousKeepAngleCommand.h"

TongueContinuousKeepAngleCommand::TongueContinuousKeepAngleCommand() {
	Requires(Robot::tongueSubsystem.get());
}

void TongueContinuousKeepAngleCommand::Initialize() {}

void TongueContinuousKeepAngleCommand::Execute() {
	Robot::tongueSubsystem->set(Robot::tongueSubsystem->getFixedOutput(Robot::hamSubsystem->hamDistance(),Robot::tongueSubsystem->position()));
}

bool TongueContinuousKeepAngleCommand::IsFinished() {
	return false;
}

void TongueContinuousKeepAngleCommand::End() {}

void TongueContinuousKeepAngleCommand::Interrupted() {
	End();
}
