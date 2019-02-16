#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class HamRaisingCommand : public frc::Command {
private:
	double speed;
public:
	HamRaisingCommand(double s);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

