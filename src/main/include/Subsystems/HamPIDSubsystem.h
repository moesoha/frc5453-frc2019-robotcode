#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>

class HamPIDSubsystem : public frc::PIDSubsystem {
private:
    const double fBase=59.5/(0.71*2*100);
    std::shared_ptr<frc::SpeedControllerGroup> motorHam;
public:
	HamPIDSubsystem();
	void InitDefaultCommand() override;
protected:
    double ReturnPIDInput() override;
    void UsePIDOutput(double output) override;
};
