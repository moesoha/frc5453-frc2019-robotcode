#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class StillAutoCommand : public frc::Command {
public:
	StillAutoCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

