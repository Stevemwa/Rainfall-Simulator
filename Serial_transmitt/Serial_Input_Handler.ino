
void Serial_Input(){
   if (does == 1) {
     delay(10);
  Serial.println(String(1));
  
  }

    if (does == 5) {
  Valve_Pwm = Valve_Pwm +10;
  does =0;
  }

  if (does == 6) {
  Valve_Pwm = Valve_Pwm -10;
  does =0;
  }
  
}