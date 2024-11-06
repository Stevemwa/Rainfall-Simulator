

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
  if (Currenttime >= (Looptime + 500 )) {
    Looptime = Currenttime;
    litre_hr = pulses; //* (60 / 11);
    pulses = 0;
  }
  Currenttime = millis();
  delay(5);
  process_flowrate();
}

void process_flowrate() {
  litre_hrFiltered = floor(litre_hrFiltered) * prevFlowGain + litre_hr * currentFlowGain;
  litre_hrFiltered += biasFlow;
}

float flow_conversion_exponent(float input) {
return 1.1858*exp(0.0191*input);
}

float flow_conversion_linear(float input) {
  return (0.231052*input)-10.6054;
}
/*------------------------------------*/
void pulsecounter() {
  pulses++;
}
/*------------------------------------*/
