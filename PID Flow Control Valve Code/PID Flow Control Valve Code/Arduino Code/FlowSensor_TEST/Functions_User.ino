/*-----------------------------------*/
void get_user_input() {
  if (Serial.available() != 0) {
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
      case 7:
        // Stream Flowrate readings
        Serial.println("Stream flowrate Values");
        streamFlag = true;
        break;

      case 8:
        // Stop Stream Flowrate readings
        Serial.println("Stop flowrate Stream");
        streamFlag = false;
        break;

      default:
        Serial.println("Please choose a valid selection");
        streamFlag = streamFlag;
    }
  }
}
/*-----------------------------------*/
