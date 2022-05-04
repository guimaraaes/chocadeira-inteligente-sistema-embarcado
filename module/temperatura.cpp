#include "controle.cpp"
class Temperatura
{
    Controle controle;

    void acionarVentilacao()
    {
    }

    void acionarAquecedor()
    {
    }

public:
    void acionamento(float padrao, float chocadeira)
    {
        if (controle.abaixoLimite(padrao, chocadeira))
            acionarAquecedor();

        else if (controle.acimaLimite(padrao, chocadeira))
            acionarVentilacao();
    }
};