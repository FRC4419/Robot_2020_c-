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
  m_PDP = new frc::PowerDistributionPanel(0);
  m_PDP->ResetTotalEnergy();
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
//sensitivity
float throt = 0.0;
float steer = 0.0;
float accel = 0.04;
//runs every 20ms

float timeUntilSend = 0.0;

void Robot::RobotPeriodic() {
  
  timeUntilSend += 20.0 / 1000.0;
  {
    timeUntilSend = 0;
    std::cout << m_PDP->GetTotalCurrent() << std::endl;
  }
  //motor throttle multiplier
  float throttleLimit = 0.5;

  //if the xbox controller joystick is lower than this, it will ignore the input
  //due to the joystick is not always fully centered
  float tolerance = 0.03;


  //raw steering value - dont use
  float steera = m_Joystick->GetRawAxis(0);
  //raw positive throttle - dont use
  float posthrottle = m_Joystick->GetRawAxis(1);//m_Joystick->GetRawAxis(3);
  //raw negative throttle - dont use
  float negthrottle = 0;// m_Joystick->GetRawAxis(2);
  //raw summed throttle - dont use
  float throttle = posthrottle - negthrottle;

  std::cout << "Test A: " << steera << " Test B:" << posthrottle << std::endl;

  //easing steering value for non sudden acceleration
  steer = (1 - accel) * steer + accel * steera;

  //set throttle to zero if thottle is lower than tolerance
  if (abs(throttle) < tolerance)
  {
    throttle = 0;
  }

  //easing throttle value for non suddden acceleration - avoid wheelslip
  throt = throt * (1 - accel) + throttle * accel;

  //left and right motor throttles
  float motorLeft = -steer + throt;
  float motorRight = steer + throt;
  float sumThrottle = (motorLeft + motorRight);
  if (sumThrottle < 1) sumThrottle = 1;
  //calls motors to run
  m_Motor0.EnableDeadbandElimination(true);
  m_Motor0.Set(motorLeft / sumThrottle * throttleLimit);
  m_Motor1.EnableDeadbandElimination(true);
  m_Motor1.Set(-motorRight / sumThrottle * throttleLimit);
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