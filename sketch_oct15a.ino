const int trigPin = 13;
const int echoPin = 12;
const int LEDFar = 6;
const int LEDClose = 7;

long duration;
int distance;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //pinMode(LEDFar, OUTPUT);
  pinMode(LEDClose, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);                
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;
  if(distance < 10){
      digitalWrite(LEDClose, HIGH);
      digitalWrite(LEDFar, LOW);
  }
  else{
      digitalWrite(LEDClose, LOW);
      digitalWrite(LEDFar, HIGH);
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}
