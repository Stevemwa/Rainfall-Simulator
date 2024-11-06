

/*************************************************/

/*------------------------------------------------*/
public void CONNECT() {
  serial_init();
}
/*------------------------------------------------*/

public void DATA_ON() {
  if (dataONTicker !=0) {
    println("Streaming DATA_ON");
    myPort.write('1');
    customize_button_color(dataON, GREEN);
    customize_button_color(dataOFF, RED);
  }
  dataONTicker++;
}

/*------------------------------------------------*/
public void DATA_OFF() {
  if (dataOFFTicker !=0) {
    println("Streaming DATA_OFF");
    myPort.write('2');
    customize_button_color(dataOFF, GREEN);
    customize_button_color(dataON, RED);
  }
  dataOFFTicker++;
}

/*------------------------------------------------*/
public void VALVE_OPEN() {
  if (valveOpenTicker !=0) {
    println("Command VAVLVE_OPEN");
    myPort.write('3');
    customize_button_color(valveOpen, GREEN);
    customize_button_color(valveClose, RED);
  }
  valveOpenTicker++;
}
/*------------------------------------------------*/
public void VALVE_CLOSE() {
  if (valveCloseTicker !=0) {
    println("Command VAVLVE_CLOSED");
    myPort.write('4');
    customize_button_color(valveClose, GREEN);
    customize_button_color(valveOpen, RED);
  }
  valveCloseTicker++;
}
/*------------------------------------------------*/

void slider(float value) {
  desiredValvePosition = value;
  String message = "D:" + str(value);
  myPort.write(message);
  println("a slider event.value = "+value);
}
