#include "Temporada.h"

void Temporada::formataDuracao()
{

    int minutos,horas;

    minutos = getDuracaoMediaEpisodios();
    horas = minutos/60;
    minutos = minutos % 60;
    if( minutos%60 == 0)
    {
        cout << "    Tempo de duracao em media: " << horas << " horas" << endl;
    }
    else if(horas == 0)
    {
        cout << "    Tempo de duracao em media: " << minutos << " minutos" << endl;
    }
    else
    {
        cout << "    Tempo de duracao em media: " << horas << " horas e  " << minutos << " minutos" << endl;
    }
}

Temporada::Temporada() {}

Temporada::Temporada(int num, int qtdEps, float duracao, int ano)
{

    this->numero = num;
    this->qtdEpisodios = qtdEps;
    this->duracaoMediaEpisodios = duracao;
    this->anoLancamento = ano;

}

int Temporada::getNumero()
{

    return this->numero;

}

void Temporada::setNumero(int numero)
{

    this->numero = numero;

}

int Temporada::getQtdEpisodios()
{

    return this->qtdEpisodios;

}

void Temporada::setQtdEpisodios(int qtdEpisodios)
{

    this->qtdEpisodios = qtdEpisodios;

}

int Temporada::getDuracaoMediaEpisodios()
{

    return this->duracaoMediaEpisodios;

}

void Temporada::setDuracaoMediaEpisodios(int duracaoMediaEpisodios)
{

    this->duracaoMediaEpisodios = duracaoMediaEpisodios;

}

int Temporada::getAnoLancamento()
{

    return this->anoLancamento;

}

void Temporada::setAnolancamento(int anoLancamento)
{

    this->anoLancamento = anoLancamento;

}

void Temporada::imprimeInfoTemporada()
{

    cout << "    Numeros de episodios: " << getQtdEpisodios() << endl;
    formataDuracao();
    cout << "    Ano de lancamento: " << getAnoLancamento() << endl;

}

void Temporada::imprimeNoArquivo(ofstream &outfile)
{
    outfile << this->numero << endl;
    outfile << this->qtdEpisodios << endl;
    outfile << this->duracaoMediaEpisodios << endl;
    outfile << this->anoLancamento << endl;
}

void Temporada::carregaArquivo(ifstream &infile)
{
    infile >> this->numero;
    infile >> this->qtdEpisodios;
    infile >> this->duracaoMediaEpisodios;
    infile >> this->anoLancamento;
}
