#include "Commands/BackHamRaisingCommand.h"

BackHamRaisingCommand::BackHamRaisingCommand() {
	Requires(Robot::hamSubsystem.get());
}

void BackHamRaisingCommand::Initialize() {

}

void BackHamRaisingCommand::Execute() {
	Robot::hamSubsystem->set(-generateOutputPercent());
}

bool BackHamRaisingCommand::IsFinished() {
	return false;
}

void BackHamRaisingCommand::End() {
    Robot::hamSubsystem->softBackStop();
}

void BackHamRaisingCommand::Interrupted() {
	End();
}

double BackHamRaisingCommand::generateOutputPercent(){
	double dist=Robot::hamSubsystem->hamDistance();
    if(dist>4){
        return 0;
    }else if(dist>-5){
        return 0.05;
    }else if(dist>-18){
        return 0.10;
    }else if(dist>-35){
        return 0.21;
    }else if(dist>-70){
        return 0.36;
    }
    return 0.3;
}