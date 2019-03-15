#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>

class TongueSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motor;
	std::shared_ptr<frc::Encoder> encoder;
	double fixedPosition=0;

public:
	TongueSubsystem();
	void InitDefaultCommand() override;
	void set(double speed);
	void stopMotors();
	double position();
	void setFixedPosition(double angle);
	double getFixedOutput(double hamAngle,double tongueAngle);
};

