// Importação de bibliotecas
import processing.serial.*; // Biblioteca responsável por gerenciar a comunicação serial entre a IDE Arduino e a IDE Processing
Serial porta;               // Armazena qual porta o Arduino está conectado

PImage Pixels, botao; // Tipo de dados para armazenar imagens
int status = 0;       // Váriavel 'status' do tipo inteiro inicializando com zero

void setup()
{
  String COM3 = Serial.list()[0]; 
  porta = new Serial(this, "COM3", 9600); // Inicia a comunicação serial na COM3 com uma taxa de transmissão de 9600bps
  
  //Criação da janela
  frame.setTitle("Controle de LED");  // Define o título que irá aparecer na parte superior da janela
  size(1366, 768);                    // Resolução da tela
  background(53, 156, 196);           // Define a cor do fundo da janela em RGB
  
  // Carregando imagens
  Pixels = loadImage("logo_pixels01.png"); // Carrega uma imagem em uma variável do tipo PImage
  // Criação da imagem
  image(Pixels, 150,0);                    // Desenha uma imagem na janela de exibição
  
  // Carregando imagens 
  botao = loadImage("bomba-desligada.png");
  // Criação da imagem
  image(botao, 250, 0);
  
}

void draw()
{
  clear();
  
  background(53, 156, 196); // Define a cor do fundo da janela em RGB
  // Carregando imagens
  Pixels = loadImage("logo_pixels01.png"); // Carregue a imagem para cá, endereço da imagem no computador
  // Criação da imagem
  image(Pixels, 150,0);
  
  fill(255); // Cor do texto
  textFont(createFont("Rockwell", 50));
  text("Projeto: Liga BOMBA", 830, 80);

  image(botao, 250, 0); // Desenha uma imagem na janela de exibição
}
void mouseClicked()
{ //Faz a leitura do mouse

  //Se for 0 bomba desl
  if(status == 0)
  { // liga a bomba
    botao = loadImage("bomba-ligada.png");
    status = 1;
    porta.write('0'); //Escreve o número '0' na serial do Arduino
  }
  
  //Se for 1 bomba liga
  else
  { //desliga a bomba
    botao = loadImage("bomba-desligada.png");
    status = 0;
    porta.write('1'); //Escreve o número '1' na serial do Arduino
  }
}
