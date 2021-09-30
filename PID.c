#include <PID.h>

void PID_Init(PID_Handler *PID, PID_Constant_Type ConstantP,PID_Constant_Type ConstantI, PID_Constant_Type ConstantD, PID_Constant_Type TimeBaseMs)
{
    PID->Kp = ConstantP;
    PID->Ki = ConstantI;
    PID->Kd = ConstantD;
};
void PID_SetGoal(PID_Handler *PID, PID_Constant_Type Goal)
{
    PID->Goal = Goal;
};
float PID_Compute(PID_Handler *PID, PID_Constant_Type InputData )
{
    PID_Constant_Type Output;
    PID->PError = PID->Goal - InputData; //P
    PID->IError = PID->PError * PID->TimeBaseMS; //I
    PID->DError = (PID->PError - PID->LastPError)/ PID->TimeBaseMS // D
    //somation
    Output = PID->Kp*PID->PError +  PID->Ki*PID->IError +  PID->Kd*PID->DError;
    PID->LastPError = PID->PError;
};