#include "Commands/DriveCommand.h"

DriveCommand::DriveCommand() {
	Requires(Robot::driveSubsystem.get());
}

void DriveCommand::Initialize() {

}

void DriveCommand::Execute() {
	// Robot::driveSubsystem->tankDrive(Robot::oi->getDriverRawAxis(1),Robot::oi->getDriverRawAxis(3));
}

bool DriveCommand::IsFinished() {
	return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {
	End();
}
