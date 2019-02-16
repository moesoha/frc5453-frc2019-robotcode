#include "Subsystems/DriveSubsystem.h"
#include "RobotMap.h"
#include "Commands/DriveCommand.h"

DriveSubsystem::DriveSubsystem() : frc::Subsystem("DriveSubsystem") {
	robotDrive=RobotMap::robotDrive;
	motorLeft=RobotMap::motorDriveGroupLeft;
	motorRight=RobotMap::motorDriveGroupRight;
}

void DriveSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new DriveCommand());
}

void DriveSubsystem::tankDrive(double l,double r,bool squaredInputs){
	robotDrive->TankDrive(l,r,squaredInputs);
}

void DriveSubsystem::arcadeDrive(double x,double y,bool squaredInputs){
	robotDrive->ArcadeDrive(x,y,squaredInputs);
}

void DriveSubsystem::stopMotor(){
	robotDrive->StopMotor();
}
