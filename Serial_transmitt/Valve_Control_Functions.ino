void Fully_Open(){
     does = 0;
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, LOW);
    analogWrite(ENA, 255);
    Serial.println(String(4));
    delay(4000);

}

void Fully_Closed(){

    does = 0;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 255);
    Serial.println(String(3));
    delay(4000);
  
}

int Valve_Angle(){

  unsigned long duration = pulseIn(4, LOW);
  return duration;
  
}
void Open(){
     does = 0;
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, LOW);
    analogWrite(ENA, 255);
    // Serial.println(String(4));
    delay(40);

}

void Closed(){

    does = 0;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 255);
    // Serial.println(String(3));
    delay(40);
  
}
void Stop(){
digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 255);

}