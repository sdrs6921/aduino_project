int trig = D1;
int echo = D2;
int greenLed = D3;
int redLed = D4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int dist = pulseIn(echo, HIGH) * 17 / 1000;
  Serial.print(dist);
  Serial.println("cm");
  if (dist < 150) {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  }
  else {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  }
  delay(100);
}
