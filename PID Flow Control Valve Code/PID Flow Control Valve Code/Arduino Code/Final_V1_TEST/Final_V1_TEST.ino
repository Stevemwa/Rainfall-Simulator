/*************************************************/
/*
   Test code for Flow sensor reading
*/
/*************************************************/
// System Flags
bool waitFlag = true;
bool streamFlag = false;
unsigned int menuChoice = 0;
/*************************************************/
const int FLOWSENSORPIN = 3;
unsigned int pulses;
unsigned long Currenttime;
unsigned long Looptime;
int litre_hr;
float setflowrate;
/*************************************************/
// Motor pins definitions
const int IN1 = 7;
const int IN2 = 8;
const int ENA = 6;
/*************************************************/
String delimiter = ",";
/*************************************************/
// Potentiometer definitions
const int POTPIN = A3;
const int POTMAX = 35;
const int POTMIN = 21;
int potReading = 0 ;

float valve_setpoint = 70;

#define CW 0
#define CCW 1
//____________________
// Potentiometer Mapping and Filterning
float potMapped = 0;
float potFiltered = 0;
float prevGain = 0.925;
float currentGain = 1 - prevGain;
float bias = 0.65;
//____________________
// Flowrate Filterning

float litre_hrFiltered = 0;
float prevFlowGain = 0.925;
float currentFlowGain = 1 - prevFlowGain;
float biasFlow = 0.65;
//____________________
const int OPENING = 2;
const int CLOSING = 3;
const int STOPPED = 4;
int valveStatus = STOPPED;

//____________________
const int OPENED = 2;
const int CLOSED = 3;
const int ACTIVE = 4;
int valvePosition = ACTIVE;
/*************************************************/
/*-----------------------------------*/
void setup() {
  // put your setup code here, to run once:
  valve_init();
  flowSensor_init();
  Serial.begin(9600);
  establishContact();
  //Serial.println("*******: ARDUINO ONLINE");
}
/*-----------------------------------*/
void loop() {
  if (waitFlag) {
    //print_welcome();
    waitFlag = false;
  }
  get_user_input();
  process_user_input();

  //if (streamFlag) {
  read_flowRate();
  pot_processing();
  //valve_control(potFiltered, valve_setpoint);
  //pot_processing();
  serial_transmit_packet();
  // }
  // Serial.flush();
}
/*-----------------------------------*/
