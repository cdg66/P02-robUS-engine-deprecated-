#ifndef PID_H
#define PID_H

#ifdef __cplusplus
 extern "C" {
#endif


#include <Arduino.h>
//#include <librobus.h>
typedef  int32_t PID_Constant_Type;
typedef struct _PID
{
    float Kp;
    float Ki;
    float Kd;
    PID_Constant_Type PError;
    PID_Constant_Type LastPError;
    PID_Constant_Type IError;
    PID_Constant_Type DError;
    PID_Constant_Type Goal;
    uint16_t TimeBaseMS; // delta of time(in ms) witch the PID_Copute function is called periodically

} PID_Handler;

void PID_Init(PID_Handler *PID, float ConstantP, float ConstantI, float ConstantD, PID_Constant_Type TimeBaseMs);

void PID_SetGoal(PID_Handler *PID, PID_Constant_Type Goal);

float PID_Compute(PID_Handler *PID, PID_Constant_Type InputData );

#ifdef __cplusplus
}
#endif

#endif