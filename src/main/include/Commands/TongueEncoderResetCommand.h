#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class TongueEncoderResetCommand : public frc::Command {
public:
	TongueEncoderResetCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

