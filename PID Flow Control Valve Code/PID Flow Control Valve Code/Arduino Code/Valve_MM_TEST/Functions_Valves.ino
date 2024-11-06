void open_valve() {
  valveStatus = OPENING;
  analogWrite(ENA, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void close_valve() {
  valveStatus = CLOSING;
  analogWrite(ENA, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void stop_valve() {
  valveStatus = STOPPED;
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
