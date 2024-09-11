#define rele1 8
#define rele2 7
#define rele3 5
#define rele4 4

#define ch1 3
#define ch2 9

#define led1 13
#define led2 11

#define sensor1 1
#define sensor2 2

#define limiar 40

void setup() {
  Serial.begin(9600);

  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);

  digitalWrite(rele1, LOW);
  digitalWrite(rele2, LOW);
  digitalWrite(rele3, LOW);
  digitalWrite(rele4, LOW);

}

void loop() {

  if (ler_sensores(1) == 0 && ler_sensores(2) == 0) {
    frente();
  }
  
  if (ler_sensores(1) == 1 && ler_sensores(2) == 0) {
    esquerda();
  }
  
  if (ler_sensores(1) == 0 && ler_sensores(2) == 1) {
    direita();
  }
  
  if (ler_sensores(1) == 1 && ler_sensores(2) == 1) {
    para();
  }


}

bool ler_sensores(int sensor) {
  int sensor_lido = 0;
  switch (sensor) {
    case 1:
      sensor_lido = analogRead(sensor1);
      break;

    case 2:
      sensor_lido = analogRead(sensor2);
      break;
  }

  if (sensor_lido > limiar) {
    return 1;
  } else {
    return 0;
  }
}

void gira_direita() {
  digitalWrite(rele1, HIGH);//MOTOR DA ESQUERDA IR PARA FRENTE
  digitalWrite(rele2, LOW);

  digitalWrite(rele3, HIGH);//MOTOR DIREITA IR PARA TRÁS
  digitalWrite(rele4, LOW);
}
void gira_esquerda() {
  digitalWrite(rele1, LOW);//MOTOR DA ESQUERDA IR PARA FRENTE
  digitalWrite(rele2, HIGH);

  digitalWrite(rele3, LOW);//MOTOR DIREITA IR PARA TRÁS
  digitalWrite(rele4, HIGH);
}


void direita() {
  digitalWrite(rele1, HIGH);//MOTOR DA ESQUERDA IR PARA FRENTE
  digitalWrite(rele2, LOW);

  digitalWrite(rele3, LOW);//MOTOR DIREITA IR PARA TRÁS
  digitalWrite(rele4, LOW);
}

void esquerda() {
  digitalWrite(rele1, LOW);//MOTOR DA ESQUERDA IR PARA FRENTE
  digitalWrite(rele2, LOW);

  digitalWrite(rele3, LOW);//MOTOR DIREITA IR PARA TRÁS
  digitalWrite(rele4, HIGH);
}

void frente() {
  digitalWrite(rele1, HIGH);//MOTOR DA ESQUERDA IR PARA FRENTE
  digitalWrite(rele2, LOW);

  digitalWrite(rele3, LOW);//MOTOR DIREITA IR PARA FRENTE
  digitalWrite(rele4, HIGH);
}

void tras() {
  digitalWrite(rele1, LOW);//MOTOR DA ESQUERDA IR PARA FRENTE
  digitalWrite(rele2, HIGH);

  digitalWrite(rele3, HIGH);//MOTOR DIREITA IR PARA FRENTE
  digitalWrite(rele4, LOW);
}

void para() {
  digitalWrite(rele1, LOW);//MOTOR DA ESQUERDA IR PARA FRENTE
  digitalWrite(rele2, LOW);

  digitalWrite(rele3, LOW);//MOTOR DIREITA IR PARA FRENTE
  digitalWrite(rele4, LOW);
}
