
#include <Wire.h>

/*======================================*/
/* SETUP PARAMETERS                 */
/*======================================*/
void setup() {
  Wire.begin(85);                     // join I2C bus with address 0x55
  Wire.onReceive(receiveEvent);       // register event
  Serial.begin(9600);                 // start serial for output
}

void loop() {
  // put your main code here, to run repeatedly:

}

/*======================================*/
/* Receive Interrupt          */
/*======================================*/
void receiveEvent(int howMany) {
  uint8_t pressure;

  /* loop through all but the last */
  while (Wire.available())                // Remove "while" - single value at a time?
  {    
    pressure = Wire.read();               // Get continuous pressure values
    /* ??ZEROES INBETWEEN?? */
    if(pressure != 0){
      Serial.println(pressure);//, HEX);        // print received value to serial
    }
  }
}
