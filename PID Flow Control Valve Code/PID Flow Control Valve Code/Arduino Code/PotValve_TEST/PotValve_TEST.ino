/*************************************************/
/*
   Test code for potentiometer reading
*/
/*************************************************/

// Motor pins definitions
const int IN1 = 7;
const int IN2 = 8;
const int ENA = 6;

// Potentiometer definitions
const int POTPIN = A3;
const int MAXPOT = 78;
const int MINPOT = 64;
int potReading = 0 ;

// Potentiometer Mapping and Filterning
int potMapped = 0;
float potFiltered = 0;
float prevGain = 0.9;
float currentGain = 1 - prevGain;
float bias = 1;

// System Flags
bool waitFlag = true;
bool streamFlag = false;
unsigned int menuChoice = 0;
/*-----------------------------------*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  get_user_input();
  process_user_input();

  if (streamFlag) {
    pot_processing();
    Serial.println(potFiltered);
  }
  Serial.flush();
}
/*-----------------------------------*/
