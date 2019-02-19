#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>

class TongueSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motor;
	std::shared_ptr<frc::Encoder> encoder;

public:
	TongueSubsystem();
	void InitDefaultCommand() override;
	void set(double speed);
	void stopMotors();
	double position();
};

