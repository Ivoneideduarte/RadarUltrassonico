import processing.serial.*;        // Biblioteca responsável por gerenciar a comunicação serial entre a IDE Arduino e a IDE Processing
import java.awt.event.KeyEvent;    // É uma classe JAVA de um evento que é gerado por um campo de texto quando ele é digitado
import java.io.IOException;        // É uma classe JAVA que sinaliza quando houver alguma exceção de entrada/saída

Serial myPort; // Objeto da porta serial

String angle="";
String distance="";
String data="";
int iAngle, iDistance;
int index1=0;
int index2=0;


void setup() 
{

  // Criação da janela
  frame.setTitle("Ambiente do desenho do texto"); // Define o título que irá aparecer na parte superior da janela
  size(1366, 768);                                // Resolução da tela
  smooth();
  myPort = new Serial(this, "COM3", 9600);        //Inicia a comunicação serial na COM4 com uma taxa de transmissão de 9600bps
  myPort.bufferUntil('.');                        //Lê os dados da porta serial até o caractere '.', então, na verdade, ele lê o seguinte: ângulo, distância
}

void draw() 
{

  fill(98, 245, 31);

  noStroke();
  fill(0, 10); 
  rect(0, 0, width, 1010); 

  fill(98, 245, 31); 
  
  //Chama as funções para desenhar o radar
  drawRadar();
  drawObject();
  drawText();

}

void serialEvent (Serial myPort)  // Começa a ler dados da porta serial
{ 
  //Arduino envia 4 coisas: ângulo - virgula - distância - ponto
  //dados = "Ivoneide";
  //dados.length();
  
  // O ponto serve para seprar duas informações
  // Lê os dados da porta serial até o caractere '.' e coloca na variável String "data"
  data = myPort.readStringUntil('.');          // Ler a string até achar o ponto
  data = data.substring(0, data.length()-1);   // Transforma valores recebidos //40.130
  
  // Encontra o caractere ',' e o coloca na variável "index1"
  index1 = data.indexOf(",");   // Achar a posição da virgula
  // Lê os dados da posição "0" para a posição da variável index1, ou seja, é o valor do ângulo que a placa Arduino enviou para a porta serial
  angle= data.substring(0, index1); 
  
  distance= data.substring(index1+1, data.length()); 


  iAngle = int(angle);
  iDistance = int(distance);
  
}

void drawRadar()
{
  //arc(xCentro, yCentro, distDireita, distEsquerda, 180, 360)
  pushMatrix();               // Aguarda algo
  
  translate(683,700);         // Deslocando o centro
  noFill();                   // Elimina o fundo do semi circulo
  strokeWeight(3);            // Espessura da linha do circulo
  stroke(98, 245, 31);        // Mostrar o contorno
  arc(0, 0, 1300, 1300, PI, TWO_PI);
  arc(0, 0, 1000, 1000, PI, TWO_PI);
  arc(0, 0, 700, 700, PI, TWO_PI);
  arc(0, 0, 400, 400, PI, TWO_PI);
  
  //Desenha as linhas angulares
  //line(xInicial, yInicial, xFinal, yFinal)
  line(-700, 0, 700, 0);
  line(0, 0, -670*cos(radians(30)), -670*sin(radians(30)));
  line(0, 0, -700*cos(radians(60)), -700*sin(radians(60)));
  line(0, 0, -700*cos(radians(90)), -700*sin(radians(90)));
  line(0, 0, -700*cos(radians(120)), -700*sin(radians(120)));
  line(0, 0, -700*cos(radians(150)), -700*sin(radians(150)));
  
  popMatrix();
}

void drawObject() 
{
  //Impressão de leitura do sensor ultrassônico
  
  //Imprimi o ângulo e distância
  textSize(32);
  text("Distância: ", 10, 30);
  text(iDistance, 200, 30); 
  text("Ângulo: ", 10, 100);
  text(iAngle, 200, 100);
  fill(0, 102, 153);
  
}

void drawText()
{
  
  pushMatrix();
  
  noStroke();
  rect(0, 1010, width, 1010);
  //Qual a cor do texto
  fill(98,245,31);
  // Tamanho do texto
  textSize(25);
  // Escrita das distâncias
  text("10 cm", 800, 690); 
  text("20 cm", 950, 690); 
  text("30 cm", 1100, 690); 
  text("40 cm", 1250, 690); 
  
  // Cor do texto
   fill(98,245,31);
  // Tamanho do texto
  textSize(25);
  //Escrita dos Angulos
  translate(410 + 960*cos(radians(30)), 800 -960*sin(radians(30)));
  rotate(radians(60));
  text("30º", 0, 0);
  resetMatrix();
  
  translate(490 + 960*cos(radians(60)), 920 -960*sin(radians(60))); 
  rotate(radians(30));
  text("60º", 0, 0);
  resetMatrix();
  
  translate(630 + 960*cos(radians(90)), 990 -960*sin(radians(90))); 
  rotate(radians(0));
  text("90º", 0, 0);
  resetMatrix();
  
  translate(760 + 960*cos(radians(120)), 1000 -960*sin(radians(120)));
  rotate(radians(-30));
  text("120º", 0, 0);
  resetMatrix();
  
  translate(900 + 960*cos(radians(150)), 920 -960*sin(radians(150)));
  rotate(radians(-60));
  text("150º", 0, 0);
  resetMatrix();
  
  popMatrix();
}
