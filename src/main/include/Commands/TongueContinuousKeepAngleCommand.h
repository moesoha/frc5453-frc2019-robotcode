#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class TongueContinuousKeepAngleCommand : public frc::Command {
public:
	TongueContinuousKeepAngleCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

