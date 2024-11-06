
void valve_init() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}
/*-----------------------------------*/
void read_pot() {
  potReading = analogRead(POTPIN);
}
/*-----------------------------------*/
void pot_processing() {
  potReading = analogRead(POTPIN);
  potMapped = map(potReading, 0, 1023, 100, 0);
  potFiltered = floor(potFiltered) * prevGain + potMapped * currentGain;
  potFiltered += bias;
}
/*------------------------------------*/

void open_valve() {
  valveStatus = OPENING;
  analogWrite(ENA, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

/*------------------------------------*/
void close_valve() {
  valveStatus = CLOSING;
  analogWrite(ENA, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

/*------------------------------------*/
void stop_valve() {
  valveStatus = STOPPED;
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
/*------------------------------------*/
void full_close_valve() {
  while (potFiltered >= POTMIN) {
    close_valve();
    pot_processing();
  }
  stop_valve();
  valvePosition = CLOSED;
}
/*------------------------------------*/
void full_open_valve() {
  while (potFiltered <= POTMAX) {
    open_valve();
    pot_processing();
  }
  stop_valve();
  valvePosition = OPENED;
}
/*------------------------------------*/


/*------------------------------------*/
void test_open_valve() {
  while (potFiltered >= POTMIN) {
    open_valve();
    pot_processing();
  }
  stop_valve();
  valvePosition = OPENED;
}
/*------------------------------------*/

void pulse_valve(boolean dir, int PWM) {
  if (dir == CW) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (dir == CCW) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  digitalWrite(ENA, PWM);
  delay(200);
}
/*------------------------------------*/
void valve_control(float current, float setpoint) {
  float error = setpoint - current;
  boolean valve_dir = (error > 0) ? CW : CCW;
  float mag = sqrt(error * error);
  if (mag >= 1) {
    pulse_valve(valve_dir, 150);
  }
  else {
    stop_valve();
  }
}
