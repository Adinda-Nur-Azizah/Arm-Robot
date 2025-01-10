#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial SerialBT; // Inisialisasi Bluetooth
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int pos1 = 90;  // Posisi awal untuk servo 1
int pos2 = 0;  // Posisi awal untuk servo 2
int pos3 = 60;  // Posisi awal untuk servo 3
int pos4 = 90;  // Posisi awal untuk servo 4

// Definisikan pin servo
const int servoPin1 = 13;
const int servoPin2 = 12;
const int servoPin3 = 14;
const int servoPin4 = 27;

void setup() {
  Serial.begin(115200);    // Serial Monitor untuk debugging
  SerialBT.begin("ESP32_Arm_Controller"); // Nama perangkat Bluetooth
  Serial.println("Bluetooth started! Connect to ESP32_Arm_Controller");

  // Attaching servos
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);

  // Set posisi awal servo
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    switch (command) {
      case 'A': // Servo 1 +
        pos1 = constrain(pos1 + 10, 0, 180);
        servo1.write(pos1);
        SerialBT.print("Servo 1: "); SerialBT.println(pos1);
        break;

      case 'B': // Servo 1 -
        pos1 = constrain(pos1 - 10, 0, 180);
        servo1.write(pos1);
        SerialBT.print("Servo 1: "); SerialBT.println(pos1);
        break;

      case 'C': // Servo 2 +
        pos2 = constrain(pos2 + 10, 0, 180);
        servo2.write(pos2);
        SerialBT.print("Servo 2: "); SerialBT.println(pos2);
        break;

      case 'D': // Servo 2 -
        pos2 = constrain(pos2 - 10, 0, 180);
        servo2.write(pos2);
        SerialBT.print("Servo 2: "); SerialBT.println(pos2);
        break;

      case 'E': // Servo 3 +
        pos3 = constrain(pos3 + 10, 0, 180);
        servo3.write(pos3);
        SerialBT.print("Servo 3: "); SerialBT.println(pos3);
        break;

      case 'F': // Servo 3 -
        pos3 = constrain(pos3 - 10, 0, 180);
        servo3.write(pos3);
        SerialBT.print("Servo 3: "); SerialBT.println(pos3);
        break;

      case 'G': // Servo 4 +
        pos4 = constrain(pos4 + 10, 0, 180);
        servo4.write(pos4);
        SerialBT.print("Servo 4: "); SerialBT.println(pos4);
        break;

      case 'H': // Servo 4 -
        pos4 = constrain(pos4 - 10, 0, 180);
        servo4.write(pos4);
        SerialBT.print("Servo 4: "); SerialBT.println(pos4);
        break;

      default:
        SerialBT.println("Invalid Command");
        break;
    }
  }
}
