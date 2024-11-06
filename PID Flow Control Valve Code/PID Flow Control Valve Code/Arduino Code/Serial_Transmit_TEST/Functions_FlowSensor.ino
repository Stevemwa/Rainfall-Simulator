/*------------------------------------*/
// we are reading frequency and f=11*Q
//(where Q is flow rate
//, so Q=f/11, then multiply 60 to change to litres per hr)

void read_flowRate() {
  Currenttime = millis();
  if (Currenttime >= (Looptime + 500)) {
    Looptime = Currenttime;
    litre_hr = pulses * (60 / 11);
    pulses = 0;
  }
  Currenttime = millis();
  delay(5);
}

/*------------------------------------*/
void pulsecounter(){
  pulses++;
}
/*------------------------------------*/
