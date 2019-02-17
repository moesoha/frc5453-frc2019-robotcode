#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class LegAxisCommand : public frc::Command {
public:
	LegAxisCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

