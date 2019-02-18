#include "Subsystems/FootSubsystem.h"
#include "RobotMap.h"
#include "Commands/LegAxisCommand.h"

FootSubsystem::FootSubsystem() : frc::Subsystem("FootSubsystem") {
	motorFootRoller=RobotMap::motorFootRoller;
}

void FootSubsystem::InitDefaultCommand() {
	// SetDefaultCommand(new LegAxisCommand());
}

void FootSubsystem::roll(double speed){
	motorFootRoller->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void FootSubsystem::stopMotors(){
	motorFootRoller->StopMotor();
}
