#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class FootRollerCommand : public frc::Command {
private:
	double speed;
public:
	FootRollerCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

