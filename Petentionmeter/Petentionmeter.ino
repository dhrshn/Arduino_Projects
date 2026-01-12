int ledPin = 11;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  float writeValue = (sensorValue * 225.0) / 1023.0;
  Serial.print("ADC reading: ");
  Serial.print(sensorValue);
  Serial.print("Analog Voltage: ");
  Serial.println(voltage);
  
  analogWrite(ledPin, writeValue);
  
  delay(30);
  

}

//void fadeLED(int ledPin, int sensorValue) {
  //for (int sensorValue = 0; sensorValue <= 1023; cnt += 10) {
    //analogWrite(ledPin, sensorValue);
    //delay(30);
  //}

  //for (int sensorValue = 1023; sensorValue >= 0; cnt -= 10) {
    //analogWrite(ledPin, sensorValue);
    //delay(30);
  //}
//}
