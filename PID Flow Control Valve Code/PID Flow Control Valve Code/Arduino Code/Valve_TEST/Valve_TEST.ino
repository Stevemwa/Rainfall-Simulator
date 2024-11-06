/*************************************************/
/*
   Test code for valve opening and closing
*/
/*************************************************/

// Motor pins definitions
const int IN1 = 12;
const int IN2 = 13;
const int ENA = 9;

// Potentiometer definitions
const int POTPIN = A3;
const int MAXPOT = 78;
const int MINPOT = 44;
int potReading = 0 ;

bool waitInput = true;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Serial.println("*******: ARDUINO ONLINE");

}

void loop() {
  // put your main code here, to run repeatedly:
  // User message requesting for input
  if (waitInput) {
    Serial.println("Arduino in MANUAL MODE");
    Serial.println("Input : [1] Close Valve");
    Serial.println("Input : [2] Open Valve");
  }

  while (Serial.available() == 0) {
  }

  // Waiting for user to give input
  unsigned int menuChoice = Serial.parseInt();
  if (menuChoice == 0) {
    waitInput = false ;
  } else {
    waitInput = true;
  }


  //Serial.print("[ ");
 // Serial.print(menuChoice);
  //Serial.println(" ]");

  if (menuChoice != 0) {
    switch (menuChoice) {
      case 1:
        // temp sensor code goes here
        Serial.println("Closing Valve");
        close_valve();
        break;

      case 2:
        // humidity sensor code goes here
        Serial.println("Opening Valve");
        open_valve();
        break;

      default:
        Serial.println("Please choose a valid selection");
    }
  }
  Serial.flush();
}

void read_pot() {
  potReading = analogRead(POTPIN);
}

void open_valve() {
  read_pot();
  Serial.println(potReading);
}

void close_valve() {
  read_pot();
  Serial.println(potReading);
}
