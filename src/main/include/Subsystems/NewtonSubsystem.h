#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>

class NewtonSubsystem : public frc::Subsystem {
private:
	std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motorLeft;
	std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motorRight;
    std::shared_ptr<frc::Solenoid> solenoid;
    bool solenStatus=false;

public:
	NewtonSubsystem();
	void InitDefaultCommand() override;
	
    // Arm Part
    void setLeft(double speed);
	void setRight(double speed);
    void setMotors(double speed);
	void stopLeft();
	void stopRight();
	void stopMotors();

    // Hand Part
    void toggleHand();
    void startPushing();
    void stopPushing();
};
