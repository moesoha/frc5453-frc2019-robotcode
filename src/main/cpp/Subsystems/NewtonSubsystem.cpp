#include "Subsystems/NewtonSubsystem.h"
#include "Commands/NewtonUsingHandsCommand.h"
#include "RobotMap.h"

NewtonSubsystem::NewtonSubsystem() : frc::Subsystem("NewtonSubsystem") {
	motorLeft=RobotMap::motorNewtonLeftArm;
	motorRight=RobotMap::motorNewtonRightArm;
    solenoid=RobotMap::solenNewtonHand;
}

void NewtonSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new NewtonUsingHandsCommand());
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
    solenStatus=true;
    solenoid->Set(true);
}
void NewtonSubsystem::stopPushing(){
    solenStatus=false;
    solenoid->Set(false);
}
void NewtonSubsystem::toggleHand(){
    solenoid->Set(!solenStatus);
    solenStatus=!solenStatus;
}
