#include "Subsystems/HamSubsystem.h"
#include "RobotMap.h"
#include "Commands/LegAxisCommand.h"

HamSubsystem::HamSubsystem() : frc::Subsystem("HamSubsystem") {
	motorHam=RobotMap::motorHam;
}

void HamSubsystem::InitDefaultCommand() {
	// SetDefaultCommand(new LegAxisCommand());
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
