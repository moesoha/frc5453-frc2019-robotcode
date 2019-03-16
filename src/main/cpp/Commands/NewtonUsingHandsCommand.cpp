#include "Commands/NewtonUsingHandsCommand.h"

NewtonUsingHandsCommand::NewtonUsingHandsCommand() {
	Requires(Robot::newtonSubsystem.get());
}

void NewtonUsingHandsCommand::Initialize() {}

void NewtonUsingHandsCommand::Execute() {
	Robot::newtonSubsystem->setLeft(Robot::oi->getNewtonRawAxis(3)*0.2);
	Robot::newtonSubsystem->setRight(Robot::oi->getNewtonRawAxis(1)*0.2);
    
}

bool NewtonUsingHandsCommand::IsFinished() {
	return false;
}

void NewtonUsingHandsCommand::End() {
	Robot::newtonSubsystem->stopMotors();
}

void NewtonUsingHandsCommand::Interrupted() {
	End();
}
