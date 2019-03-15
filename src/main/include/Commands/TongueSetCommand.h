#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class TongueSetCommand : public frc::Command {
private:
    double destAngle;
    double outputCalculator();
public:
	TongueSetCommand(double da);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

