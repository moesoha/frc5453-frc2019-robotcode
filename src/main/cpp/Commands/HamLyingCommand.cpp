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
    Robot::hamSubsystem->softStop();
}

void HamLyingCommand::Interrupted() {
	End();
}

double HamLyingCommand::generateOutputPercent(){
	double dist=Robot::hamSubsystem->hamDistance();
	dist=fabs(dist);
	if(dist<9){
		return 0.08;
	}else if(dist<23){
		return 0.18;
    }else if(dist<56){
        return 0.20;
    }else if(dist<86){
		return 0.10;
	}else if(!safeDown && dist<150){
		return 0.09;
	}
    return -0.09;
}