#include "Subsystems/HamPIDSubsystem.h"
#include "RobotMap.h"
#include <cmath>

HamPIDSubsystem::HamPIDSubsystem() : frc::PIDSubsystem("HamPIDSubsystem", 0.0016, 0.00004, 0.00045) {
	motorHam=RobotMap::motorHam;
    SetPercentTolerance(0.2);
    SetPIDSourceType(frc::PIDSourceType::kDisplacement);
    GetPIDController()->SetContinuous(false);
}

void HamPIDSubsystem::InitDefaultCommand(){}

double HamPIDSubsystem::ReturnPIDInput(){
    return RobotMap::encoderHam->GetDistance();
}

void HamPIDSubsystem::UsePIDOutput(double output){
    frc::SmartDashboard::PutNumber("HamPIDOutput",output);
    // if(fabs(output)>0.6){
    //     return;
    // }
    motorHam->Set(-output);
}