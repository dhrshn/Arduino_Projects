// This Code is for multiple light led control

int ledPinBlue = 5;
int ledPinRed = 6;
int ledPinGreen = 9;
int ledPinOrange = 10;
int ledPinYellow = 11;

void setup(){
  
}

void loop(){
  fadeLED(ledPinBlue);
  fadeLED(ledPinRed);
  fadeLED(ledPinGreen);
  fadeLED(ledPinOrange);
  fadeLED(ledPinYellow);
}

void fadeLED(int ledPin) {
  for (int fadeValue = 0; fadeValue <= 225; fadeValue += 10) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }

  for (int fadeValue = 225; fadeValue >= 0; fadeValue -= 10) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
}

