#include <iostream>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  i_error += cte;
  p_error = cte;
  cout<<"p_error : "<<p_error<<", d_error : "<<d_error<<", i_error : "<<i_error<<std::endl;
}

double PID::TotalError() {
  return (Kp * p_error) + (Kd * d_error) + (Ki * i_error);
}

