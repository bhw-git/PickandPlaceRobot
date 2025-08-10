#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(0, 1);
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
int Incoming_value;
int servo1pos[10][6], servo2pos[10][6],servo3pos[10][6],servo4pos[10][6],servo5pos[10][6],servo6pos[10][6];
int index = 0;
int nosavedpos1 = 0;
int nosavedpos2 = 0;
int nosavedpos3 = 0;
int nosavedpos4 = 0;
int nosavedpos5 = 0;
int nosavedpos6 = 0;
int s1, s2, s3, s4, s5, s6;
int Speed = 10000;
bool isrunning = false;
bool ispaused = false;

void setup() {
  Serial.begin(9600);
  servo1.attach(7);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);
  s1 = 90;
  servo1.write(s1);
  s2 = 90;
  servo2.write(s2);
  s3 = 96;
  servo3.write(s3);
  s4 = 150;
  servo4.write(s4);
  s5 = 50;
  servo5.write(s5);
  s6 = 90;
  servo6.write(s6);
  Bluetooth.begin(115200); // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(1);
  delay(20);
  // put your setup code here, to run once:
}
void loop() {
  if (Serial.available() > 0)
  {
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print("\n");
}
  if (Incoming_value == 0) {
    if (s1 < 180) {
      s1 = s1 + 1;
      servo1.write(s1);
      delay(50);
      Serial.println(s1);
      //delayMicroseconds(((s1) * 11) + Speed);
    }
  }
  if (Incoming_value == 1) {
    if (s1 > 0) {
      s1 = s1 - 1;
      servo1.write(s1);
      delay(50);
      Serial.println(s1);
      //delayMicroseconds(((s1) * 11) + Speed);
    }
  }
  if (Incoming_value == 2) {
    if (s2 < 180) {
      s2 = s2 + 1;
      servo2.write(s2);
      delay(50);
      Serial.println(s2);
      //delayMicroseconds((s2 * 11) + Speed);
    }
  }
  if (Incoming_value == 3) {
    if (s2 > 0) {
      s2 = s2 - 1;
      servo2.write(s2);
      delay(50);
      Serial.println(s2);
      //delayMicroseconds((s2 * 11) + Speed);
    }
  }
  if (Incoming_value == 4) {
    if (s3 < 180) {
      s3 = s3 + 1;
      servo3.write(s3);
      delay(50);
      Serial.println(s3);
      //delayMicroseconds(((s3) * 11) + Speed);
    }
  }
  if (Incoming_value == 5) {
    if (s3 > 0) {
      s3 = s3 - 1;
      servo3.write(s3);
      delay(50);
      Serial.println(s3);
      //delayMicroseconds(((s3) * 11) + Speed);
    }
  }
  if (Incoming_value == 6) {
    if (s4 < 180) {
      s4 = s4 + 1;
      servo4.write(s4);
      delay(50);
      Serial.println(s4);
      //delayMicroseconds(((s4) * 11) + Speed);
    }
  }
  if (Incoming_value == 7) {
    if (s4 > 0) {
      s4 = s4 - 1;
      servo4.write(s4);
      delay(50);
      Serial.println(s4);
      //delayMicroseconds(((s4) * 11) + Speed);
    }
  }
  if (Incoming_value == 8) {
    if (s5 < 180) {
      s5 = s5 + 1;
      servo5.write(s5);
      delay(50);
      Serial.println(s5);
      //delayMicroseconds(((s5) * 11) + Speed);
    }
  }
  if (Incoming_value == 9) {
    if (s5 > 0) {
      s5 = s5 - 1;
      servo5.write(s5);
      delay(50);
      Serial.println(s5);
      //delayMicroseconds(((s5) * 11) + Speed);
    }
  }
  if (Incoming_value == 10) {
    if (s6 < 180) {
      s6 = s6 + 1;
      servo6.write(s6);
      delay(50);
      Serial.println(s6);
      //delayMicroseconds(((s6) * 11) + Speed);
    }
  }
  if (Incoming_value == 11) {
    if (s6 > 0) {
      s6 = s6 - 1;
      servo6.write(s6);
      delay(50);
      Serial.println(s6);
      //delayMicroseconds(((s6) * 11) + Speed);
    }
  }
  if (Incoming_value == 15) {
    digitalWrite(3, LOW);
  }
  if (Incoming_value == 20) {
    if (Speed <= 13000 ) {
      Speed = Speed + 1000;
      delay(1000);
      Serial.println(Speed);
      delay(500);
    }
  }
  if (Incoming_value == 21) {
    if (Speed >= 1000) {
      Speed = Speed - 1000;
      delay(1000);
      Serial.println(Speed);
      delay(500);
    }
  }
  if (Incoming_value == 25) {   //when "SAVE" button is pressed
    servo1pos[nosavedpos1][0] = servo1.read();
    servo2pos[nosavedpos1][1] = servo2.read();
    servo3pos[nosavedpos1][2] = servo3.read();
    servo4pos[nosavedpos1][3] = servo4.read();
    servo5pos[nosavedpos1][4] = servo5.read();
    servo6pos[nosavedpos1][5] = servo6.read();
  }


