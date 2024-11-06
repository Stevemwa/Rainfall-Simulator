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
        // Stream data to serial
        Serial.println("Stream Pot Values");
        streamFlag = true;
        break;

      case 2:
        // Stop streaming data to serial
        Serial.println("Stop Pot Stream");
        streamFlag = false;
        break;

      case 4:
        // Open Valve
        Serial.println("Opening Valve");

        while (potFiltered >= POTMIN) {
          if (valveStatus != OPENING) {
            open_valve();
          }
          pot_processing();
        }
        stop_valve();
        valvePosition = OPENED;
        streamFlag = true;
        
        break;

      case 5:
        // Close Valve
        Serial.println("Closing Valve");
        
        while (potFiltered <= POTMAX) {
          if (valveStatus != CLOSING) {
            close_valve();
          }
          pot_processing();
        }
        stop_valve();
        valvePosition = CLOSED;
        streamFlag = true;
        break;

      default:
        Serial.println("Please choose a valid selection");
        streamFlag = streamFlag;
    }
  }
}
/*-----------------------------------*/
