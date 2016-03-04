/* ir-projector-screen-controller
 *  https://github.com/dbruning/ir-projector-screen-controller
 *  based very heavily on IRrecvDump example from https://github.com/z3t0/Arduino-IRremote, and obviously using that library.
 */

#include <IRremote.h>

/* 
*  Default is Arduino pin D11. 
*  You can change this to another available Arduino Pin.
*  Your IR receiver should be connected to the pin defined here
*/
int RECV_PIN = 11; 

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // Serial.println(results.value, HEX);
    // dump(&results);
    Serial.println(results.value, DEC);
    // Serial.println(results.value, HEX);
    // These codes are what seems to work from Simple Remote's database of Benq projectors using IR Group 1. 
    // Seems pretty reliable, more so that the actual Panasonic codes anyway.
    // "Right" pad is 930455363, could use that to fine-tune or manual control down-slightly
    // "Left" pad is 2524775321, could use that to fine-tune or manual control down-slightly
    
    if(results.value == 1590215105) {
      Serial.println("Projector power on!");
    } else  if(results.value == 2311607719) {
      Serial.println("Projector power off!");
    } else {
      Serial.println("Dunno brah!");
    }
    irrecv.resume(); // Receive the next value
  }
}
