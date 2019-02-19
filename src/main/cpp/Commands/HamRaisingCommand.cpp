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
	// ham 到达一定位置，并且 tongue 的位置不正确的时候强行 finish
	// if(Robot::hamSubsystem->hamDistance()<30 && Robot::tongueSubsystem->position()>120){
	// 	return true;
	// }
	return false;
}

void HamRaisingCommand::End() {
    Robot::hamSubsystem->softStop();
}

void HamRaisingCommand::Interrupted() {
	End();
}

double HamRaisingCommand::generateOutputPercent(){
	double dist=Robot::hamSubsystem->hamDistance();
	if(dist<3){
		return 0;
	}else if(dist<5){
		return 0.05;
	}else if(dist<18){
		return 0.10;
	}else if(dist<35){
		return 0.21;
	}else if(dist<82){
		return 0.36;
	}
	return 0.3;
}