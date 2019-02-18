#include "Subsystems/SuckerSubsystem.h"
#include "RobotMap.h"

SuckerSubsystem::SuckerSubsystem() : frc::Subsystem("SuckerSubsystem") {
	sucker=RobotMap::solenPlateSucker;
    sucker->Set(status);
}

void SuckerSubsystem::InitDefaultCommand() {}

void SuckerSubsystem::toggle(){
    sucker->Set(!status);
    status=!status;
}

void SuckerSubsystem::set(bool s){
    sucker->Set(s);
    status=s;
}