/*-----------------------------------*/
void get_user_input() {
  if (Serial.available() > 0) {
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
    //Serial.println(menuChoice);
    switch (menuChoice) {
      case 1:
        // Stream Flowrate readings
        streamFlag = true;
        break;

      case 2:
        // Stop Stream Flowrate readings
        streamFlag = false;
        break;

      case 3:
        // Stream Flowrate readings
        while (potFiltered >= POTMIN) {

          open_valve();

          pot_processing();
        }
        stop_valve();
        valvePosition = OPENED;
        break;
        
      case 4:
        // Stop Stream Flowrate readings
        while (potFiltered <= POTMAX) {
          close_valve();
          pot_processing();
        }
        stop_valve();
        valvePosition = CLOSED;
        break;

      default:
        streamFlag = streamFlag;
        Serial.println("S");

    }
  }
}
/*-----------------------------------*/
