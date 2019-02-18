#include "Subsystems/SuckerSubsystem.h"
#include "RobotMap.h"

SuckerSubsystem::SuckerSubsystem() : frc::Subsystem("SuckerSubsystem") {
	sucker=RobotMap::solenPlateSucker;
    suckerKiller=RobotMap::solenPlateSuckerKiller;
    sucker->Set(status);
    suckerKiller->Set(killerStatus);
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

void SuckerSubsystem::toggleKiller(){
    suckerKiller->Set(!killerStatus);
    killerStatus=!killerStatus;
}

void SuckerSubsystem::setKiller(bool s){
    suckerKiller->Set(s);
    killerStatus=s;
}