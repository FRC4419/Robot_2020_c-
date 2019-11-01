#include "Robot.h"
#include <iostream>
#ifndef RUNNING_FRC_TESTS
int main() 
{ 
    std::cout << "blin";
    return frc::StartRobot<Robot>(); 
}
#endif
