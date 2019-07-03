int trig = D1;//Triiger Pin
int echo = D2;//Echo Pin
int redLed = D3;//LED

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//Serial Init
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int distance = pulseIn(echo, HIGH) * 17 / 1000;
  Serial.print(distance * 10);
  Serial.println("cm");
  int Time = map(distance, 0, 400, 0, 4000);//0 ~ 400 -> 0 ~ 4000
  
  digitalWrite(redLed, HIGH);
  delay(Time);
  digitalWrite(redLed, LOW);
  delay(Time);
}
