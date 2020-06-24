// Tipo de dados para armazenar imagens
PImage Pixels;  
PImage bomba; 

void setup()
{
  
  // Criação da janela
  frame.setTitle("Título da janela");  // Define o título que irá aparecer na parte superior da janela
  size(1280, 765);                     // Resolução da tela
  background(105,89,205);              // Define a cor do fundo da janela em RGB
  
  // Carregando imagens
  Pixels = loadImage("logo_pixels.jpg"); // Carrega uma imagem em uma variável do tipo PImage

  //Redução de imagem
  Pixels.resize(100,100);  // Redimensiona a imagem
  image(Pixels, 550,100);  // Desenha uma imagem na janela de exibição
  
  // Escrita de texto
  fill(255);                 // Cor do texto
  textFont(createFont("Rockwell", 50)); // Eixo x,y
  text("Trabalhando com imagens", 300, 50);
   
  bomba = loadImage("bomba.png");    // Está sendo armazenado na varável bomba, a imagem de uma bomba
  image(bomba, 350, 150);            // Desenha uma imagem na janela de exibição
  
  bomba.resize(200,200);             // Redimensiona a imagem
  image(bomba, 300, 250);            // Desenha uma imagem na janela de exibição
  
}

void draw()
{
  
}
