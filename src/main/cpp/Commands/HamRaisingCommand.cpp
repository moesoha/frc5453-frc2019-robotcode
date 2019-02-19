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
    double dist=Robot::hamSubsystem->hamDistance();
	if(dist>5){
        Robot::hamSubsystem->softStop();
    }else{
        Robot::hamSubsystem->softBackStop();
    }
}

void HamRaisingCommand::Interrupted() {
	End();
}

double HamRaisingCommand::generateOutputPercent(){
	double disto=Robot::hamSubsystem->hamDistance();
	double dist=fabs(disto);
	if(dist<8){
		return 0.12;
	}else if(dist<20){
		return 0.16;
	}else if(dist<54){
		return 0.21;
	}else if(dist<82){
		return 0.18;
	}
	if(dist>82 && disto<0){
		return -0.09;
	}
	return 0.3;
}