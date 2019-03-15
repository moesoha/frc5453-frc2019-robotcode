#include "Commands/TongueSetCommand.h"

TongueSetCommand::TongueSetCommand(double da) {
    destAngle=da; // 相对于地面的角度
}

void TongueSetCommand::Initialize() {}

void TongueSetCommand::Execute() {
	Robot::tongueSubsystem->setFixedPosition(destAngle);
}

bool TongueSetCommand::IsFinished() {
	return true;
}

void TongueSetCommand::End() {}

void TongueSetCommand::Interrupted() {
	End();
}
