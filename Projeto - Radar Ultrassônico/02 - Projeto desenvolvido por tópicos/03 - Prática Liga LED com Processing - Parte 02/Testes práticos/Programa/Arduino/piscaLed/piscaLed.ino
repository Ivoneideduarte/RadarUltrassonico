/* ========================================================================================================
 
  Projeto: Utilizando Processing com Arduino Parte 1
  Autor: Ivoneide Duarte
  Data: 25/05/2020
  Fonte: Autocore Robótica

// ======================================================================================================== */

// -- Definindo as variáveis --
  int LED = 13;
  int entrada = 0;
// ========================================================================================================

// -- Definindo o Setup() --
  void setup()
  {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
  }
// ========================================================================================================

// -- Definindo o Loop() --
void loop()
  {
    // apenas responde quando dados são recebidos:
    if (Serial.available() > 0)
    { 
      // lê do buffer o dado recebido:
      entrada = Serial.read();
    
      if (entrada == '0')
        digitalWrite(LED, LOW);
    
      else if (entrada == '1')
        digitalWrite(LED, HIGH);
    }
  }
// ========================================================================================================
