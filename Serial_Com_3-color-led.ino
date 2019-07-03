void setup() {
  // put your setup code here, to run once:
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char input;

  if (Serial.available() > 0) {
    input = Serial.read();
    if (input == '\n');
    else {
      switch(input) {
      case 'a':
        digitalWrite(D0, HIGH);
        digitalWrite(D1, LOW);
        digitalWrite(D2, LOW);
        break;
      case 'b':
        digitalWrite(D0, LOW);
        digitalWrite(D1, HIGH);
        digitalWrite(D2, LOW);
        break;
      case 'c':
        digitalWrite(D0, LOW);
        digitalWrite(D1, LOW);
        digitalWrite(D2, HIGH);
        break;
      case 'd':
        digitalWrite(D0, LOW);
        digitalWrite(D1, LOW);
        digitalWrite(D2, LOW);
        break;
      }
   }
  }
}
