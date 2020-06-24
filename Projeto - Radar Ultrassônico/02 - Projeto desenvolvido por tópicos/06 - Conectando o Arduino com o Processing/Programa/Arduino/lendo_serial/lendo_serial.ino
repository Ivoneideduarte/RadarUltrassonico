char incomingByte = 0; //Variável para o dado recebido
#define ledBlink 13

void setup()
{
  Serial.begin(9600);
  pinMode(ledBlink, OUTPUT);
}

void loop()
{
  //Apenas responde quando dados são recebidos
  if (Serial.available() > 0) // Significa que está recebendo dados na serial
  {
    //Lê do buffer o dado recebido
    incomingByte = Serial.read(); // Está armazenando na varável 'incomingByte' o valor lido na serial

    if (incomingByte == 'a')
    {
      digitalWrite(ledBlink, HIGH);
    }
    if (incomingByte == 'b')
    {
      digitalWrite(ledBlink, LOW);
    }
  }
}
