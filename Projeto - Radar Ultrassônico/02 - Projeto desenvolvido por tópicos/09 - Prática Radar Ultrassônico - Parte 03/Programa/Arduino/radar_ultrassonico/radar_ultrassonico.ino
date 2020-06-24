#include <Servo.h> //Biblioteca do Servo Motor

/*
   Teste do Sensor Ultrassônico HC-SR04 com o Servo motor

   Objetivo: Construir um radar ultrassônico com o sensor HCSR04 e o servo motor

   Autora: Téc. em Mecatrônica - Ivoneide Duarte

   Data: Junho de 2020
*/

const int pinTrigger = 3; //Pino 3 do Arduino será a saída de trigger
const int pinEcho = 2;    //Pino 2 do Arduino será a entrada de echo

long tempo;
int distancia;

Servo servo;

void setup()
{
  pinMode(pinTrigger, OUTPUT); //Pino de trigger será saída digital
  pinMode(pinEcho, INPUT);     //Pino de echo será entrada digital

  Serial.begin(9600);          //Inicia comunicação serial
  servo.attach(12);            //Anexar o servo
}

void loop()
{
//Servo gire de 0 a 180º
//Servo volte de 180 a 0º
//  for (byte i = 0; i <= 180; i++)
//  { // O servo irá girar de 15° até 165°
//    servo.write(i);
//    delay(30); //Enviar a informação da distancia
//    distancia = calculoDistancia();
//    Serial.print(distancia);
//  }
//  for (byte i = 180; i >= 0; i--)
//  { // O servo irá girar de 15° até 165°
//    servo.write(i);
//    delay(30); //Enviar a informação da distancia
//    distancia = calculoDistancia();
//    Serial.print(distancia);
//  }


  for (byte i = 0; i <= 180; i++)
  { // O servo irá girar de 15° até 165°
    servo.write(i);
    delay(30);

    // Nessa parte, enquanto o servo gira, o sensor verifica
    // Se tem algum objeto e qual a distancia
    // Chamando a função 'CalculandoDistancia()'
    distancia = calculoDistancia();
    Serial.print(i);         // Mostra na serial qual o angulo de giro o servo está naquele momento
    Serial.print(",");       // Aqui vamos separar o angulo da distancia calculada com uma vírgula
    Serial.print(distancia); // Mostra a distancia que o sensor está calculando
    Serial.print(".");       // Coloca um '.' depois da distancia para indexar no processing a distancia
  }

  for (byte i = 180; i > 0; i--)
  { // Os mesmos passos que fizemos para ele ir de 15° --> 165°
    // Vamos utilizar para ele voltar de 165° --> 15°
    servo.write(i);
    delay(30);
    distancia = calculoDistancia();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print("."); //Processing -> tua barra vai se movimentar
  }
}

int calculoDistancia()
{
  digitalWrite(pinTrigger, LOW); // Aqui vou desligar o trigger para poder realizar os pulsos
  delayMicroseconds(2); //Desativado

  digitalWrite(pinTrigger, HIGH); //Pulso de trigger em nível alto
  delayMicroseconds(10);  //Pulso ativo  //duração de 10 microsegundos
  digitalWrite(pinTrigger, LOW);  //Pulso de trigge em nível baixo
  tempo = pulseIn(pinEcho, HIGH); //Escuta a porta 10(Echo), tempo de echo: 10 microssegundos e 3min
  distancia = tempo * 0.034 / 2; // Por fim, esta é a fórmula que utilizamos para converter o tempo na distancia do objeto até o sensor

  return distancia;

  //v=342m/s --> velocidade do som
  //t= tempo = pilseIn(pinEcho, HIGH)
  //s = distancia que quero encontrar
  //distancia = tempo*0.017; //centimetros -> 400cm
  //distancia = tempo*0.17; //decimetros -> 40dm
  //4 metros
}
