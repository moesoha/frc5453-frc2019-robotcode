#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class TongueRaisingCommand : public frc::Command {
public:
	TongueRaisingCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

