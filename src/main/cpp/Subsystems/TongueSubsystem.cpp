#include "Subsystems/TongueSubsystem.h"
#include "RobotMap.h"
#include "Commands/TongueContinuousKeepAngleCommand.h"
#include <cmath>

TongueSubsystem::TongueSubsystem() : frc::Subsystem("TongueSubsystem") {
	motor=RobotMap::motorHalfFrame;
	encoder=RobotMap::encoderFootFrame;
}

void TongueSubsystem::InitDefaultCommand() {
    // SetDefaultCommand(new TongueContinuousKeepAngleCommand());
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

void TongueSubsystem::setFixedPosition(double angle){
	fixedPosition=angle;
}

double TongueSubsystem::getFixedOutput(double hamAngle,double tongueAngle) {
	// 目标角度为6点钟方向为标准的偏移
    double angleTarget=hamAngle+fixedPosition;
	double angleDelta=angleTarget-tongueAngle;
    double y=pow(angleDelta/180,3);
	if(y>1.0){
		return 1.0;
	}else if(y<-1.0){
		return -1.0;
	}else{
		return y;
	}
}
