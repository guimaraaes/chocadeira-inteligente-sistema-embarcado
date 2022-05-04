#include <Arduino.h>
#include "../module/comunicacao.cpp"
#include "../module/controle.cpp"
Comunicacao com;
Controle controle;

void setup()
{
  com.connectWIFI();

  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:

  controle.acionamento(true, com.getProcess().temperatura, com.CI().temperatura);
  controle.acionamento(false, com.getProcess().umidade, com.CI().umidade);
}