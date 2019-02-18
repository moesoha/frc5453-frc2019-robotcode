#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class SuckerToggleCommand : public frc::Command {
public:
	SuckerToggleCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

