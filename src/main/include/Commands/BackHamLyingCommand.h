#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class BackHamLyingCommand : public frc::Command {
private:
	double generateOutputPercent();
public:
	BackHamLyingCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

