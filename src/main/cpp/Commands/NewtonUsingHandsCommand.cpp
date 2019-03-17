#include "Commands/NewtonUsingHandsCommand.h"

NewtonUsingHandsCommand::NewtonUsingHandsCommand() {
	Requires(Robot::newtonSubsystem.get());
}

void NewtonUsingHandsCommand::Initialize() {}

void NewtonUsingHandsCommand::Execute() {
	double c=0.2;
	if(Robot::oi->getNewtonRawButton(7) && Robot::oi->getNewtonRawButton(8)){
		c=1.0;
	}
	Robot::newtonSubsystem->setLeft(Robot::oi->getNewtonRawAxis(3)*c);
	Robot::newtonSubsystem->setRight(Robot::oi->getNewtonRawAxis(1)*c);
    
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
