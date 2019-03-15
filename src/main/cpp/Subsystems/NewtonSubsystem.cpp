#include "Subsystems/NewtonSubsystem.h"
#include "RobotMap.h"

NewtonSubsystem::NewtonSubsystem() : frc::Subsystem("NewtonSubsystem") {
	motorLeft=RobotMap::motorNewtonLeftArm;
	motorRight=RobotMap::motorNewtonRightArm;
    solenLeft=RobotMap::solenNewtonLeftHand;
    solenRight=RobotMap::solenNewtonRightHand;
}

void NewtonSubsystem::InitDefaultCommand() {
	// SetDefaultCommand();
}

// Arm Part
void NewtonSubsystem::setLeft(double speed){
    motorLeft->Set(speed);
}
void NewtonSubsystem::setRight(double speed){
    motorRight->Set(speed);
}
void NewtonSubsystem::setMotors(double speed){
    setLeft(speed);
    setRight(speed);
}
void NewtonSubsystem::stopLeft(){
    motorLeft->StopMotor();
}
void NewtonSubsystem::stopRight(){
    motorRight->StopMotor();
}
void NewtonSubsystem::stopMotors(){
    stopLeft();
    stopRight();
}

// Hand Part
void NewtonSubsystem::startPushing(){
    startPushingLeft();
    startPushingRight();
}
void NewtonSubsystem::startPushingLeft(){
    solenLeft->Set(true);
}
void NewtonSubsystem::startPushingRight(){
    solenRight->Set(true);
}
void NewtonSubsystem::stopPushing(){
    stopPushingLeft();
    stopPushingRight();
}
void NewtonSubsystem::stopPushingLeft(){
    solenLeft->Set(false);
}
void NewtonSubsystem::stopPushingRight(){
    solenRight->Set(false);
}
