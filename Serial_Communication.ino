void setup() {
  // put your setup code here, to run once:
  pinMode(D1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char command;

  //Serail == PC
  if ( Serial.available() > 0) {
    /*if data exist*/
    command = Serial.read();
    if (command =='\n');
    else if ( command == 'a')
      digitalWrite(D1, HIGH);
    else
      digitalWrite(D1, LOW);
  }
}
