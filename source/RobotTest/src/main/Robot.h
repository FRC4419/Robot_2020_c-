/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/VictorSP.h>
#include <frc/Joystick.h>
#include <frc/PowerDistributionPanel.h>

#include "rev/CANSparkMax.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  rev::CANSparkMax m_Motor0{14, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_Motor1{13, rev::CANSparkMax::MotorType::kBrushless};
  frc::Joystick* m_Joystick;
  frc::PowerDistributionPanel* m_PDP;
};
