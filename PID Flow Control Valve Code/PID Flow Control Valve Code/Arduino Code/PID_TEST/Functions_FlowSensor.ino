const int FLOWSENSORPIN = 3;
unsigned int pulses;
unsigned long Currenttime;
unsigned long Looptime;
int litre_hr;
float setflowrate;

void flowSensor_init() {
  pinMode(FLOWSENSORPIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FLOWSENSORPIN), pulsecounter, RISING);
  // I want that whenever a pulse is felt pulsecounter adds 1
  Currenttime = millis();
  Looptime = Currenttime;
}





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
void pulsecounter() {
  pulses++;
}
/*------------------------------------*/
