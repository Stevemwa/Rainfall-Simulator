
#define IN1 7
#define IN2 8
#define ENA 6
#define ValveAnglePin A3
int does = 0;
int Valve_Pwm = 0;
int Connected = 0;
String val;  // Data received from the serial port
int Current;
void setup() {
  pinMode(IN1, OUTPUT);  // Set pin as OUTPUT
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ValveAnglePin, INPUT);  //Set the pin to receive NE555 pulses as Input

  Serial.begin(9600);  // Start serial communication at 9600 bps
}

void loop() {

  //   if (Serial.available() > 0) {          // If data is available to read,
  //     val = Serial.readStringUntil('\n');  // Read the data until a newline character is encountered
  //     does = atoi(val.c_str());            // Convert the string to an integer
  //     delay(20);
  //   }

  //   Serial_Input();//Handle inputs from Processing

  //  if(Connected==1){
  // Serial.println(String(Valve_Angle()));//Send Flowrate

  //  }



Serial.println(String(Valve_Angle()));//Send Flowrate
Closed();
delay(1500);
Serial.println(String(Valve_Angle()));//Send Flowrate
Stop();
delay(5000);
Open();
delay(1500);
Serial.println(String(Valve_Angle()));//Send Flowrate
Stop();
delay(5000);


}







