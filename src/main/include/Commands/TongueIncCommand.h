#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class TongueIncCommand : public frc::Command {
private:
    double delta;
	bool stopAtSpecificPosition=false;
	double specificMaxPosition=270;
public:
	TongueIncCommand(double d);
	TongueIncCommand(double d,double maxPosition);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

