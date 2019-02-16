#include "Commands/TimedArcadeDriveCommand.h"

#include "Robot.h"

TimedArcadeDriveCommand::TimedArcadeDriveCommand(double ax,double ay,double atime/* seconds */) {
	x=ax;
	y=ay;
	delay=atime;
	Requires(Robot::driveSubsystem.get());
}

void TimedArcadeDriveCommand::Initialize() {
	timer.Reset();
	timer.Start();
}

void TimedArcadeDriveCommand::Execute() {
	Robot::driveSubsystem->arcadeDrive(x,y,false);
}

bool TimedArcadeDriveCommand::IsFinished() {
	return timer.Get()>=delay;
}

void TimedArcadeDriveCommand::End() {
	timer.Stop();
	Robot::driveSubsystem->stopMotor();
}

void TimedArcadeDriveCommand::Interrupted() {
	End();
}
