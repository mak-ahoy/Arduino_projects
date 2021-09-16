#define trig 10
#define echo 13

float duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

duration= pulseIn(echo, HIGH);


distance= (duration/2)*;


Serial.print("Distance== ");

if (distance<=2 || distance>=400){
  Serial.println("OUT OF RANGE");
}
else {
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}

delay(500);


}
