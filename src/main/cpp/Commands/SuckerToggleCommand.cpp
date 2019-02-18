#include "Commands/SuckerToggleCommand.h"

SuckerToggleCommand::SuckerToggleCommand(bool isK) {
	Requires(Robot::suckerSubsystem.get());
	isKiller=isK;
}

void SuckerToggleCommand::Initialize() {}

void SuckerToggleCommand::Execute() {
	if(!isKiller){
		Robot::suckerSubsystem->toggle();
	}else{
		Robot::suckerSubsystem->toggleKiller();
	}
}

bool SuckerToggleCommand::IsFinished() {
	return true;
}

void SuckerToggleCommand::End() {}

void SuckerToggleCommand::Interrupted() {
	End();
}
