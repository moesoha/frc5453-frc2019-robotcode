#include "Commands/HamRaisingCommand.h"

HamRaisingCommand::HamRaisingCommand() {
	Requires(Robot::hamSubsystem.get());
}

void HamRaisingCommand::Initialize() {

}

void HamRaisingCommand::Execute() {
	Robot::hamSubsystem->set(generateOutputPercent());
}

bool HamRaisingCommand::IsFinished() {
	return false;
}

void HamRaisingCommand::End() {
    Robot::hamSubsystem->stopMotors();
}

void HamRaisingCommand::Interrupted() {
	End();
}

double HamRaisingCommand::generateOutputPercent(){
	double dist=Robot::hamSubsystem->hamDistance();
	if(dist<5){
		return 0;
	}else if(dist<25){
		return 0.05;
	}else if(dist<100){
		return 0.10;
	}else if(dist<200){
		return 0.20;
	}else if(dist<500){
		return 0.38;
	}
	return 0.3;
}