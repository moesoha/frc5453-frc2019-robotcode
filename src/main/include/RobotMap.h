#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>

class RobotMap {
public:
	static void init();

	constexpr static int CAN_HAM_1=11;
	constexpr static int CAN_HAM_2=12;
	constexpr static int CAN_MAID_ROLLER=13;
	constexpr static int CAN_FRONT_WINCH_1=16;
	constexpr static int CAN_FRONT_WINCH_2=17;
	constexpr static int CAN_PCM=60;
	constexpr static int CAN_CHASSIS_MOTOR_NUMBASE=20;
	constexpr static int DIO_ENCODER_HAM_A=0;
	constexpr static int DIO_ENCODER_HAM_B=1;
	constexpr static int DIO_ENCODER_FOOTFRAME_A=2;
	constexpr static int DIO_ENCODER_FOOTFRAME_B=3;
	constexpr static int PCM_SOLENOID_PLATESUCKER=0;
	constexpr static int PCM_SOLENOID_PLATESUCKERKILLER=1;

	static std::shared_ptr<rev::CANSparkMax> motorDriveLeft1;
	static std::shared_ptr<rev::CANSparkMax> motorDriveLeft2;
	static std::shared_ptr<rev::CANSparkMax> motorDriveLeft3;
	static std::shared_ptr<rev::CANSparkMax> motorDriveRight1;
	static std::shared_ptr<rev::CANSparkMax> motorDriveRight2;
	static std::shared_ptr<rev::CANSparkMax> motorDriveRight3;
	static std::shared_ptr<frc::SpeedControllerGroup> motorDriveGroupLeft;
	static std::shared_ptr<frc::SpeedControllerGroup> motorDriveGroupRight;
	static std::shared_ptr<frc::DifferentialDrive> robotDrive;

	static std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motorFootRoller;

	static std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motorHam1;
	static std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motorHam2;
	static std::shared_ptr<frc::SpeedControllerGroup> motorHam;
	static std::shared_ptr<frc::Encoder> encoderHam;

	static std::shared_ptr<frc::Encoder> encoderFootFrame;

	static std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motorElevator1;
	static std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> motorElevator2;
	static std::shared_ptr<frc::SpeedControllerGroup> motorElevator;

	static std::shared_ptr<frc::Compressor> compressor;
	static std::shared_ptr<frc::Solenoid> solenPlateSucker;
	static std::shared_ptr<frc::Solenoid> solenPlateSuckerKiller;

	static std::shared_ptr<frc::PowerDistributionPanel> pdp;
};
