#include "Commands/HamLyingCommand.h"
#include <cmath>

HamLyingCommand::HamLyingCommand(bool safe) {
	safeDown=safe;
	Requires(Robot::hamSubsystem.get());
}

void HamLyingCommand::Initialize() {

}

void HamLyingCommand::Execute() {
	Robot::hamSubsystem->set(-generateOutputPercent());
}

bool HamLyingCommand::IsFinished() {
	return false;
}

void HamLyingCommand::End() {
    double dist=Robot::hamSubsystem->hamDistance();
	if(dist>5){
        Robot::hamSubsystem->softStop();
    }else{
        Robot::hamSubsystem->softBackStop();
    }
}

void HamLyingCommand::Interrupted() {
	End();
}

double HamLyingCommand::generateOutputPercent(){
	double dist=Robot::hamSubsystem->hamDistance();
	dist=fabs(dist);
	if(dist<9){
		return 0.13;
	}else if(dist<23){
		return 0.18;
    }else if(dist<56){
        return 0.20;
    }else if(dist<86){
		return 0.16;
	}else if(!safeDown && dist<150){
		return 0.09;
	}
    return -0.09;
}