/*************************************************/
/*
   Test code for Sending a command to the arduino and 
   receiveing a data stream from it
*/
/*************************************************/
import processing.serial.*;
Serial myPort;
String val;     // Data received from the serial port
boolean firstContact = false;
int messageToSend = 0;


void setup () {
  size(800, 600);        // window size
  println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 115200);
  myPort.bufferUntil('\n'); 
}

void draw () {
}
