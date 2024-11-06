/*-----------------------------------*/
String process_serial() {
  String parsedData[] = split(val, ',');
  if (parsedData[0].equals("#") == true) {
      serialBuffer[0] = parsedData[i + 1];
    }
  } else {
    serialBuffer[0]  = parsedData[i + 1];
  }
  return serialBuffer[0];
}

/*-----------------------------------*/
void get_user_input() {
  if (Serial.available() > 0) {
    val = Serial.readStringUntil('\n');
    if (val != 0) {
      //trim whitespace and formatting characters (like carriage return)
      //val = Serial.trim(val);
      process_serial();
    }

    Serial.println(serialBuffer[0]);
}

/*-----------------------------------*/
void process_user_input() {
  if ((menuChoice != 0) && (menuChoice <= 10)) {
    //Serial.println(menuChoice);
    switch (menuChoice) {
      case 1:
        streamFlag = true;
        break;

      case 2:
        streamFlag = false;
        break;

      case 3:
        // Fully open the valve
        full_open_valve();
        break;

      case 4:
        // Fully close the valve
        full_close_valve();
        break;

      case 5:
        valveMode = MANUAL;
        break;

      case 6:
        slight_flag = true;
        slight_open_valve();
        break;

      case 7:
        slight_flag = true;
        slight_close_valve();
        break;

      case 8:
        Serial.println("8");
        stop = true;
        stop_valve();

      case 9:
        valveMode = AUTOMATIC;

      default:
        streamFlag = streamFlag;
        //Serial.println("S");
    }
  } 
  
  //else if ((menuChoice != 0) && (menuChoice > 10) && (mode)) {
  //  cast = int(menuChoice) - 10;
  //}
  menuChoice = 0;
}
/*-----------------------------------*/

/*
  Current Serial Commands:8
  1: *** Stream Data - True
  2: *** Stream Data - False
  3: *** Open Fully Valve
  4: *** Close Fully Valve
  5: *** Calibrate Flowmeter
  6: Opening Pulse Valve (150)
  7: Closing Pulse Valve (150)
  8: Opening Pulse Valve (100)
  9: Closing Pulse Valve (100)

*/
