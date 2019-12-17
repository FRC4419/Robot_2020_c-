#include <map>

#include <frc/VictorSP.h>


enum class EMotorSide
{
    Left,
    Right
};

class Motor
{
private:
    frc::VictorSP MotorDriver;
    

};

class DriveTrain
{
private:
    std::map<EMotorSide, Motor*> m_MotorTable;
public:
    DriveTrain();
    ~DriveTrain();

    void AddMotor(EMotorSide side, Motor motor);
};