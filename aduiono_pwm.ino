void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Adc = analogRead(A0);
  Serial.println(Adc);
  analogWrite(D3, Adc);
}
