const int sensor=A5; // Assigning analog pin A5 to variable 'sensor'

float tempc; //variable to store temperature in degree Celsius

float tempf; //variable to store temperature in Fahreinheit

float vout; //temporary variable to hold sensor reading

void setup() {

pinMode(sensor,INPUT); // Configuring sensor pin as input
pinMode(2, OUTPUT);

Serial.begin(9600);

}

void loop() {

vout=analogRead(sensor); //Reading the value from sensor

vout=(vout*500)/1023;

tempc=vout; // Storing value in Degree Celsius

tempf=(vout*1.8)+32; // Converting to Fahrenheit

Serial.print("in DegreeC=");

Serial.print("\t");

Serial.print(tempc);

Serial.print(" ");

Serial.print("in Fahrenheit=");

Serial.print("\t");

Serial.print(tempf);

Serial.println();


if (tempc>20){
  digitalWrite(2, LOW);
  delay(1800000);
  digitalWrite(2, HIGH);
  delay(900000);
}
 delay(500);//Delay of 1 second for ease of viewing 
}
