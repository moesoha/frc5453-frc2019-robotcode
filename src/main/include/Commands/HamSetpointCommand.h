#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class HamSetpointCommand : public frc::Command {
private:
	double point=0;
public:
	HamSetpointCommand(double p);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

