////////////////////////////////////////////////////////////////////////////
//            ------ Radar Ultrassônico de 180º -------
//               Projeto: Radar com HC-SR04
//               Autora: Ivoneide Duarte
//               Data: 28/06/2020         
///////////////////////////////////////////////////////////////////////////

#include <Servo.h>

// Definição dos pinos de Echo e Trigger do HC-SR04
const int pinTrigger = 3;
const int pinEcho = 2;

// Cálculo da distância do objeto
long tempo;
int distancia;

// Objeto chamado 'Radar_Servo'
Servo Radar_Servo;

void setup()
{
  pinMode(pinTrigger, OUTPUT); // Trigger definido como saída
  pinMode(pinEcho, INPUT);     // Echo definido como entrada

  Serial.begin(9600);          // Inicializando a Comunicação Serial
  Radar_Servo.attach(12);       // Pino que define a conexão do servo
}

void loop() 
{
  // O servo irá girar de 15° até 165° ou de 0° até 180°
  for (int i = 0; i <= 180; i++) 
  {
    Radar_Servo.write(i); // O servo irá rotacionar de 0° até 180°
    delay(30);

    // Nessa parte, enquanto o servo gira, o sensor verifica
    // Se tem algum objeto e qual a distância
    // Chamando a função 'CalculandoDistancia()'
    distancia = calculandoDistancia();

    Serial.print(i);         // Mostra na serial qual o ângulo de giro o servo está naquele momento
    Serial.print(",");       // Aqui vamos separar o ângulo da distância calculada com uma vírgula
    Serial.print(distancia); // Mostra a distância que o sensor está calculando
    Serial.print(".");       // Coloca um '.' depois da distância para indexar no processing a distância
  }

  // Os mesmos passos que fizemos para ele ir de 15° --> 165° ou 0º --> 180º
  // Vamos utilizar para ele voltar de 165° --> 15° ou 180º --> 0º
  for (int i = 180; i > 0 ; i--) 
  {
    Radar_Servo.write(i); // O servo irá rotacionar de 180° até 0°
    delay(30);

    // Nessa parte, enquanto o servo gira, o sensor verifica
    // Se tem algum objeto e qual a distância
    // Chamando a função 'CalculandoDistancia()'
    distancia = calculandoDistancia();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }
}

// Aqui vamos criar a função que utilizamos ali em cima
// Para poder calcular a distância sabe?
int calculandoDistancia() 
{
  digitalWrite(pinTrigger, LOW);  // Aqui vou desligar o trigger para poder realizar os pulsos
  delayMicroseconds(2);

  // Aqui é onde ligo o trigger por 10 ms
  // Que é o tempo para calcular a distância
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);

  tempo = pulseIn(pinEcho, HIGH);  // Aqui setamos o Echo para capitar o pulso ultrassônico e voltar o tempo que ele demorou

  distancia = tempo * 0.034 / 2; // Por fim, esta é a fórmula que utilizamos para converter o tempo na distância do objeto até o sensor
  return distancia;
}
