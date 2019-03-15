#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class NewtonUsingHandsCommand : public frc::Command {
public:
	NewtonUsingHandsCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

