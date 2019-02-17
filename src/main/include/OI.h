#pragma once

#include <frc/WPILib.h>

class OI {
private:
	std::shared_ptr<frc::Joystick> joystickDriver;
	std::shared_ptr<frc::Joystick> joystickOperator;

public:
	OI();

	std::shared_ptr<frc::Joystick> getJoystickDriver();
	double getDriverRawAxis(int axis);
	bool getDriverRawButton(int id);
};
