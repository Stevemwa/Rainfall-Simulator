
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
