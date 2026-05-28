#include <Servo.h> 

// --- Constants ---
#define EN_A 6
#define IN1 5
#define IN2 4
#define IR_1 3
#define IR_2 2
#define SERVO_PIN 7

Servo myservo; 

// --- Flags ---
// volatile ensures the loop reads the updated value from the ISR
volatile bool piece_at_sensor_2 = false;
volatile bool piece_at_sensor_1 = false;

// --- ISRs ---
void ISR_IR_1(){
  if (digitalRead(IR_1) == LOW) {
    piece_at_sensor_1 = true;
  }
}

void ISR_IR_2(){
  // We only care when the piece ARRIVES (LOW)
  if (digitalRead(IR_2) == LOW) {
    piece_at_sensor_2 = true; 
    // Do NOT stop motor or read serial here. Just set the flag.
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  myservo.attach(SERVO_PIN);
  myservo.write(152);
  
  // Use FALLING to detect only when the object covers the sensor
  attachInterrupt(digitalPinToInterrupt(IR_1), ISR_IR_1, FALLING);
  attachInterrupt(digitalPinToInterrupt(IR_2), ISR_IR_2, FALLING);
}

void loop() {
  
  // 1. Start Belt Logic
  if(piece_at_sensor_1){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN_A, 200);
    piece_at_sensor_1 = false; 
  } 
  
  // 2. Sorting Logic
  if (piece_at_sensor_2){
    
    // A. Stop motor
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN_A, 0);
    delay(500); // Wait a tiny bit for the camera to catch up

    // B. THE FIX: Clear the buffer to get the LATEST command
    char command = '0'; // Default to 0
    
    // While there is data in the buffer, keep reading to empty it.
    // The last byte read will be the most recent command from Python.
    while (Serial.available() > 0) {
      command = Serial.read();
      delay(2); // Small delay to catch incoming stream
    }

    // C. Check the command (Using CHAR '1', not INT 1)
    if (command == '1') {
       myservo.write(110); // Red condition
    } else {
       myservo.write(180); // Else condition
    }
    
    delay(1000); 
    
    // D. Eject
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN_A, 200);
    delay(2000); 

    // E. Reset
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN_A, 0);
    myservo.write(152); 
    piece_at_sensor_2 = false; 
  }
}