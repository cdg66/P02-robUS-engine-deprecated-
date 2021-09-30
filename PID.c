#include <PID.h>
//#include <Arduino.h>
//#include <librobus.h>
void PID_Init(PID_Handler *PID, float ConstantP, float ConstantI, float ConstantD, PID_Constant_Type TimeBaseMs)
{
    PID->Kp = ConstantP;
    PID->Ki = ConstantI;
    PID->Kd = ConstantD;
    PID->LastPError = 0;
};
void PID_SetGoal(PID_Handler *PID, PID_Constant_Type Goal)
{
    PID->Goal = Goal;
};
float PID_Compute(PID_Handler *PID, PID_Constant_Type InputData )
{
    float Output;
    PID->PError = PID->Goal - InputData; //P
    PID->IError = PID->PError * PID->TimeBaseMS; //I
    PID->DError = (PID->PError - PID->LastPError)/ PID->TimeBaseMS; // D
    //somation
    Output = PID->Kp*PID->PError +  PID->Ki*PID->IError +  PID->Kd*PID->DError;
    //Serial.print(Output,10);
    //Serial.print("\n\r");
    PID->LastPError = PID->PError;

    return Output;
};