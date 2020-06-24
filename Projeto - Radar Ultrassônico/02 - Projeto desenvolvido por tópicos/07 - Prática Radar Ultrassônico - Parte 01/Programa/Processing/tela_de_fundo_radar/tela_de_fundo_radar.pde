import processing.serial.*;       // Biblioteca responsável por gerenciar a comunicação serial entre a IDE Arduino e a IDE Processing
import java.awt.event.KeyEvent;   // É uma classe JAVA de um evento que é gerado por um campo de texto quando ele é digitado
import java.io.IOException;       // É uma classe JAVA que sinaliza quando houver alguma exceção de entrada/saída

Serial myPort; // Objeto da porta serial

String data = "";
String angulo = "";
String distancia = "";
int index1 = 0;

int iAngulo=0;
int iDistancia=0;

void setup()
{
  // Criação da janela
  frame.setTitle("Tela de fundo do Radar"); // Define o título que irá aparecer na parte superior da janela
  size(1366, 760);                          //Ajusta a resolução da tela em 1366x768 pixels
  myPort = new Serial(this, "COM3", 9600);  //Inicia a comunicação serial na COM4 com uma taxa de transmissão de 9600bps
  myPort.bufferUntil('.');                  //Lê os dados da porta serial até o caractere '.', então, na verdade, ele lê o seguinte: ângulo, distância
}

void draw()
{
  //Chamando a função
  fill(98, 245, 31); //Cor verde
  noStroke();
  fill(0,10);
  rect(0, 0, width, 1010);
  fill(98, 245, 31);
   
  //Chama as funções para desenhar o radar
  drawRadar();
  drawObject();
  
  //print(iAngulo);
  //print(iDistancia);
}


void serialEvent(Serial myPort) // Começa a ler dados da porta serial
{ 
  //Arduino envia 4 coisas: ângulo - virgula - distância - ponto
  //dados = "Ivoneide";
  //dados.length();
  
  // O ponto serve para seprar duas informações
  // Lê os dados da porta serial até o caractere '.' e coloca na variável String "data"
  data = myPort.readStringUntil('.');         // Ler a string até achar o ponto
  data = data.substring(0, data.length()-1);  // Transforma valores recebidos //40.130
  
  // Encontra o caractere ',' e o coloca na variável "index1"
  index1 = data.indexOf(","); // Achar a posição da virgula //2
  // Lê os dados da posição "0" para a posição da variável index1, ou seja, é o valor do ângulo que a placa Arduino enviou para a porta serial
  angulo = data.substring(0, index1); //40
  
  distancia = data.substring(index1+1, data.length()); //130
  
  // Converte as variáveis String em Inteiro
  iAngulo = int(angulo); // Mudar para o tipo int
  iDistancia = int(distancia);
}

void drawRadar()
{
  //arc(xCentro, yCentro, distDireita, disEsquerda, 180, 360)
  
  pushMatrix();         // Aguarda algo
  translate(683, 700);  // Deslocando o centro
  noFill();             // Elimina o fundo do semi circulo
  strokeWeight(3);      // Espessura da linha do circulo
  stroke(98, 245, 31);  // Mostrar o contorno
  //arc(683, 700, 1300, 1300, 180, 360);
  //arc(683, 700, 1000, 1000, 180, 360);
  //arc(683, 700, 700, 700, 180, 360);
  //arc(683, 700, 400, 400, 180, 360);
  
  //Desenha as linhas do arco
  arc(0, 0, 1300, 1300, PI, TWO_PI);
  arc(0, 0, 1000, 1000, PI, TWO_PI);
  arc(0, 0, 700, 700, PI, TWO_PI);
  arc(0, 0, 400, 400, PI, TWO_PI);
  
  //Desenha as linhas angulares
  //line(xInicial, yInicial, xFinal, yFinal)
  line(-700, 0, 700, 0);
  line(0, 0, -700*cos(radians(30)), -700*sin(radians(30)));
  line(0, 0, -700*cos(radians(60)), -700*sin(radians(60)));
  line(0, 0, -700*cos(radians(90)), -700*sin(radians(90)));
  line(0, 0, -700*cos(radians(120)), -700*sin(radians(120)));
  line(0, 0, -700*cos(radians(150)), -700*sin(radians(150)));
  line(-700*cos(radians(30)), 0,700,0);
  
  popMatrix(); //Mostra o que foi guardado
}

void drawObject()
{ //Impressão de leitura do sensor ultrassônico

  //Imprimi o ângulo e distância
  textSize(30); //tamanho da letra
  text("Ângulo: ", 10, 30);
  text(iAngulo, 200, 30); //distancia eixo x:10 eixo y:30
  text("Distância: ", 10, 100);
  text(iDistancia, 200, 100); 
  fill(0, 182, 150);
}
