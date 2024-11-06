void controlEvent(ControlEvent event) {
 //______________CONNECT BUTTON CALLBACK___________ 
  if (event.getName().equals("Connect")) {
    if(Status==0){
     portName =  Serial.list()[int(seriallist.getValue())];
     serial_init();
    }
  }
 //______________DATA BUTTONS CALLBACK___________ 
  if (event.getName().equals("DataOn")) {
    
    if(data ==0){
      data++;
      DataOn.setColorBackground(GREEN);
      DataOff.setColorBackground(RED);
      println("Streaming DATA_ON");
      myPort.write('1');
      
    
    }
    
  }
  if (event.getName().equals("DataOff")) {
    
    if(data!=0){
    data--;
    DataOn.setColorBackground(RED);
    DataOff.setColorBackground(GREEN);
    println("Streaming DATA_OFF");
    myPort.write('2');
    }
    
  }
 //________________MODES BUTTONS ____________ 
  if (event.getName().equals("ManualMode")) {
    if(mode !=0){
      mode=0;
      ManualMode.setColorBackground(GREEN);
      AutoMode.setColorBackground(RED);
    }
  }
  
   if (event.getName().equals("AutoMode")) {
     
    if(mode !=1){
      mode=1;
      ManualMode.setColorBackground(RED);
      AutoMode.setColorBackground(GREEN);
    }
    
  }
  
   //________________MANUAL MODE +- BUTTONS ____________ 
  if (event.getName().equals("ManualModePlus")) {
    if(mode ==0){
      ManualModeSliderVal=ManualModeSliderVal+10;
      ManualmodeSlider.setValue(ManualModeSliderVal);
    }
  }
  
   if (event.getName().equals("ManualModeMinus")) {
    
    if(mode ==0){
       ManualModeSliderVal=ManualModeSliderVal-10;
      ManualmodeSlider.setValue(ManualModeSliderVal);
    }
    
  }
  //__________MANUAL MODE OPEN AND CLOSE BUTTONS_________
   if (event.getName().equals("ManualModeOpen")) {
    if(mode ==0){
     if (valveOpenTicker !=0) {
    println("Command VAVLVE_OPEN");
    myPort.write('3');
    
  }
  valveOpenTicker++;
    }
  }
  
   if (event.getName().equals("ManualModeClose")) {
    
    if(mode ==0){
      if (valveCloseTicker !=0) {
    println("Command VAVLVE_CLOSED");
    myPort.write('4');
    
  }
  valveCloseTicker++;
    }
    
  }
  
  //______________MANUAL MODE SLIDER_____________________
  if (event.getName().equals("VALVE POSITION MANUAL")) {
    if(mode ==0){
    sliderValue = event.getValue();
    }
    
  }
  
  //________________AUTO MODE SLIDER_____________________
  if (event.getName().equals("VALVE STATUS AUTO")) {
   
  }
   
  
}

//_____________________________________________________________________________________________
 void customize_connect_button()
 {
  Connect.setColorBackground(GREEN);
  Connect.setLabel("CONNECTED");
}
  
