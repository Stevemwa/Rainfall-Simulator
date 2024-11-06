import processing.serial.*;


//_________________________SERIAL-VAR________________________________________
Serial myPort;
String portName="";
int inByte = -1;
int count = 10;
int Manualctrl=0;
String Received;

//_________________________GUI variables______________________________________
HScrollbar hScrollbar;
HScrollbar hSScrollbar;

ButtonDisplay DataON;
ButtonDisplay ValveOpen;
ButtonDisplay ValveClose;


color GREEN = #6AAB9C;
color ORANGE = #FA9284;
color RED = #E06C78;
color BLUE = #5874DC;
color NAVY = #384E78;
color WHITE = #DDDDDA;
color GRAY = #878787;

int L;
boolean connected ;



void setup() {
  size(800, 600);
  
  initSerial();

  //____________Create a horizontal scrollbar_______________________
  hScrollbar = new HScrollbar(10, 500, 200, 20);
  hSScrollbar = new HScrollbar(370, 500, 200, 20);
  
  //__________Create Buttons________________________________________
  DataON = new ButtonDisplay(10,420,50,50,GREEN,BLUE,NAVY,"HOME");
  ValveOpen = new ButtonDisplay(150,420,100,30,RED,BLUE,NAVY,"VALVE OPEN");
  ValveClose = new ButtonDisplay(300,420,100,30,RED,BLUE,NAVY,"VALVE CLOSE");
  
  //_________Create DropDown menu__________________________________

   
}

void draw() {

  Flow_GUI();
//if(connected){ 
    if (myPort.available()>0) {
      String data = myPort.readStringUntil('\n');
      if (data != null) {
        Received = data;
        data = trim(data); // Remove leading/trailing whitespace
        inByte = int(data);
      }
    }
    
  if(DataON.isClicked()){
  count = (count + 1) % 256; // Wrap the count around
  myPort.write(str(count));
  }
  delay(10);
  if(ValveOpen.isClicked()){
  myPort.write(str(3));
  }
  if(ValveClose.isClicked()){
  myPort.write(str(4));
  }
  
  } 
 
 
 
 //}

void initSerial() {
  String portName = Serial.list()[4]; // Change the index based on your setup
  myPort = new Serial(this, portName, 9600);
}
