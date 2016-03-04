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
    Serial.println(results.value, HEX);
    if(results.value == 1505153145) {
      Serial.println("Projector power on!");
    } else  if(results.value == 3766776354) {
      Serial.println("Projector power off!");
    } else {
      Serial.println("Dunno brah!");
    }
    irrecv.resume(); // Receive the next value
  }
}
