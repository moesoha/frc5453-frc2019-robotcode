#include "Commands/ArcadeDriveCommand.h"

#include "Robot.h"

ArcadeDriveCommand::ArcadeDriveCommand(double ax,double ay) {
	x=ax;
	y=ay;
	Requires(Robot::driveSubsystem.get());
}

void ArcadeDriveCommand::Initialize() {}

void ArcadeDriveCommand::Execute() {
	Robot::driveSubsystem->arcadeDrive(x,y,false);
}

bool ArcadeDriveCommand::IsFinished() {
	return false;
}

void ArcadeDriveCommand::End() {
	Robot::driveSubsystem->stopMotor();
}

void ArcadeDriveCommand::Interrupted() {
	End();
}
