/*************************************************/
/*
   Test code for Flow sensor reading
*/
/*************************************************/
const int FLOWSENSORPIN = 3;
unsigned int pulses;
unsigned long Currenttime;
unsigned long Looptime;
int litre_hr;
float setflowrate;


// System Flags
bool waitFlag = true;
bool streamFlag = false;
unsigned int menuChoice = 0;
/*-----------------------------------*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(FLOWSENSORPIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(FLOWSENSORPIN), pulsecounter, RISING);
  // I want that whenever a pulse is felt pulsecounter adds 1

  Currenttime = millis();
  Looptime = Currenttime;
  establishContact();
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
    read_flowRate();
    Serial.println(litre_hr);
  }
  Serial.flush();
}
/*-----------------------------------*/
