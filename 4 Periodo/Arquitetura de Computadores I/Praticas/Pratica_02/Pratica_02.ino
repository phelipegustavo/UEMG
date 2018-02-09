int leds[5];
#define btn1 12
#define btn2 11
#define btn3 10

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);

  for (int i=3; i<8; i++){
    leds[i] = i;
  	pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  Serial.begin(9600);
}

void acendeEsqDir(){
  for (int i=3; i<8; i++){
  	digitalWrite(leds[i], HIGH);
  	delay(1000);
  }
}

void acendeDirEsq(){
	for (int i=7; i>=3; i--){
  	digitalWrite(leds[i], HIGH);
  	delay(1000);
  }
}

void acendeMeioExt(){
	digitalWrite(5, HIGH);
  	delay(1000);
  	digitalWrite(4, HIGH);
  	digitalWrite(6, HIGH);
  	delay(1000);
  	digitalWrite(3, HIGH);
  	digitalWrite(7, HIGH);
  	delay(1000);
}

void apagaLeds(){
  for (int i=3; i<8; i++){
  	digitalWrite(leds[i], LOW);
  }
}
void loop() {
   
  if (!digitalRead(btn1)){
    //Serial.println("botao 2 pressionado: leds Esquerda -> Direita");
   	acendeEsqDir();
  }else{
    apagaLeds();
  }
  if (!digitalRead(btn2)){
  	//Serial.println("botao 2 pressionado: leds Direita -> Esquerda");
    acendeDirEsq();
  }else{
    apagaLeds();
  }
  if (!digitalRead(btn3)){
  	//Serial.println("botao 2 pressionado: leds Direita -> Esquerda");
    acendeMeioExt();
  }else{
    apagaLeds();
  }
}

