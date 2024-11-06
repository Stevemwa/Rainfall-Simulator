Button Connect, DataOn, DataOff, ManualMode, AutoMode, ManualModePlus, ManualModeMinus, Valve_Open, Valve_Close;
DropdownList serialList;
Slider ManualmodeSlider,AutomodeSlider;

void All_Buttons(){
  //__________________CONNECT TO COM BUTTON_____________________
  cp5 = new ControlP5(this);
           Connect = cp5.addButton("Connect")
                             .setPosition(300, 65)
                             .setSize(100, 40)
                             .setLabel("Connect");
                             
  //__________________DATA ON BUTTON_____________________
  cp5 = new ControlP5(this);
        DataOn = cp5.addButton("DataOn")
                             .setPosition(470, 75)
                             .setSize(100, 40)
                             .setColorBackground(RED)
                             .setLabel("Data ON");
                             
                             
                             
                             
 //__________________DATA OFF BUTTON_____________________
  cp5 = new ControlP5(this);
       DataOff = cp5.addButton("DataOff")
                             .setPosition(650, 75)
                             .setSize(100, 40)
                             .setColorBackground(GREEN)
                             .setLabel("DATA OFF");
                             
 //__________________MANUAL MODE BUTTON_____________________
  cp5 = new ControlP5(this);
        ManualMode = cp5.addButton("ManualMode")
                             .setPosition(100, 350)
                             .setSize(100, 40)
                             .setColorBackground(GREEN)
                             .setLabel("MANUAL MODE");                            
                             

  //__________________AUTO MODE BUTTON_____________________
  cp5 = new ControlP5(this);
         AutoMode = cp5.addButton("AutoMode")
                             .setPosition(550, 350)
                             .setSize(100, 40)
                             .setColorBackground(RED)
                             .setLabel("AUTOMATIC MODE");  
  
   //__________________MANUAL MODE + BUTTON_____________________
  cp5 = new ControlP5(this);
        ManualModePlus = cp5.addButton("ManualModePlus")
                             .setPosition(20, 450)
                             .setSize(100, 40)
                             .setColorBackground(ORANGE)
                             .setLabel("VALVE +");                            
                             

  //__________________MANUAL MODE - BUTTON_____________________
  cp5 = new ControlP5(this);
          ManualModeMinus = cp5.addButton("ManualModeMinus")
                             .setPosition(180, 450)
                             .setSize(100, 40)
                             .setColorBackground(BLUE)
                             .setLabel("VALVE -");    
 
    //__________________MANUAL MODE VALVE OPEN_____________________
  cp5 = new ControlP5(this);
        Valve_Open = cp5.addButton("ManualModeOpen")
                             .setPosition(10, 510)
                             .setSize(120, 40)
                             .setColorBackground(BLUE)
                             .setLabel("VALVE OPEN");                            
                             

  //__________________AUTO MODE VALVE CLOSE_____________________
  cp5 = new ControlP5(this);
          Valve_Close = cp5.addButton("ManualModeClose")
                             .setPosition(170, 510)
                             .setSize(120, 40)
                             .setColorBackground(GRAY)
                             .setLabel("VALVE CLOSE"); 
                                                         
                             
}

void Sliders(){
  cp5 = new ControlP5(this);
  ManualmodeSlider=cp5.addSlider("VALVE POSITION MANUAL")
     .setPosition(10, 400)
     .setSize(250, 20)
     .setRange(0, 100)
     .setValue(12)
     .setNumberOfTickMarks(11)
     .setColorForeground(BLUE)
     .setColorBackground(DARK);
     
     
  cp5 = new ControlP5(this);
  AutomodeSlider=cp5.addSlider("VALVE STATUS AUTO")
     .setPosition(450, 400)
     .setSize(250, 20)
     .setRange(0, 100)
     .setValue(10)
     .setNumberOfTickMarks(11)
     .setColorForeground(BLUE)
     .setColorBackground(DARK);
}
