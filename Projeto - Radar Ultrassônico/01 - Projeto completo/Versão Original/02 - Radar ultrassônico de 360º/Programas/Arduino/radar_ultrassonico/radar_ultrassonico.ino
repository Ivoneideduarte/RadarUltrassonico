////////////////////////////////////////////////////////////////////////////
//            ------ Radar Ultrassônico de 360º -------
//               Projeto: Radar com HC-SR04
//               Autora: Ivoneide Duarte
//               Data: 28/06/2020         
///////////////////////////////////////////////////////////////////////////

#include <Servo.h> //Biblioteca do Servo Motor

//Conexões para o primeiro sensor de distância 
const int pinTrigger_1 = 6;
const int pinEcho_1 = 5; 

//Conexões para o segundo sensor de distância 
const int pinTrigger_2 = 3;
const int pinEcho_2 = 4;

#define pinServo 2

long tempo;
int dist_1, dist_2; //Distâncias

Servo servo;

void setup()
{
  pinMode(pinTrigger_1, OUTPUT); //Pino de trigger será saída digital
  pinMode(pinEcho_1, INPUT);     //Pino de echo será entrada digital
  pinMode(pinTrigger_2, OUTPUT); 
  pinMode(pinEcho_2, INPUT);
  
  servo.attach(pinServo);        //Anexar o servo
  
  Serial.begin(9600);            //Inicia comunicação serial 
}

void loop()
{
  for (byte i = 0; i <= 180; i++)
  { // O servo irá girar de 0° até 180°
    servo.write(i);
    delay(30);

    //Mostra a distância do primeiro sensor
    dist_1 = calculoDistancia_1();
    Serial.print(i);         // Mostra na serial qual o angulo de giro o servo está naquele momento
    Serial.print(",");       // Aqui vamos separar o angulo da distancia calculada com uma vírgula
    Serial.print(dist_1);    // Mostra a distancia que o sensor está calculando
    Serial.print(".");       // Coloca um '.' depois da distancia para indexar no processing a distancia

  }

  for (byte i = 180; i > 0; i--)
  { // O servo irá girar de 180° até 0°
    servo.write(i);
    delay(30);
    
    //Mostra a distância do segundo sensor
    dist_2 = calculoDistancia_2();
    Serial.print(i);
    Serial.print(",");
    Serial.print(dist_2);
    Serial.print(".");
  }
}

int calculoDistancia_1()
{
  digitalWrite(pinTrigger_1, LOW); // Aqui vou desligar o trigger para poder realizar os pulsos
  delayMicroseconds(2); //Desativado

  digitalWrite(pinTrigger_1, HIGH); //Pulso de trigger em nível alto
  delayMicroseconds(10);  //Pulso ativo  //duração de 10 microsegundos
  digitalWrite(pinTrigger_1, LOW);  //Pulso de trigge em nível baixo
  tempo = pulseIn(pinEcho_1, HIGH); //Escuta a porta 10(Echo), tempo de echo: 10 microssegundos e 3min
  dist_1 = tempo * 0.034 / 2; // Por fim, esta é a fórmula que utilizamos para converter o tempo na distancia do objeto até o sensor

  return dist_1;
}

int calculoDistancia_2()
{
  digitalWrite(pinTrigger_2, LOW); // Aqui vou desligar o trigger para poder realizar os pulsos
  delayMicroseconds(2); //Desativado

  digitalWrite(pinTrigger_2, HIGH); //Pulso de trigger em nível alto
  delayMicroseconds(10);  //Pulso ativo  //duração de 10 microsegundos
  digitalWrite(pinTrigger_2, LOW);  //Pulso de trigge em nível baixo
  tempo = pulseIn(pinEcho_2, HIGH); //Escuta a porta 10(Echo), tempo de echo: 10 microssegundos e 3min
  dist_2 = tempo * 0.034 / 2; // Por fim, esta é a fórmula que utilizamos para converter o tempo na distancia do objeto até o sensor

  return dist_2;
}
