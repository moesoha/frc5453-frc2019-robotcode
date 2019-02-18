#include "Commands/DriveCommand.h"
#include <cmath>

DriveCommand::DriveCommand() {
	Requires(Robot::driveSubsystem.get());
}

void DriveCommand::Initialize() {

}

void DriveCommand::Execute() {
	double r=getRate();
	double x=Robot::oi->getDriverRawAxis(1);
	double y=Robot::oi->getDriverRawAxis(3);
	x=fabs(x)<0.01?0:x*r;
	y=fabs(y)<0.01?0:y*r;
	// Robot::driveSubsystem->tankDrive(x,y,false);
}

double DriveCommand::getRate(){
	if(Robot::oi->getDriverRawButton(7)){
		return 0.3;
	}
	if(Robot::oi->getDriverRawButton(8)){
		return 1.0;
	}
	return 0.6;
}

bool DriveCommand::IsFinished() {
	return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {
	End();
}
