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
// Motor pins definitions
const int IN1 = 7;
const int IN2 = 8;
const int ENA = 6;

// Potentiometer definitions
const int POTPIN = A3;
const int POTMAX = 78;
const int POTMIN = 66;

int potReading = 0 ;

// Potentiometer Mapping and Filterning
int potMapped = 0;
float potFiltered = 0;
float prevGain = 0.75;
float currentGain = 1 - prevGain;
float bias = 0;

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
  Serial.begin(115200);
 
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
  process_desired_flow(5);

  if (streamFlag) {
    read_flowRate();
    pot_processing();
    serial_transmit_packet();
  }
  Serial.flush();
}
/*-----------------------------------*/
