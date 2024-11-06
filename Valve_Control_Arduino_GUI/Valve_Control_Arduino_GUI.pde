import controlP5.*;
import processing.serial.*;

ControlP5 cp5;

int count = 0;
//_________________ConnectStatus Array Togle______________
int Status = 0;

//_______________button pressed variable___________________
int data = 0;
int mode = 0;
int valvePercent;
float ManualModeSliderVal=10;
int valveOpenTicker, valveCloseTicker = 0;

//_______________Data Variables____________________________
float flowRate;
String[] serialBuffer = {"0", "0", "0", "0"};


//___________________Sliders_______________________________
float sliderValue = 0;

//_________________GUI Colors______________________________
color GREEN = color(0,200,0);
color ORANGE = #E14254;
color RED = color(230,0,0);
color BLUE = #3524FF;
color NAVY = #384E78;
color WHITE = #DDDDDA;
color GRAY = #878787;
color DARK = #121222;

String[] ConnectStatus;

void setup() {
  size(800, 650);
  All_Buttons();
  Sliders();
  LIST();
  //customize_droplist(serialList);
  
  

  ConnectStatus = new String[8]; // Initialize the array
  ConnectStatus[0] = "DISCONNECTED";
  ConnectStatus[1] = "CONNECTED";
  ConnectStatus[2] = "MANUAL";
  ConnectStatus[3] = "AUTOMATIC";
  ConnectStatus[4] = "UNSELECTED";
  ConnectStatus[5] = "OPENED";
  ConnectStatus[6] = "CLOSED";
  ConnectStatus[7] = "ACTIVE";
}

void draw() {
  background(NAVY);
  fill(DARK);
  rect(0, 0, 800, 30);
  fill(WHITE);
  textSize(26);
  textAlign(CENTER, CENTER);
  text("FLOW CONTROl SYSTEM", 400, 15);
  
  fill(RED);
  textSize(26);
  textAlign(CENTER, CENTER);
  text("DATA STREAM ", 630, 50);
  text("SERIAL PORT: ", 80, 57);
 
  text(" INCOMING DATA ", 630, 140);
  fill(WHITE);
  textSize(24);
  if(data !=0){
  
  text("FLOW RATE(L/HR): " + serialBuffer[0], 600, 170);
  text(" VALVE POSITION: " +serialBuffer[1] , 600, 210);
  
  }
  
  fill(GRAY);
  textSize(20);
  switch(serialBuffer[2]){
     case "2":
    text("   VALVE STATUS: " + ConnectStatus[5], 600, 260);
    break;
  case "3":
     text("   VALVE STATUS: " + ConnectStatus[6], 600, 260);
    break;
  case "4":
     text("   VALVE STATUS: " + ConnectStatus[7], 600, 260);
    break;
  default:
      text("   VALVE STATUS: " + ConnectStatus[0], 600, 260);
    break; 
    
  }
 
  
  
  if(mode == 0){
    textSize(20);
    text("CONTROL MODE: " + ConnectStatus[2] , 600, 290);
  }else{
    textSize(20);
    text("CONTROL MODE: " + ConnectStatus[3] , 600, 290);
  }
 
  
  fill(DARK);
  rect(0, 315, 800, 30);
  fill(WHITE);
  textSize(26);
  textAlign(CENTER, CENTER);
  text("VALVE CONTROL MODES", 400, 330);
  
  
  
}
