#include "Commands/NewtonLovesGroundCommand.h"

NewtonLovesGroundCommand::NewtonLovesGroundCommand(bool o) {
	open=o;
}

void NewtonLovesGroundCommand::Initialize() {}

void NewtonLovesGroundCommand::Execute() {
	if(open){
		Robot::newtonSubsystem->startPushing();
	}else{
		Robot::newtonSubsystem->stopPushing();
	}
}

bool NewtonLovesGroundCommand::IsFinished() {
	return true;
}

void NewtonLovesGroundCommand::End() {}

void NewtonLovesGroundCommand::Interrupted() {
	End();
}
