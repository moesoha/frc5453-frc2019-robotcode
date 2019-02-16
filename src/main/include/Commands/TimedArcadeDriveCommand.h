#pragma once

#include <frc/commands/Command.h>
#include <frc/WPILib.h>

class TimedArcadeDriveCommand : public frc::Command {
public:
	TimedArcadeDriveCommand(double ax,double ay,double atime);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	double x,y,delay;
	frc::Timer timer;
};

