/*************************************************/
/*
   Test code for Manually opening and closing the valve
   and stopping based on the value of the valve potentiometer
*/
/*************************************************/

// Motor pins definitions
const int IN1 = 7;
const int IN2 = 8;
const int ENA = 6;

// Potentiometer definitions
const int POTPIN = A3;

const int POTMAX = 75; // When closing
const int POTMIN = 65; // When Opening

int potReading = 0 ;

// Potentiometer Mapping and Filterning
int potMapped = 0;
float potFiltered = 0;
float prevGain = 0.95;
float currentGain = 1 - prevGain;
float bias = 0;

// System Flags
bool waitFlag = true;
bool streamFlag = false;

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

unsigned int menuChoice = 0;
/*-----------------------------------*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Serial.println("*******: ARDUINO ONLINE");
}
/*-----------------------------------*/
void loop() {

  if (waitFlag) {
    print_welcome();
    waitFlag = false;
  }

  pot_processing();
  get_user_input();
  process_user_input();

  if (streamFlag) {
    Serial.println(potFiltered);
  }
  Serial.flush();
}
/*-----------------------------------*/
