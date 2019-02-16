#pragma once

#include <frc/commands/Command.h>
#include <frc/WPILib.h>

class ArcadeDriveCommand : public frc::Command {
public:
	ArcadeDriveCommand(double ax,double ay);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	double x,y;
};

