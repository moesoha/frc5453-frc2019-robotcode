#include "Commands/HamControlCommand.h"
#include <cmath>

HamControlCommand::HamControlCommand(bool raising,bool safe) {
	isRaising=raising;
    isSafeMode=safe;
	Requires(Robot::hamSubsystem.get());
}

void HamControlCommand::Initialize() {

}

void HamControlCommand::Execute() {
    double disto=Robot::hamSubsystem->hamDistance();
    if(isRaising && disto>0){ // 正向上升
        Robot::hamSubsystem->set(generateRaisingOutputPercent(disto));
    }else if(isRaising && disto<0){ // 反向下降
        Robot::hamSubsystem->set(generateLyingOutputPercent(disto));
    }else if(!isRaising && disto>0){ // 正向下降
        Robot::hamSubsystem->set(-generateLyingOutputPercent(disto));
    }else if(!isRaising && disto<0){ // 反向上升
        Robot::hamSubsystem->set(-generateRaisingOutputPercent(disto));
    }
}

bool HamControlCommand::IsFinished() {
	return false;
}

void HamControlCommand::End() {
    double dist=Robot::hamSubsystem->hamDistance();
	if(dist>5){
        Robot::hamSubsystem->softStop();
    }else{
        Robot::hamSubsystem->softBackStop();
    }
}

void HamControlCommand::Interrupted() {
	End();
}

double HamControlCommand::generateRaisingOutputPercent(double disto){
	double dist=fabs(disto);
    if(dist<8){
        return 0.16;
    }else if(dist<18){
        return 0.27;
    }else if(dist<54){
        return 0.37;
    }else if(dist<90){
        return 0.31;
    }
    return 0.38;
}

double HamControlCommand::generateLyingOutputPercent(double disto){
	double dist=fabs(disto);
	if(dist<9){
		return 0.08;
	}else if(dist<19){
		return 0.18;
    }else if(dist<50){
        return 0.20;
    }else if(dist<85){
		return 0.08;
	}else if(!isSafeMode && dist<150){
		return 0.05;
	}
    return -0.09;
}