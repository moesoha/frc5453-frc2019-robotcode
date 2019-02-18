#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>

class SuckerSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<frc::Solenoid> sucker;
	std::shared_ptr<frc::Solenoid> suckerKiller;
    bool status=false;
    bool killerStatus=false;

public:
	SuckerSubsystem();
	void InitDefaultCommand() override;
	void toggle();
	void toggleKiller();
    void set(bool s);
    void setKiller(bool s);
};

