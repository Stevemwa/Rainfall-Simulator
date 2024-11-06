import controlP5.*;
ControlP5 cp5;

DropdownList seriallist;

int connectSerialTicker=0;


void LIST()
{
  seriallist =cp5.addDropdownList("SERIAL_PORTS")
    .setPosition(150,65);
    
}

void serial_init() {
  if (connectSerialTicker!=0)
  {
    println("CONNECTING TO ARDUINO");
    if (portName!="")
    {
      myPort= new Serial(this, portName, 9600);
    }
  }
}

void controlEvent(ControlEvent theEvent)
{
  if( theEvent.isController())
  {
    String callingList= theEvent.getController().getName();
    float calledValue=theEvent.getController().getValue();
    
    if(callingList=="SERIAL_PORTS")
    {
      
    }
    
  }
}
