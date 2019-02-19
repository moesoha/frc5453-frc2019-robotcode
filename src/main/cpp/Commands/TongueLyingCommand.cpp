#include "Commands/TongueLyingCommand.h"

TongueLyingCommand::TongueLyingCommand() {
	Requires(Robot::tongueSubsystem.get());
}

void TongueLyingCommand::Initialize() {}

void TongueLyingCommand::Execute() {
	Robot::tongueSubsystem->set(Robot::tongueSubsystem->set(-0.07));
}

bool TongueLyingCommand::IsFinished() {
	return false;
}

void TongueLyingCommand::End() {
	Robot::tongueSubsystem->set(0);
}

void TongueLyingCommand::Interrupted() {
	End();
}
