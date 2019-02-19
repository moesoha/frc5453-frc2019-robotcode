#include "Commands/HamRaisingCommand.h"
#include <cmath>

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
	double disto=Robot::hamSubsystem->hamDistance();
	double dist=fabs(disto);
	if(dist<5){
		return 0.08;
	}else if(dist<18){
		return 0.14;
	}else if(dist<35){
		return 0.21;
	}else if(dist<82){
		if(disto<0){
			return -0.9;
		}
		return 0.36;
	}
	return 0.3;
}