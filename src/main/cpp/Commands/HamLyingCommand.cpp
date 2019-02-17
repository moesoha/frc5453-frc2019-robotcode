#include "Commands/HamLyingCommand.h"

HamLyingCommand::HamLyingCommand() {
	Requires(Robot::footSubsystem.get());
}

void HamLyingCommand::Initialize() {

}

void HamLyingCommand::Execute() {
	Robot::footSubsystem->ham(-generateOutputPercent());
}

bool HamLyingCommand::IsFinished() {
	return false;
}

void HamLyingCommand::End() {
    Robot::footSubsystem->ham(0);
}

void HamLyingCommand::Interrupted() {
	End();
}

double HamLyingCommand::generateOutputPercent(){
	double dist=Robot::footSubsystem->hamDistance();
	if(dist<10){
		return 0.3;
	}else if(dist<50){
		return 0.3;
	}else if(dist<130){
		return 0.18;
    }else if(dist<320){
        return 0.1;
    }else if(dist<480){
		return 0.08;
	}
    return -0.06;
}