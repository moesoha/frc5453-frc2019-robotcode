#pragma once

#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/TimedRobot.h>

#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/FootSubsystem.h"
#include "Subsystems/ElevatorSubsystem.h"

#include "OI.h"
#include "RobotMap.h"
#include "Commands/Autonomous/StillAutoCommand.h"
#include "Commands/TimedArcadeDriveCommand.h"

class Robot : public frc::TimedRobot {
public:
	static std::shared_ptr<DriveSubsystem> driveSubsystem;
	static std::shared_ptr<FootSubsystem> footSubsystem;
	static std::shared_ptr<ElevatorSubsystem> elevatorSubsystem;
	static std::shared_ptr<OI> oi;

	void RobotInit() override;
	void RobotPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	frc::SendableChooser<frc::Command*> m_chooser;
};
