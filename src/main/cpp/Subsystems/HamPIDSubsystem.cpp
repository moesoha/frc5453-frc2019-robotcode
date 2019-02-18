#include "Subsystems/HamPIDSubsystem.h"
#include "RobotMap.h"
#include <cmath>

HamPIDSubsystem::HamPIDSubsystem() : frc::PIDSubsystem("HamPIDSubsystem", 0.005, 0.2, 0) {
	motorHam=RobotMap::motorHam;
    SetPercentTolerance(0.2);
    SetInputRange(-90,90);
    SetPIDSourceType(frc::PIDSourceType::kRate);
    GetPIDController()->SetContinuous(false);
    GetPIDController()->SetF(fBase);
}

void HamPIDSubsystem::InitDefaultCommand(){}

double HamPIDSubsystem::ReturnPIDInput(){
    // return (RobotMap::motorHam1->GetMotorOutputVoltage()+RobotMap::motorHam2->GetMotorOutputVoltage())/2.0;
    GetPIDController()->SetF(fBase*cos(90-RobotMap::encoderHam->GetRate()));
    return RobotMap::encoderHam->GetRate();
}

void HamPIDSubsystem::UsePIDOutput(double output){
    frc::SmartDashboard::PutNumber("HamPIDOutput",output);
    // printf("PID: %lf\n",output);
    // motorHam->Set(-output);
}
