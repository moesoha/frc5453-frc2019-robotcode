#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class HamRaisingCommand : public frc::Command {
private:
	double generateOutputPercent();
public:
	HamRaisingCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

