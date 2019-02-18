#include "Subsystems/TongueSubsystem.h"
#include "RobotMap.h"
#include "Commands/TongueAxisCommand.h"

TongueSubsystem::TongueSubsystem() : frc::Subsystem("TongueSubsystem") {
	motor=RobotMap::motorHalfFrame;
}

void TongueSubsystem::InitDefaultCommand() {
    SetDefaultCommand(new TongueAxisCommand());
}

void TongueSubsystem::set(double speed){
	motor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void TongueSubsystem::stopMotors(){
	motor->StopMotor();
}
