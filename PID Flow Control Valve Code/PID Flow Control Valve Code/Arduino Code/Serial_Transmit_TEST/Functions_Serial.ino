void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("S");   // send a capital S
    delay(300);
  }
}
