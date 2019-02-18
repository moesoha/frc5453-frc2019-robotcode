#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class HamAxisCommand : public frc::Command {
public:
	HamAxisCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

