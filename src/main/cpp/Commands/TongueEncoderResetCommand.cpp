#include "Commands/TongueEncoderResetCommand.h"

TongueEncoderResetCommand::TongueEncoderResetCommand() {}

void TongueEncoderResetCommand::Initialize() {}

void TongueEncoderResetCommand::Execute() {
	Robot::tongueSubsystem->resetEncoder();
}

bool TongueEncoderResetCommand::IsFinished() {
	return true;
}

void TongueEncoderResetCommand::End() {}

void TongueEncoderResetCommand::Interrupted() {
	End();
}
