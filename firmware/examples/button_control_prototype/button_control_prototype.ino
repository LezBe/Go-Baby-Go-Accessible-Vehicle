const int buttonPinGo = 3;     // Pin for the "Go" button 
const int buttonPinStop = 6;   // Pin for the "Stop" button
const int outputPin = 11;  // Pin for the "Stop" LED
bool buttonStateGo = false;    // Track the "Go" button press state
bool buttonStateStop = false;  // Track the "Stop" button press state
int count = 0;
void setup() {
  // Set up LED pins as outputs and button pins as inputs
  pinMode(buttonPinGo, INPUT); //  Pin [3] tracks to this variable (from go button)
  pinMode(outputPin, OUTPUT); //pin [11] tracks to this variable (to motor)
  pinMode(buttonPinStop, INPUT); //Pin [6] tracks to this variable (from stop button)
  Serial.begin(9600); //sets IDE output (DO NOT KEEP IN FINAL CODE; FOR DEBUGGING ONLY)
}
void loop() {
  Serial.println(count); //prints IDE output (DO NOT KEEP IN FINAL CODE; FOR DEBUGGING ONLY)
  delay(10); //delays loop (cooldown)(DETERMINE PRECISE VALUE LATER)
  // Handle "Go" button
  if (digitalRead(buttonPinGo) == LOW) {
    count = count+20;
    if(count>1000){count = 0;}
  else{}
  digitalWrite(buttonPinGo, HIGH); // Buttons starts off
  }
}
