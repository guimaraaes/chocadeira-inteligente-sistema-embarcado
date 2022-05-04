#include "controle.cpp"
class Umidade
{
    Controle controle;
    void abastecerReservatorio()
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
            abastecerReservatorio();
    }
};