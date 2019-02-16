#pragma once

#include <frc/commands/Subsystem.h>

#include <frc/WPILib.h>

class DriveSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<frc::DifferentialDrive> robotDrive;
	std::shared_ptr<frc::SpeedControllerGroup> motorLeft;
	std::shared_ptr<frc::SpeedControllerGroup> motorRight;

public:
	DriveSubsystem();
	void InitDefaultCommand() override;
	void tankDrive(double l,double r,bool squaredInputs=true);
	void arcadeDrive(double x,double y,bool squaredInputs=true);
	void stopMotor();
};

