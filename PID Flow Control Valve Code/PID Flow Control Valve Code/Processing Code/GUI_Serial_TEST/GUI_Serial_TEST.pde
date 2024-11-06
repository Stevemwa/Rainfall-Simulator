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
String portName = " ";

float flowRate = 0;

color GREEN = #6AAB9C;
color ORANGE = #FA9284;
color RED = #E06C78;
color BLUE = #5874DC;
color NAVY = #384E78;
color WHITE = #DDDDDA;
color GRAY = #878787;

String[] serialBuffer = {"0", "0", "0", "0"};

void setup () {
  size(800, 600);        // window size
  cp5 = new ControlP5(this);
  gui_init();
}

void draw () {
  background(NAVY);
  fill(BLUE);
  rect(0, 0, width, 40);
  noStroke();
  fill(WHITE);
  textSize(32);
  text("Flow Control Project", (width/2)-150, 35);

  textSize(20);
  text("Serial Port:", 50, 80);
  text("DATA Stream:", 50, 150);
  text("Incoming DATA:", 300, 160);
  text("FlowRate (L/HR):", 300, 210);
  text(serialBuffer[0], 450, 210);
  text("Valve Position :", 315, 240);
  text(serialBuffer[1], 450, 240);
  text("Valve Status :", 330, 270);
  String Vstatus = "NO CONNECTION";
  switch(serialBuffer[2]) {
  case "2":
    Vstatus = "OPENED";
    break;
  case "3":
    Vstatus = "CLOSED";
    break;
  case "4":
    Vstatus = "ACTIVE";
    break;
  default:
    break;
  }
  text(Vstatus, 450, 270);


  fill(BLUE);
  rect(0, 300, width, 35);
  noStroke();
  fill(WHITE);
  textSize(32);
  text("Control Modes: ", 30, 330);
}
