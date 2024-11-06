//____________________Valve_Position_PID VARS___________________
int dir=1;
int motor_PWM=180;
float P_Gain=2.5;
float I_Gain= 0.0001;
float D_Gain=1.25;
int previous_error;
int error_summation;
// error_margin_=3 to -3
//____________________Flow Rate PID VARS_________________________
float FR_error = 0;
float FR_P_Gain=1.2;
float FR_I_Gain= 0.0001;
float FR_D_Gain=1.25;
int FR_previous_error;
int FR_error_summation;


//____________________Valve_Position_PID FCN___________________
void  valve_control(int percentage){
int done =1;
while (done==1) {
  read_pot();
int Valve_error = percentage-pwm;
int PID_pwm = int((P_Gain*Valve_error)+(I_Gain*error_summation)+(D_Gain*(Valve_error-previous_error)));
error_summation = error_summation+Valve_error;
previous_error=Valve_error;
motor_PWM=abs(PID_pwm);

if(motor_PWM>=245){motor_PWM=240;}
if(motor_PWM<=150){motor_PWM=150;}


if(Valve_error>3){ dir =1; }else if(Valve_error<-3){ dir =2;}else{done=0; dir =3;}

  analogWrite(ENA,motor_PWM);

  if(dir == 1){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  }
  else if(dir == 2){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  }
  else{
  stop_valve();
  }

}


}

//____________________Flow Rate PID FCN_________________________
void FlowRate_PID(int Desired_FR){
 

FR_error = Desired_FR - litre_hr;

int PID_FR = int((FR_P_Gain*FR_error)+(FR_I_Gain*FR_error_summation)+(FR_D_Gain*(FR_error-FR_previous_error)));
FR_error_summation = FR_error_summation + FR_error;
FR_previous_error=FR_error;

if (PID_FR > 100) {
    PID_FR = 100;
  } else if (PID_FR < 0) {
    PID_FR = 0;
  }


if(FR_error>3){
valve_control(PID_FR); 
}




}