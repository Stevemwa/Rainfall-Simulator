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
      case 1:
        // temp sensor code goes here
        Serial.println("Stream Pot Values");
        streamFlag = true;
        break;

      case 2:
        // humidity sensor code goes here
        Serial.println("Stop Pot Stream");
        streamFlag = false;
        break;

      default:
        Serial.println("Please choose a valid selection");
        streamFlag = streamFlag;
    }
  }
}
/*-----------------------------------*/
