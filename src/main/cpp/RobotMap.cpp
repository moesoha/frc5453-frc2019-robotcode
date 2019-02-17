#include "RobotMap.h"

std::shared_ptr<rev::CANSparkMax> RobotMap::motorDriveLeft1;
std::shared_ptr<rev::CANSparkMax> RobotMap::motorDriveLeft2;
std::shared_ptr<rev::CANSparkMax> RobotMap::motorDriveLeft3;
std::shared_ptr<rev::CANSparkMax> RobotMap::motorDriveRight1;
std::shared_ptr<rev::CANSparkMax> RobotMap::motorDriveRight2;
std::shared_ptr<rev::CANSparkMax> RobotMap::motorDriveRight3;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::motorDriveGroupLeft;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::motorDriveGroupRight;
std::shared_ptr<frc::DifferentialDrive> RobotMap::robotDrive;

std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> RobotMap::motorFootRoller;

std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> RobotMap::motorHam1;
std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> RobotMap::motorHam2;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::motorHam;
std::shared_ptr<frc::Encoder> RobotMap::encoderHam;

std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> RobotMap::motorElevator1;
std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_VictorSPX> RobotMap::motorElevator2;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::motorElevator;

std::shared_ptr<frc::Compressor> RobotMap::compressor;

std::shared_ptr<frc::PowerDistributionPanel> RobotMap::pdp;

void RobotMap::init(){
	motorDriveLeft1.reset(new rev::CANSparkMax(CAN_CHASSIS_MOTOR_NUMBASE+1,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
	motorDriveLeft2.reset(new rev::CANSparkMax(CAN_CHASSIS_MOTOR_NUMBASE+2,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
	motorDriveLeft3.reset(new rev::CANSparkMax(CAN_CHASSIS_MOTOR_NUMBASE+3,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
	motorDriveRight1.reset(new rev::CANSparkMax(CAN_CHASSIS_MOTOR_NUMBASE+4,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
	motorDriveRight2.reset(new rev::CANSparkMax(CAN_CHASSIS_MOTOR_NUMBASE+5,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
	motorDriveRight3.reset(new rev::CANSparkMax(CAN_CHASSIS_MOTOR_NUMBASE+6,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
	motorDriveGroupLeft.reset(new frc::SpeedControllerGroup(*motorDriveLeft1,*motorDriveLeft2,*motorDriveLeft3));
	motorDriveGroupRight.reset(new frc::SpeedControllerGroup(*motorDriveRight1,*motorDriveRight2,*motorDriveRight3));
	motorDriveGroupLeft->SetInverted(true);
	motorDriveGroupRight->SetInverted(true);
	robotDrive.reset(new frc::DifferentialDrive(*motorDriveGroupLeft,*motorDriveGroupRight));
	robotDrive->SetSafetyEnabled(false);

	motorFootRoller.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(RobotMap::CAN_MAID_ROLLER));

	motorHam1.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(RobotMap::CAN_HAM_1));
	motorHam2.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(RobotMap::CAN_HAM_2));
	// motorHam2->SetInverted(true);
	motorHam.reset(new frc::SpeedControllerGroup(*motorHam1,*motorHam2));
	motorHam->SetInverted(true);
	encoderHam.reset(new frc::Encoder(RobotMap::DIO_ENCODER_HAM_A, RobotMap::DIO_ENCODER_HAM_B));

	motorElevator1.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(RobotMap::CAN_FRONT_WINCH_1));
	motorElevator2.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(RobotMap::CAN_FRONT_WINCH_2));
	motorElevator.reset(new frc::SpeedControllerGroup(*motorElevator1,*motorElevator2));

	compressor.reset(new frc::Compressor(RobotMap::CAN_PCM));
	compressor->SetClosedLoopControl(true);
	// compressor->Enabled();

	// pdp.reset(new frc::PowerDistributionPanel());
}
