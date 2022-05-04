
class Controle
{

public:
    bool acimaLimite(float variavel_padrao, float variavel_chocadeira)
    {
        return variavel_chocadeira > variavel_padrao * 1.05;
    }

    bool abaixoLimite(float variavel_padrao, float variavel_chocadeira)
    {
        return variavel_chocadeira < variavel_padrao * 95;
    }

    // virtual void acionamento(bool temp, float padrao, float chocadeira);
};