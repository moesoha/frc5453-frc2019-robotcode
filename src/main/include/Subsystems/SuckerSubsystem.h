#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

class SuckerSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<frc::Solenoid> sucker;
    bool status=false;

public:
	SuckerSubsystem();
	void InitDefaultCommand() override;
	void toggle();
    void set(bool s);
};

