
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
  potMapped = map(potReading, 0, 1023, 0, 100);
  potFiltered = int(floor(potFiltered) * prevGain + potMapped * currentGain);
  potFiltered += bias;

  if (potFiltered >= POTMAX) {
    valvePosition = CLOSED;
  } else if (potFiltered <= POTMIN) {
    valvePosition = OPENED;
  } else {
    valvePosition = ACTIVE;
  }
}
/*------------------------------------*/

void open_valve() {
  if (valvePosition != OPENED) {
    analogWrite(ENA, 200);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else {
    stop_valve();
  }
}

/*------------------------------------*/
void close_valve() {
  if (valvePosition != CLOSED) {
    analogWrite(ENA, 200);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    stop_valve();
  }
}

/*------------------------------------*/
void stop_valve() {
  valveStatus = STOPPED;
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
/*------------------------------------*/
