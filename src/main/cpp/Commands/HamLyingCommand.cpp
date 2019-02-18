#include "Commands/HamLyingCommand.h"

HamLyingCommand::HamLyingCommand() {
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
	if(dist<9){
		return 0.05;
	}else if(dist<23){
		return 0.18;
    }else if(dist<56){
        return 0.20;
    }else if(dist<82){
		return 0.08;
	}
    return 0.02;
}