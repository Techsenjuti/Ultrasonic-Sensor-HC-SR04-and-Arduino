/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*/
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 12; 
const int buzzer = 8; //buzzer to arduino pin
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  pinMode(ledPin, OUTPUT); // Set pin 13 as output
  pinMode(buzzer, OUTPUT);//buzzer pin setup
  
}
 void loop1() {
  digitalWrite(ledPin, HIGH);   // Turn LED on
  delay(100);                  // Wait for 1 second
  digitalWrite(ledPin, LOW);    // Turn LED off
  delay(100);
 }
 void loop2(){
 
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(200);        // 
  noTone(buzzer);     // Stop sound...
  delay(100);        // ...for 1sec
  
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if(distance<=5){
    loop1();
  //  loop2();
}
  Serial.print("Distance in cms: ");
  Serial.println(distance);
  delay(100);
}
