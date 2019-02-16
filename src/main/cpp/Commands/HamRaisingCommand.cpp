#include "Commands/HamRaisingCommand.h"

HamRaisingCommand::HamRaisingCommand() {
	Requires(Robot::footSubsystem.get());
}

void HamRaisingCommand::Initialize() {

}

void HamRaisingCommand::Execute() {
	Robot::footSubsystem->ham(generateOutputPercent());
}

bool HamRaisingCommand::IsFinished() {
	return false;
}

void HamRaisingCommand::End() {
    Robot::footSubsystem->ham(0);
}

void HamRaisingCommand::Interrupted() {
	End();
}

double HamRaisingCommand::generateOutputPercent(){
	double dist=Robot::footSubsystem->hamDistance();
	if(dist<10){
		return 0.05;
	}else if(dist<50){
		return 0.2;
	}else if(dist<200){
		return 0.5;
	}else if(dist<500){
		return 0.6;
	}else{
		return 0.5;
	}
}