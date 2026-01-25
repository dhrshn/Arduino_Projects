#include <LiquidCrystal.h>

// LCD pin setup
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Joystick pins
#define joyX A0
#define joyY A1
#define joyBtn 8

int playerX = 0;
int playerY = 0;

int targetX = 10;
int targetY = 1;

int score = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(joyBtn, INPUT_PULLUP);
  randomSeed(analogRead(A5));

  lcd.clear();
  lcd.print("Simple LCD Game");
  delay(1500);
}

void loop() {
  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);

// LEFT
if (xVal < 400 && playerX > 0) {
  playerX--;
}

// RIGHT
if (xVal > 600 && playerX < 15) {
  playerX++;
}

// UP
if (yVal < 400 && playerY > 0) {
  playerY--;
}

// DOWN
if (yVal > 600 && playerY < 1) {
  playerY++;
}


  // Movement thresholds
  //if (xVal < 400 && playerX > 0) playerX--;
  //if (xVal > 600 && playerX < 15) playerX++;
  //if (yVal < 400 && playerY < 1) playerY++;
  //if (yVal > 600 && playerY > 0) playerY--;

  // Collision detection
  if (playerX == targetX && playerY == targetY) {
    score++;
    targetX = random(0, 16);
    targetY = random(0, 2);
  }

  drawGame();
  delay(200);
}

void drawGame() {
  lcd.clear();

  // Draw player
  lcd.setCursor(playerX, playerY);
  lcd.print(">");

  // Draw target
  lcd.setCursor(targetX, targetY);
  lcd.print("*");

  // Draw score
  lcd.setCursor(12, 0);
  lcd.print(score);
}

