#include "Subsystems/HamSubsystem.h"
#include "RobotMap.h"
#include "Commands/HamAxisCommand.h"

HamSubsystem::HamSubsystem() : frc::Subsystem("HamSubsystem") {
	motorHam=RobotMap::motorHam;
}

void HamSubsystem::InitDefaultCommand() {
	// SetDefaultCommand(new HamAxisCommand());
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
