#include<Wire.h>
long accelX,accelY, accelZ;
float gForceX, gForceY, gForceZ;


long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;

void setup(){
Serial.begin(9600);
Wire.begin();
setupMPU();
  
}


void setupMPU(){
  Wire.beginTransmission(0b1101000) ;// address of I2C
  Wire.write(0x6B);//accessing power  management
  Wire.write(0b00000000);//setting sleep register to 0
  Wire.endTransmission();

  Wire.beginTransmission(0b1101000) ;// address of I2C
  Wire.write(0x1B);//accessing gyro sensitivity register
  Wire.write(0x00000000);//setting +/-250deg cobnfig
  Wire.endTransmission();

  Wire.beginTransmission(0b1101000) ;// address of I2C
  Wire.write(0x1C);//accessing accel sensitivity register
  Wire.write(0b00000000);//setting +/-2g cobnfig
  Wire.endTransmission();

  
}

void recordAccelRegisters() {
  Wire.beginTransmission(0b1101000) ;// address of I2C
  Wire.write(0x3B);//accessing accel reading register
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //req accel register 
  while(Wire.available() < 6);
  accelX = Wire.read()<<8|Wire.read(); //store first 2 bytes of x direction
  accelY = Wire.read()<<8|Wire.read(); //store 2 bytes of y direction
  accelZ = Wire.read()<<8|Wire.read(); // store 2 bytes of z direction
  processAccelData();
}


void processAccelData(){

  gForceX = accelX  / 16384.0;
  gForceY = accelY  / 16384.0;
  gForceZ = accelZ  / 16384.0;
}

void recordGyroRegisters() {
  Wire.beginTransmission(0b1101000) ;// address of I2C
  Wire.write(0x43);//accessing accel reading register
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //req accel register 
  while(Wire.available() < 6);
  gyroX = Wire.read()<<8|Wire.read(); //store first 2 bytes of x direction
  gyroY = Wire.read()<<8|Wire.read(); //store 2 bytes of y direction
  gyroZ = Wire.read()<<8|Wire.read(); // store 2 bytes of z direction
  processGyroData();
}


void processGyroData(){
  rotX  =  gyroX /131.0;
  rotY  =  gyroY /131.0;
  rotZ  =  gyroZ /131.0;
}


void  printData(){
  Serial.print(" Gyro (deg)");
  Serial.print(" X=");
  Serial.print(rotX);
  Serial.print(" Y=");
  Serial.print(rotY);
  Serial.print(" Z=");
  Serial.print(rotZ);
  
  Serial.print(" Accel (g)");
  Serial.print(" X=");
  Serial.print(gForceX);
  Serial.print(" Y=");
  Serial.print(gForceY);
  Serial.print(" Z=");
  Serial.println(gForceZ);

  
}



void loop(){
  recordAccelRegisters();
  recordGyroRegisters();
  printData();
  delay(100);
  
}
