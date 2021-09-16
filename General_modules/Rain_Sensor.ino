
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  if (sensorValue<=600)
  {
    digitalWrite(LED_BUILTIN, 5000);
    delay(1000);
    digitalWrite(LED_BUILTIN,0);
    delay(1000);
  }
  Serial.println(sensorValue);
  delay(100);
}
