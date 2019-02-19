#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class HamLyingCommand : public frc::Command {
private:
	double generateOutputPercent();
	bool safeDown=false;
public:
	HamLyingCommand(bool safe);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

