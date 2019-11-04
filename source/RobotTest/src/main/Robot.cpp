/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_Joystick = new frc::Joystick(0);
  std::cout << "Robot Initing..." << std::endl;
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
float clamp(float v, float min, float max)
{
  if (v < min)
    return min;
  if (v > max)
    return max;
  return v;
}



void Robot::RobotPeriodic() {
  float throttleLimit = 0.5;
  float steer = m_Joystick->GetRawAxis(0);
  float throttle = m_Joystick->GetRawAxis(3);
  float negthrottle = m_Joystick->GetRawAxis(2);
  float accel = throttle - negthrottle;

  std::cout << negthrottle << throttle << " / " << steer << std::endl;

  float leftMotor = clamp(1 - 2 * steer, -1, 1);
  float rightMotor = -clamp(1 - 2 * -steer, -1, 1);

  m_Motor0.EnableDeadbandElimination(true);
  m_Motor0.Set(leftMotor * accel * throttleLimit);
  m_Motor1.EnableDeadbandElimination(true);
  m_Motor1.Set(rightMotor * accel * throttleLimit);


}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  
}

void Robot::AutonomousPeriodic() {
  
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {

}

void Robot::TestPeriodic() {

}
