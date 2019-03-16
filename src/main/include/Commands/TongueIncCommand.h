#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class TongueIncCommand : public frc::Command {
private:
    double delta;
public:
	TongueIncCommand(double d);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

