#include "temperatura.cpp"
#include "umidade.cpp"

class Controle
{
public:
    Temperatura temperatura;
    Umidade umidade;

    bool acimaLimite(float variavel_padrao, float variavel_chocadeira)
    {
        return variavel_chocadeira > variavel_padrao * 1.05;
    }

    bool abaixoLimite(float variavel_padrao, float variavel_chocadeira)
    {
        return variavel_chocadeira < variavel_padrao * 95;
    }

    void acionamento(bool temp, float padrao, float chocadeira)
    {
        if (abaixoLimite(padrao, chocadeira))
        {
            if (temp)
                temperatura.acionarAquecedor();
            else
                umidade.abastecerReservatorio();
        }
        else if (acimaLimite(padrao, chocadeira))
        {
            if (temp)
                temperatura.acionarVentilacao();
        }
    }
};