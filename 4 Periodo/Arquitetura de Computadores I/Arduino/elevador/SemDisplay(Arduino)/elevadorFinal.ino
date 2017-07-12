int pino = 8;   //Pino ativo
char tecla;     //Entrada de dados
int atual=1;    //Andar Atual
int irAndar=0;  //Andar Desejado
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);   //Laranja
  pinMode(9, OUTPUT);   //Marrom
  pinMode(10, OUTPUT);  //Marrom e Branco
  pinMode(11, OUTPUT);  //Laranja e Branco
  Serial.println("Informe o andar desejado: ");
}

/*Descer Elevador*/
void descer(int passos){
  for (int i = 0; i < passos; i++) {
      pino++;
      if (pino == 12) {
        pino = 8;
      }
      digitalWrite(pino, HIGH);
      delay(7); //Espera 7ms 
      digitalWrite(pino, LOW);
  }
}

/*Subir Elevador*/
void subir(int passos){
  for (int i = 0; i < passos; i++) {
      pino--;
      if (pino == 7) {
        pino = 11;
      }
      digitalWrite(pino, HIGH);
      delay(7); //Espera 7ms
      digitalWrite(pino, LOW);
    }
}

void loop() {
  tecla = Serial.read();                //Recebe andar digitado pelo usuario
  irAndar = atoi(&tecla);               //Converte o andar para inteiro
  if(irAndar!=0 && irAndar<=5){         //0 como flag
    if(irAndar>atual){                  //Andar desejado esta acima do atual
      int passos=(irAndar-atual)*370;   
      atual=irAndar;
      subir(passos);
      irAndar=0;
      delay(500);
    }else{                              //Andar desejado esta no mesmo nivel ou abaixo do atual
      int passos=(atual-irAndar)*370;   
      atual=irAndar;
      descer(passos);
      irAndar=0;
      delay(500);
    }
  }
}
