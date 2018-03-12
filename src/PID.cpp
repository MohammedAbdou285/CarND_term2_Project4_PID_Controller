#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() 
{
    // Initialize PID Coefficients Errors
    p_error = 0;
    i_error = 0;
    d_error = 0;

    // Initialize PID Controller Coefficients
    Kp = 0;
    Ki = 0;
    Kd = 0;
}

PID::~PID() 
{}

void PID::Init(double Kp, double Ki, double Kd) 
{
    // Set PID COefficient values
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

void PID::UpdateError(double cte) 
{
    // In this function we have the current cte 
    d_error = cte - p_error;
    p_error = cte;
    i_error = i_error + cte;
    
}

double PID::TotalError() 
{
    // Calculate the total PID error Compnents
    double P_Component  = -Kp * p_error;
    double I_Component  = -Ki * i_error;
    double D_Component  = -Kd * d_error;
    double PID_Components = P_Component + I_Component + D_Component;
    
    return PID_Components;
}

