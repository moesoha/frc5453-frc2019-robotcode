#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class FreezingHamCommand : public frc::Command {
public:
	FreezingHamCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

