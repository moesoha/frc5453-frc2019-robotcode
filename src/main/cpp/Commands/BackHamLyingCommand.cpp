#include "Commands/BackHamLyingCommand.h"

BackHamLyingCommand::BackHamLyingCommand() {
	Requires(Robot::hamSubsystem.get());
}

void BackHamLyingCommand::Initialize() {

}

void BackHamLyingCommand::Execute() {
	Robot::hamSubsystem->set(generateOutputPercent());
}

bool BackHamLyingCommand::IsFinished() {
	return false;
}

void BackHamLyingCommand::End() {
    Robot::hamSubsystem->softBackStop();
}

void BackHamLyingCommand::Interrupted() {
	End();
}

double BackHamLyingCommand::generateOutputPercent(){
	double dist=Robot::hamSubsystem->hamDistance();
    if(dist>-9){
        return 0.08;
    }else if(dist>-19){
        return 0.18;
    }else if(dist>-50){
        return 0.20;
    }else if(dist>-85){
        return 0.08;
    }
    return -0.09;
}