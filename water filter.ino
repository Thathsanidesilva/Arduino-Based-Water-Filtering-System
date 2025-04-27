const int floatPin = 2;       // Float sensor input
const int motorPin = 3;       // Motor control output (via relay/MOSFET)
const int pHSensorPin = A0;   // pH sensor analog input

void setup() {
  pinMode(floatPin, INPUT_PULLUP);  // Float sensor uses internal pull-up
  pinMode(motorPin, OUTPUT);        // Motor output
  Serial.begin(9600);               // Start serial monitor
}

void loop() {
  // --- Float Sensor Logic ---
  int sensorState = digitalRead(floatPin);
  bool motorOn = false;

  if (sensorState == LOW) {
    digitalWrite(motorPin, HIGH);  // Turn ON motor
    motorOn = true;
  } else {
    digitalWrite(motorPin, LOW);   // Turn OFF motor
  }

  // --- pH Sensor Reading ---
  int sensorValue = analogRead(pHSensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert to voltage
  float pH = 3.5 * voltage;                      // Estimate pH

  // --- Serial Output ---
  Serial.print("pH: ");
  Serial.print(pH, 2);
  Serial.print(" | Motor: ");
  Serial.println(motorOn ? "ON" : "OFF");

  delay(1000);  // Delay for 1 second
}
