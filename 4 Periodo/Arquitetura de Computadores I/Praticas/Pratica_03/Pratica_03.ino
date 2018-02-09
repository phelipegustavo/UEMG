int verde1 = 1;
int amarelo1 = 2;
int vermelho1 = 3;
int verde2 = 4;
int amarelo2 = 5;
int vermelho2 = 6;
int verde3 = 7;
int amarelo3 = 8;
int vermelho3 = 9;


void setup(){
  
pinMode(verde1, OUTPUT);
pinMode(amarelo1, OUTPUT);
pinMode(vermelho1, OUTPUT);

pinMode(verde2, OUTPUT);
pinMode(amarelo2, OUTPUT);
pinMode(vermelho2, OUTPUT);

pinMode(verde3, OUTPUT);
pinMode(amarelo3, OUTPUT);
pinMode(vermelho3, OUTPUT);
  
}


void loop(){
  digitalWrite(vermelho1, HIGH);
  digitalWrite(vermelho2, HIGH);
  digitalWrite(vermelho3, HIGH);
    
  digitalWrite(vermelho1, LOW);
  digitalWrite(verde1, HIGH);
  delay(5000);
  digitalWrite(verde1, LOW);
  digitalWrite(amarelo1, HIGH);
  delay(1500);  
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, HIGH);
  delay(5000);  
  
  digitalWrite(vermelho2, LOW);
  digitalWrite(verde2, HIGH);
  delay(5000);
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, HIGH);
  delay(1500);  
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, HIGH);
  delay(5000);  

  digitalWrite(vermelho3, LOW);
  digitalWrite(verde3, HIGH);
  delay(5000);
  digitalWrite(verde3, LOW);
  digitalWrite(amarelo3, HIGH);
  delay(1500);  
  digitalWrite(amarelo3, LOW);
  digitalWrite(vermelho3, HIGH);
  delay(5000);  
 
}
