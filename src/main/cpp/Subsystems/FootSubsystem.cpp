#include "Subsystems/FootSubsystem.h"
#include "RobotMap.h"
#include "Commands/FootRollerAxisCommand.h"

FootSubsystem::FootSubsystem() : frc::Subsystem("FootSubsystem") {
	motorFootRoller=RobotMap::motorFootRoller;
	motorHam=RobotMap::motorHam;
}

void FootSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new FootRollerAxisCommand());
}

void FootSubsystem::roll(double speed){
	motorFootRoller->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void FootSubsystem::ham(double speed){
	motorHam->Set(speed);
}

void FootSubsystem::stopMotors(){
	motorFootRoller->StopMotor();
	motorHam->StopMotor();
}
