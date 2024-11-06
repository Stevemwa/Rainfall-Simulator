float error = 0;
float errorMIN = 3;

void process_desired_flow(int desiredFlow) {
  read_flowRate();
  error = desiredFlow - litre_hr;
  int errorSign = (error >= 0) ? 1 : 0 ;
  int errorMag = (error * error) / 2;
  if (errorMag < 3) {
    stop_valve();
  } else {
    if (errorSign) {
      open_valve();
    } else {
      close_valve();
    }
  }

}
