#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>

class ElevatorSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<frc::SpeedControllerGroup> motorElevator;

public:
	ElevatorSubsystem();
	void InitDefaultCommand() override;
	void set(double speed);
	void softStop();
	void stopMotors();
	double distance();
};

