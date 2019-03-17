#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class NewtonLovesGroundCommand : public frc::Command {
private:
	bool open=false;
public:
	NewtonLovesGroundCommand(bool o);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

