class Viragem
{
    void virarOvos() {}

public:
    void acionamento(int horario, int ultima_viragem)
    {
        if (horario <= ultima_viragem)
            virarOvos();
    }
};