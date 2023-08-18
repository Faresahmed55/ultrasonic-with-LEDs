const int trigPin = 10;  
const int echoPin = 9;  

const int ledPin1 = 5;  
const int ledPin2 = 6;  
const int ledPin3 = 7;  
const int ledPin4 = 8;  

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  
  
  if (distance <= 100) {
    digitalWrite(ledPin1, HIGH);
  } else if (distance > 100 && distance <= 200) {
    digitalWrite(ledPin2, HIGH);
  } else if (distance > 200 && distance <= 300) {
    digitalWrite(ledPin3, HIGH);
  } else if (distance > 300) {
    digitalWrite(ledPin4, HIGH);
  }
  
  delay(500); 
}
