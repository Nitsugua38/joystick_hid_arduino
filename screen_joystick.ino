#include <LiquidCrystal.h>

const int rs=2, en=3, d4=4, d5=5, d6=6, d7=7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



const int pinX = A0;
const int pinY = A1;
const int pinBouton = 9;



void setup() {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("hello, world !");
  
  pinMode(pinBouton , INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  lcd.display();


  int X = 0;
  int Y = 0;
  bool boutonValeur = false;
 
  X = analogRead(pinX);
  delay(100);
  Y = analogRead(pinY);
  boutonValeur = digitalRead(pinBouton);
 

  Serial.print(X);
  Serial.print(",");
  Serial.print(Y);
  Serial.print(",");
  Serial.print(boutonValeur);
  Serial.println();
  delay(200);
}





