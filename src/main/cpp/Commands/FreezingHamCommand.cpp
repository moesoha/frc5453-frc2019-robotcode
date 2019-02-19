#include "Commands/FreezingHamCommand.h"

FreezingHamCommand::FreezingHamCommand(){
	Requires(Robot::hamSubsystem.get());
}

void FreezingHamCommand::Initialize(){

}

void FreezingHamCommand::Execute(){
    double dist=Robot::hamSubsystem->hamDistance();
	if(dist>5){
        Robot::hamSubsystem->softStop();
    }else{
        Robot::hamSubsystem->softBackStop();
    }
}

bool FreezingHamCommand::IsFinished(){
	return false;
}

void FreezingHamCommand::End(){}

void FreezingHamCommand::Interrupted(){
	End();
}