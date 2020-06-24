/*
   Teste do Sensor Ultrassônico HC-SR04
   
   Objetivo: medir a distância em centímetros exibindo os dados via serial monitor
   
   Autora: Téc. em Mecatrônica - Ivoneide Duarte
   
   Data: Junho de 2020
*/

const int pinTrigger = 3; //Pino 3 do Arduino será a saída de trigger
const int pinEcho = 2;    //Pino 2 do Arduino será a entrada de echo

long tempo;
int distancia;

void setup()
{
  pinMode(pinTrigger, OUTPUT); //Pino de trigger será saída digital
  pinMode(pinEcho, INPUT);     //Pino de echo será entrada digital

  Serial.begin(9600);          //Inicia comunicação serial
}

void loop()
{
  distancia = calculoDistancia(); 
  Serial.print("Distancia: ");
  Serial.println(distancia);  //Imprime o valor na serial

  delay(500);                 //Taxa de atualização
}

int calculoDistancia()
{
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(2); //Desativado

  digitalWrite(pinTrigger, HIGH); //Pulso de trigger em nível alto
  delayMicroseconds(10);          //Pulso ativo  //duração de 10 microsegundos
  digitalWrite(pinTrigger, LOW);  //Pulso de trigge em nível baixo
  tempo = pulseIn(pinEcho, HIGH); //Escuta a porta 10(Echo), tempo de echo: 10 microssegundos e 3min
  distancia = tempo * 0.034 / 2;

  return distancia;
  
  //v=342m/s --> velocidade do som
  //t= tempo = pilseIn(pinEcho, HIGH)
  //s = distancia que quero encontrar
  //distancia = tempo*0.171;
}
