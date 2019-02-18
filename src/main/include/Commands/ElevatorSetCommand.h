#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class ElevatorSetCommand : public frc::Command {
private:
    double speed;
public:
	ElevatorSetCommand(double s);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

