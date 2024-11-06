Serial myPort;
String val;     // Data received from the serial port

DropdownList seriallist;
int connectSerialTicker=0;
boolean firstContact = false;
int messageToSend = 0;
String portName = " ";

//_____________________________________________________________________________________________________
void LIST()
{
  String[] listPortName;
  listPortName = new String[5]; 
  int L=Serial.list().length;
  
    for (int i=0; i<Serial.list().length; i++) {
    listPortName[i] = Serial.list()[i];
     }
  
seriallist =cp5.addDropdownList("SERIAL_PORTS")
    .setBackgroundColor(color(190))
    .setItemHeight(30)
    .setHeight(120)
    .setBarHeight(20)
    .setPosition(160,50);
    for(int i =0;i<L;i++){
     seriallist.addItem(listPortName[i], 0); 
    }
    //.addItem(listPortName[0], 0);
  //serialList.getCaptionLabel().set("Select Serial Port");
  
 // for (int i=0; i<Serial.list().length; i++) {
 //   listPortName = Serial.list()[i];
 //serialList.addItem(listPortName, 0);
 // }
  
 // serialList.setColorBackground(color(60));
 // serialList.setColorActive(color(255, 128));
   
}


//_________________________________________________________________________________________________
void serial_init() {
  if (Status==0) {
    println("Connecting to Arduino");
    if (portName != " ") {
      myPort = new Serial(this, portName, 9600);
      myPort.bufferUntil('\n');
      
    } else {
      println("ERROR: problem connecting to Arduino");
      println("Try selecting a com port");
    }
  }
  
}

//___________________________________________________________________________________________________
void serialEvent(Serial myPort) {
  //put the incoming data into a String
  val = myPort.readStringUntil('\n');

  //make sure our data isn't empty before continuing
  if (val != null) {
    //trim whitespace and formatting characters (like carriage return)
    val = trim(val);

    //look for our 'S' string to start the handshake
    //if it's there, clear the buffer, and send a request for data
    if (firstContact == false) {
      if (val.equals("S")) {
        myPort.clear();
        firstContact = true;
        myPort.write("H");
        println("contact");
        Status=1;
        customize_connect_button();
      }
    } else {

      //if we've already established contact, keep getting and parsing data
      //println(val);
      process_serial();
      println(process_serial());
      flowRate = float(val);
    }
  }
}

String[] process_serial() {
  String[] parsedData = split(val, ':');
  for (int i = 0; i < parsedData.length && i < 4; i++) {
    serialBuffer[i] = parsedData[i];
  }
  return parsedData;
}
void serial_readString(Serial port) {
  if (port.available() > 0)
  {  // If data is available,
    val = port.readStringUntil('\n');         // read it and store it in val
  }
  if (val != null) {
    println(val); //print it out in the console
  }
}

void serial_readBytes() {
  // get the byte:
  int inByte = myPort.read();
  // print it:
  println(inByte);
}


/*
H => Handshaking (Processing)
 S => Handshaking (Arduino)
 C => Commands
 D => Desired Flowrate
 F => Flowrate
 P => Pot position
 */
