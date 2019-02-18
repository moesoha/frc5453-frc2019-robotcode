#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>

class FootSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motorFootRoller;

public:
	FootSubsystem();
	void InitDefaultCommand() override;
	void roll(double speed);
	void stopMotors();
};

