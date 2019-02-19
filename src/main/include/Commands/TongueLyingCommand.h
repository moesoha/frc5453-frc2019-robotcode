#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class TongueLyingCommand : public frc::Command {
public:
	TongueLyingCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

