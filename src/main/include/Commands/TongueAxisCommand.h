#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class TongueAxisCommand : public frc::Command {
public:
	TongueAxisCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

