#include "Commands/TongueContinuousKeepAngleCommand.h"

TongueContinuousKeepAngleCommand::TongueContinuousKeepAngleCommand() {
	Requires(Robot::tongueSubsystem.get());
}

void TongueContinuousKeepAngleCommand::Initialize() {}

void TongueContinuousKeepAngleCommand::Execute() {
	double output=Robot::tongueSubsystem->getFixedOutput(Robot::hamSubsystem->hamDistance(),Robot::tongueSubsystem->position());
	// Robot::tongueSubsystem->set(output);
	frc::SmartDashboard::PutNumber("Tongue Fixed Output",output);
}

bool TongueContinuousKeepAngleCommand::IsFinished() {
	return false;
}

void TongueContinuousKeepAngleCommand::End() {}

void TongueContinuousKeepAngleCommand::Interrupted() {
	End();
}
