#include "Commands/HamAxisCommand.h"

// should not be used!
HamAxisCommand::HamAxisCommand() {
	Requires(Robot::hamSubsystem.get());
}

void HamAxisCommand::Initialize() {}

void HamAxisCommand::Execute() {
    // frc::SmartDashboard::PutNumber("HamVoltageAvg",(RobotMap::motorHam1->GetMotorOutputVoltage()+RobotMap::motorHam2->GetMotorOutputVoltage())/2.0);
	Robot::hamSubsystem->set(Robot::oi->getDriverRawAxis(1)*0.5);
}

bool HamAxisCommand::IsFinished() {
	return false;
}

void HamAxisCommand::End() {
	Robot::hamSubsystem->set(0);
}

void HamAxisCommand::Interrupted() {
	End();
}
