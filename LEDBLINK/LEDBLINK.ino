void setup(){
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop(){
  //RED
  digitalWrite(12,HIGH);
  delay(200);
  digitalWrite(12,LOW);
  delay(200);

  //BLUE
  digitalWrite(8,HIGH);
  delay(200);
  digitalWrite(8,LOW);
  delay(200);

}

