void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("S");   // send a capital S
    delay(300);
  }
}

String create_package() {
  return (String(litre_hr)+':'+String(int(potFiltered))+':'+String(valvePosition));
}

void serial_transmit_packet() {
  Serial.println(create_package());
}
