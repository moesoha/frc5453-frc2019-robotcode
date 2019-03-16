#include "Commands/TongueContinuousKeepAngleCommand.h"

TongueContinuousKeepAngleCommand::TongueContinuousKeepAngleCommand() {
	Requires(Robot::tongueSubsystem.get());
}

void TongueContinuousKeepAngleCommand::Initialize() {}

void TongueContinuousKeepAngleCommand::Execute() {
	double hamPos=Robot::hamSubsystem->hamDistance();
	double tongPos=Robot::tongueSubsystem->position();
	double output=Robot::tongueSubsystem->getFixedOutput(hamPos,tongPos);
	Robot::tongueSubsystem->set(output);
	// frc::SmartDashboard::PutNumber("Ham Distance",hamPos);
	// frc::SmartDashboard::PutNumber("Tongue Distance",tongPos);
	// frc::SmartDashboard::PutNumber("Tongue Fixed Output",output);
}

bool TongueContinuousKeepAngleCommand::IsFinished() {
	return false;
}

void TongueContinuousKeepAngleCommand::End() {}

void TongueContinuousKeepAngleCommand::Interrupted() {
	End();
}
