#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

class HamControlCommand : public frc::Command {
private:
    bool isRaising,isSafeMode;
	double generateRaisingOutputPercent(double disto);
    double generateLyingOutputPercent(double disto);
public:
	HamControlCommand(bool raising,bool safe);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

