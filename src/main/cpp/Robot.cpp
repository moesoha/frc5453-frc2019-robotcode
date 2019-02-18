#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

std::shared_ptr<DriveSubsystem> Robot::driveSubsystem;
std::shared_ptr<FootSubsystem> Robot::footSubsystem;
std::shared_ptr<HamSubsystem> Robot::hamSubsystem;
std::shared_ptr<HamPIDSubsystem> Robot::hamPidSubsystem;
std::shared_ptr<ElevatorSubsystem> Robot::elevatorSubsystem;
std::shared_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();

	driveSubsystem.reset(new DriveSubsystem());
	footSubsystem.reset(new FootSubsystem());
	hamSubsystem.reset(new HamSubsystem());
	hamPidSubsystem.reset(new HamPIDSubsystem());
	elevatorSubsystem.reset(new ElevatorSubsystem());

	oi.reset(new OI());

	m_chooser.SetDefaultOption("Still", new StillAutoCommand());
	m_chooser.AddOption("Go straight", new TimedArcadeDriveCommand(0.4, 0, 3.2));
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

	frc::CameraServer::GetInstance()->StartAutomaticCapture();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {
	hamPidSubsystem->Disable();
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	m_autonomousCommand = m_chooser.GetSelected();

	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	hamPidSubsystem->Enable();
	hamPidSubsystem->SetSetpoint(0);
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
