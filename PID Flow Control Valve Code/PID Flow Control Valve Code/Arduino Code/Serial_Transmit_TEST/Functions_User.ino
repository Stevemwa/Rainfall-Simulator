/*-----------------------------------*/
void get_user_input() {
  if (Serial.available() > 0) {
    // Waiting for user to give input
    menuChoice = Serial.parseInt();
    if (menuChoice == 0) {
      waitFlag = false ;
    } else {
      waitFlag = true;
    }
  }
}
/*-----------------------------------*/
void process_user_input() {
  if (menuChoice != 0) {
    switch (menuChoice) {
      case 1:
        // Stream Flowrate readings
        streamFlag = true;
        break;

      case 2:
        // Stop Stream Flowrate readings
        streamFlag = false;
        break;

      default:
        streamFlag = streamFlag;
        Serial.println("S");

    }
  }
}
/*-----------------------------------*/
