void Flow_GUI(){
  background(hScrollbar.getPos(), 120, 167);//background(R,G,B);
  Manualctrl = int(hSScrollbar.getPos());

  hScrollbar.update();
  hScrollbar.display();
  
  hSScrollbar.update();
  hSScrollbar.display();
  
  DataON.display();
  ValveOpen.display();
  ValveClose.display();
  
  
   fill(0);
  textSize(20);
  text("Scroll to change background color" + Manualctrl , 170, 300);
  text("Received: " + inByte, 170, 330);
  text("Sent: " + count, 170, 360);
 
  


}
