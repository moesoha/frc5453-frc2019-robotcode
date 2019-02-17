#include "Subsystems/ElevatorSubsystem.h"
#include "RobotMap.h"
#include "Commands/ElevatorAxisCommand.h"

ElevatorSubsystem::ElevatorSubsystem() : frc::Subsystem("ElevatorSubsystem") {
	motorElevator=RobotMap::motorElevator;
}

void ElevatorSubsystem::InitDefaultCommand() {
	// SetDefaultCommand(new ElevatorAxisCommand());
}

void ElevatorSubsystem::set(double speed){
	motorElevator->Set(speed);
}

void ElevatorSubsystem::stopMotors(){
	motorElevator->StopMotor();
}
