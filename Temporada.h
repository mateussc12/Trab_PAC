#ifndef _TEMPORADA_H
#define _TEMPORADA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class Temporada
{

private:

    int numero;
    int qtdEpisodios;
    int duracaoMediaEpisodios;
    int anoLancamento;
    void formataDuracao();

public:

    Temporada();
    Temporada(int num, int qtdEps, float duracao, int ano);
    int getNumero();
    void setNumero(int numero);
    int getQtdEpisodios();
    void setQtdEpisodios(int qtdEpisodios);
    int getDuracaoMediaEpisodios();
    void setDuracaoMediaEpisodios(int duracaoMediaEpisodios);
    int getAnoLancamento();
    void setAnolancamento(int anoLancamento);
    void imprimeInfoTemporada();

    void imprimeNoArquivo(ofstream &outfile);
    void carregaArquivo(ifstream &infile);

};
#endif

