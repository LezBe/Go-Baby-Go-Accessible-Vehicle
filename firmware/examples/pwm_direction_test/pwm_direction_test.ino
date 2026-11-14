// Pin definitions
int dirPin1 = 2;  // DIR1 pin for Motor 1
int dirPin2 = 3;  // DIR2 pin for Motor 2
int pwmPin1 = 9;  // PWM pin for Motor 1
int pwmPin2 = 10; // PWM pin for Motor 2
int toggleSwitchPin = 4;  // Pin connected to the DPDT toggle switch
void setup() {
  // Set pin modes
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(pwmPin1, OUTPUT);
  pinMode(pwmPin2, OUTPUT);
  pinMode(toggleSwitchPin, INPUT);  // Read DPDT switch state
  
  // Set initial motor speed to 0
  analogWrite(pwmPin1, 0);
  analogWrite(pwmPin2, 0);
}
void loop() {
  int toggleState = digitalRead(toggleSwitchPin);  // Read switch state
  
  if (toggleState == HIGH) {  // If switch is in one position (forward)
    digitalWrite(dirPin1, HIGH);  // Set direction for Motor 1 (forward)
    digitalWrite(dirPin2, HIGH);  // Set direction for Motor 2 (forward)
  } else {  // If switch is in other position (reverse)
    digitalWrite(dirPin1, LOW);   // Set direction for Motor 1 (reverse)
    digitalWrite(dirPin2, LOW);   // Set direction for Motor 2 (reverse)
  }
  
  // Adjust speed as needed (example: full speed)
  analogWrite(pwmPin1, 255);  // Max speed for Motor 1
  analogWrite(pwmPin2, 255);  // Max speed for Motor 2
}
