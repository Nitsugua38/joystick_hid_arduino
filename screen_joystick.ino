const int pinX = A0;
const int pinY = A1;
const int pinBouton = 9;



void setup() {  
  pinMode(pinBouton , INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
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





