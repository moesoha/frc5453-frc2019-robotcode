#pragma once

#include <frc/WPILib.h>

class OI {
private:
	std::shared_ptr<frc::Joystick> joystickDriver;
	std::shared_ptr<frc::Joystick> joystickNewton;
	std::shared_ptr<frc::Joystick> joystickOperator;
	std::shared_ptr<frc::Joystick> joystickOperator2;

public:
	OI();

	std::shared_ptr<frc::Joystick> getJoystickDriver();
	std::shared_ptr<frc::Joystick> getJoystickNewton();
	double getDriverRawAxis(int axis);
	bool getDriverRawButton(int id);
	double getNewtonRawAxis(int axis);
	bool getNewtonRawButton(int id);
};
