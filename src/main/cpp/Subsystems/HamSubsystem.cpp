#include "Subsystems/HamSubsystem.h"
#include "RobotMap.h"
#include "Commands/FreezingHamCommand.h"

HamSubsystem::HamSubsystem() : frc::Subsystem("HamSubsystem") {
	motorHam=RobotMap::motorHam;
}

void HamSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new FreezingHamCommand());
}

void HamSubsystem::set(double speed){
	motorHam->Set(speed);
}

double HamSubsystem::hamDistance(){
	return RobotMap::encoderHam->GetDistance();
}

void HamSubsystem::stopMotors(){
	motorHam->StopMotor();
}

void HamSubsystem::softStop(){
	if(hamDistance()<15){
		motorHam->Set(0);
	}else if(hamDistance()<70){
		motorHam->Set(0.07);
	}else{
		motorHam->Set(0.09);
	}
}

void HamSubsystem::softBackStop(){
	if(hamDistance()>3){
		motorHam->Set(0);
	}else if(hamDistance()>-60){
		motorHam->Set(-0.06);
	}else{
		motorHam->Set(-0.09);
	}
}
