/*-----------------------------------*/
void read_pot() {
  potReading = analogRead(POTPIN);
}
/*-----------------------------------*/
void pot_processing() {
  potReading = analogRead(POTPIN);
  potMapped = map(potReading, 0, 1023, 0, 100);
  potFiltered = int(floor(potFiltered) * prevGain + potMapped * currentGain);
  potFiltered += bias;
  }
/*------------------------------------*/
