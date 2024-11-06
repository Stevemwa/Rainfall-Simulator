//______________________________SCROLL BAR CLASS______________________________________
class HScrollbar {
  float x, y;
  float swidth, sheight;
  float spos;
  float sposMin, sposMax;
  boolean over;
  boolean locked;

  HScrollbar(float xp, float yp, float sw, float sh) {
    x = xp;
    y = yp;
    swidth = sw;
    sheight = sh;
    spos = x + swidth / 2 - sheight / 2;
    sposMin = x;
    sposMax = x + swidth - sheight;
  }

  void update() {
    if (over()) {
      over = true;
    } else {
      over = false;
    }
    if (mousePressed && over) {
      locked = true;
    }
    if (!mousePressed) {
      locked = false;
    }
    if (locked) {
      spos = constrain(mouseX - sheight / 2, sposMin, sposMax);
    }
  }

  float constrain(float val, float minv, float maxv) {
    return min(max(val, minv), maxv);
  }

  boolean over() {
    return mouseX > x && mouseX < x + swidth &&
           mouseY > y && mouseY < y + sheight;
  }

  void display() {
    fill(204);
    rect(x, y, swidth, sheight);
    if (over || locked) {
      fill(0, 0, 0);
    } else {
      fill(102, 102, 102);
    }
    rect(spos, y, sheight, sheight);
  }

  float getPos() {
    return map(spos, sposMin, sposMax, 0, 255);
  }
}



//_____________________________________BUTTON CLASS_______________________________________
class ButtonDisplay {
  float x, y;
  float width, height;
  color defaultColor, hoverColor, pressColor;
  String label;
  boolean isPressed = false;
  
  ButtonDisplay(float x, float y, float width, float height, color defaultColor, color hoverColor, color pressColor, String label) {
    this.x = x;
    this.y = y;
    this.width = width;
    this.height = height;
    this.defaultColor = defaultColor;
    this.hoverColor = hoverColor;
    this.pressColor = pressColor;
    this.label = label;
  }
  
  void display() {
    color buttonColor;
    if (isPressed) {
      buttonColor = pressColor;
    } else if (overButton()) {
      buttonColor = hoverColor;
    } else {
      buttonColor = defaultColor;
    }
    
    fill(buttonColor);
    rect(x, y, width, height);
    
    textAlign(CENTER, CENTER);
    fill(0);
    textSize(16);
    text(label, x + width / 2, y + height / 2);
  }
  
  boolean overButton() {
    return mouseX >= x && mouseX <= x + width &&
           mouseY >= y && mouseY <= y + height;
  }
  
  boolean isClicked() {
    if (overButton() && mousePressed && !isPressed) {
      isPressed = true;
      return true;
    } else if (!mousePressed) {
      isPressed = false;
    }
    return false;
  }
}


//_____________________________DROP DOWN MENU________________________________
