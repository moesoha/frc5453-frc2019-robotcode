#include "Subsystems/FootSubsystem.h"
#include "RobotMap.h"
#include "Commands/FootRollerCommand.h"

FootSubsystem::FootSubsystem() : frc::Subsystem("FootSubsystem") {
	motorFootRoller=RobotMap::motorFootRoller;
}

void FootSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new FootRollerCommand(-0.05));
}

void FootSubsystem::roll(double speed){
	motorFootRoller->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void FootSubsystem::stopMotors(){
	motorFootRoller->StopMotor();
}
