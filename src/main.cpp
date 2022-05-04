#include <Arduino.h>
#include "../module/comunicacao.cpp"
#include "../module/temperatura.cpp"
#include "../module/umidade.cpp"
#include "../module/viragem.cpp"
Comunicacao com;
Temperatura temp;
Umidade umid;
Viragem vir;

void setup()
{
  // put your setup code here, to run once:
  com.connectWIFI();
}

void loop()
{
  // put your main code here, to run repeatedly:

  temp.acionamento(com.getProcess().temperatura, com.CI().temperatura);
  umid.acionamento(com.getProcess().umidade, com.CI().umidade);
  vir.acionamento(com.getHorario(), com.getUltimaViragem());
}