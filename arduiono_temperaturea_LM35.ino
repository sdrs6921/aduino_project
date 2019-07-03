void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Adc = analogRead(A0);
  float mV = (Adc/1023.0) * 5000; //3.3v = 3300mv
  float Temp = mV/10;
  Serial.print("Temperature : ");
  Serial.print(Temp);
  Serial.println("c");
  delay(500);
}
