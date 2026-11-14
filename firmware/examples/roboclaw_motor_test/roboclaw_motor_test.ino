#include <RoboClaw.h>
// Define Serial Communication (Change if using different Serial)
#define roboclawSerial Serial1  // Using hardware Serial1 (Tx1/Rx1)
// Create RoboClaw object (TX, RX, timeout in ms)
RoboClaw roboclaw(&roboclawSerial, 10000);
// RoboClaw Address (default is 0x80)
#define ROBOCLAW_ADDRESS 0x80
void setup() {
    // Start Serial Communication
    Serial.begin(115200);  // For debugging
    roboclawSerial.begin(38400);  // Match RoboClaw baud rate
    // Verify connection
    Serial.println("Initializing RoboClaw...");
    delay(1000);
    // Move both motors forward at 50% speed continuously
    roboclaw.ForwardM1(ROBOCLAW_ADDRESS, 54); // M1 forward at 50% speed (max is 127)
    roboclaw.ForwardM2(ROBOCLAW_ADDRESS, 54); // M2 forward at 50% speed
    Serial.println("Motors Running...");
}
void loop() {
    // Nothing needed in loop, motors will keep running
}
