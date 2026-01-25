const int LRpin = A0;
const int UDpin = A1;

int LR;
int UD;

int LR_neutral;
int UD_neutral;

const int ledRed = 5;
const int ledBlue = 6;
const int ledYellow = 10;
const int ledGreen = 11;

int R;
int B;
int Y;
int G;


void setup(){
  Serial.begin(9600);

  LR_neutral = analogRead(LRpin);
  UD_neutral = analogRead(UDpin);
}
 
void loop(){
  LR = analogRead(LRpin);
  UD = analogRead(UDpin);
  if(UD >= UD_neutral){
    R = 0;
    B = map(UD, UD_neutral, 1023,0,225);
  }
  else{
    B = 0;
    R = map(UD, UD_neutral, 0,0,225);
  }

  if(LR >= LR_neutral){
    G = 0;
    Y = map(LR, LR_neutral, 1023, 0, 225);
  }
  else{
    Y = 0;
    G = map(LR, LR_neutral, 0,0,225);
  }

  analogWrite(ledRed, R);
  analogWrite(ledBlue, B);
  analogWrite(ledYellow, Y);
  analogWrite(ledGreen, G);

  //float writeValue1 = (UD * 225.0) / 1023.0;
//float writeValue2 = (LR * 225.0) / 1023.0;

  //Serial.print("LR : ");
  //Serial.print(LR);
  //Serial.println("UD : ");
  //Serial.print(UD);
}
