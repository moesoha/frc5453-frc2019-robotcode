#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class FootRollerAxisCommand : public frc::Command {
public:
	FootRollerAxisCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

