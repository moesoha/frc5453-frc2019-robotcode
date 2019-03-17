#include "Subsystems/TongueSubsystem.h"
#include "RobotMap.h"
#include "Commands/TongueContinuousKeepAngleCommand.h"
#include <cmath>

TongueSubsystem::TongueSubsystem() : frc::Subsystem("TongueSubsystem") {
	motor=RobotMap::motorHalfFrame;
	encoder=RobotMap::encoderFootFrame;
}

void TongueSubsystem::InitDefaultCommand() {
    SetDefaultCommand(new TongueContinuousKeepAngleCommand());
}

void TongueSubsystem::set(double speed){
	motor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

double TongueSubsystem::position(){
	return encoder->GetDistance();
}

void TongueSubsystem::stopMotors(){
	motor->StopMotor();
}

void TongueSubsystem::resetEncoder(){
	fixedPosition=0;
	encoder->Reset();
}

void TongueSubsystem::setFixedPosition(double angle){
	fixedPosition=angle;
	frc::SmartDashboard::PutNumber("Tongue Fixed Position",fixedPosition);
}

void TongueSubsystem::incFixedPosition(double inc){
	double fin=fixedPosition+inc;
	// setFixedPosition(fin);
	setFixedPosition(fin>270?270:(fin<-90?-90:fin));
}

double TongueSubsystem::getFixedOutput(double hamAngle,double tongueAngle) {
	double pos=fixedPosition;
	if(pos>220 && hamAngle<10){
		pos=220;
	}else if(pos>270){
		pos=270;
	}
	// 目标角度为6点钟方向为标准的偏移
    double angleTarget=hamAngle+pos;
	if(angleTarget<0){
		angleTarget=0;
	}
	if(angleTarget>270){
		angleTarget=270;
	}
	double angleDelta=angleTarget-tongueAngle;
    double y=pow(angleDelta/30,3);
	if(y>0.2){
		return 0.2;
	}else if(y<-0.2){
		return -0.2;
	}else{
		return y;
	}
}
