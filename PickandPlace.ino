#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(0, 1);
//Servo instances
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int Incoming_value;        // Input value from mobile app
int savedPositions[50][6]; // can save upto 50 steps , each with 6 servo angles
int savedCount = 0;        // Number of saved positions
int currentStep = 0;       // for playback
int s1, s2, s3, s4, s5, s6;
int Speed = 10000;
bool isrunning = false;
// bool ispaused = false;

void setup() {
  Serial.begin(9600);
  // Attach servo motors to their respective output pins
  servo1.attach(7);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);
  // Initial position of the robot
  s1 = 90; servo1.write(s1);
  s2 = 90; servo2.write(s2);
  s3 = 96; servo3.write(s3);
  s4 = 150; servo4.write(s4);
  s5 = 50; servo5.write(s5);
  s6 = 90; servo6.write(s6);
  
  Bluetooth.begin(115200); // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(1);
  delay(20);
  // put your setup code here, to run once:
}
void loop() {
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print("\n");
  }
  if (Incoming_value == 0 & s1 < 180)  { s1++; servo1.write(s1); delay(50); Serial.println(s1); }
  if (Incoming_value == 1 & s1 > 0)    { s1--; servo1.write(s1); delay(50); Serial.println(s1); }
  if (Incoming_value == 2 & s2 < 180)  { s2++; servo2.write(s2); delay(50); Serial.println(s2); }
  if (Incoming_value == 3 & s2 > 0)    { s2--; servo2.write(s2); delay(50); Serial.println(s2); }
  if (Incoming_value == 4 & s3 < 180)  { s3++; servo3.write(s3); delay(50); Serial.println(s3); }
  if (Incoming_value == 5 & s3 > 0)    { s3--; servo3.write(s3); delay(50); Serial.println(s3); }
  if (Incoming_value == 6 & s4 < 180)  { s4++; servo4.write(s4); delay(50); Serial.println(s4); }
  if (Incoming_value == 7 & s4 > 0)    { s4--; servo4.write(s4); delay(50); Serial.println(s4); }
  if (Incoming_value == 8 & s5 < 180)  { s5++; servo5.write(s5); delay(50); Serial.println(s5); }
  if (Incoming_value == 9 & s5 > 0)    { s5--; servo5.write(s5); delay(50); Serial.println(s5); }
  if (Incoming_value == 10 & s6 < 180) { s6++; servo6.write(s6); delay(50); Serial.println(s6); }
  if (Incoming_value == 11 & s6 > 0)   { s6--; servo6.write(s6); delay(50); Serial.println(s6); }

  if (Incoming_value == 15) { digitalWrite(3, LOW); }
  
  // Speed Control
  if (Incoming_value == 20 & Speed <= 13000) { Speed = Speed + 1000; delay(1000); Serial.println(Speed); delay(500); }
  if (Incoming_value == 21 & Speed >= 1000) { Speed = Speed - 1000; delay(1000); Serial.println(Speed); delay(500); }
  
  //when "SAVE" button is pressed
  if (Incoming_value == 25) {   
    if (savedCount < 50) {
      savedPositions[savedCount][0] = s1;
      savedPositions[savedCount][1] = s2;
      savedPositions[savedCount][2] = s3;
      savedPositions[savedCount][3] = s4;
      savedPositions[savedCount][4] = s5;
      savedPositions[savedCount][5] = s6;
      savedCount++;
      Serial.print("Saved step "); 
      Serial.println(savedCount);
    } else { Serial.println("Memory full!"); }
    delay(300); // debounce
    }
  
    // RUN button pressed
    if (Incoming_value == 26) {
      if (savedCount > 0) {
        Serial.println("Running saved sequence...");
        for (int step = 0; step < savedCount; step++) {
          servo1.write(savedPositions[step][0]);
          servo2.write(savedPositions[step][1]);
          servo3.write(savedPositions[step][2]);
          servo4.write(savedPositions[step][3]);
          servo5.write(savedPositions[step][4]);
          servo6.write(savedPositions[step][5]);
          delay(1000); // wait between steps
        }
        Serial.println("Sequence complete.");
      } else {
        Serial.println("No positions saved!");
      }
      delay(300); // debounce
    }
}



