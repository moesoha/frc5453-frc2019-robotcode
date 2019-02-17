#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class ElevatorAxisCommand : public frc::Command {
public:
	ElevatorAxisCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

