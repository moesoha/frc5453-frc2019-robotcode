#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>

class HamSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<frc::SpeedControllerGroup> motorHam;

public:
	HamSubsystem();
	void InitDefaultCommand() override;
	void set(double speed);
	void stopMotors();
	double hamDistance();
};

