#ifndef _FILME_H
#define _FILME_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "ProdutoAV.h"

using namespace std;

class Filme:public ProdutoAV
{

private:

    int duracao;
    int anoLancamento;

    void formataDuracao();

public:

    Filme();
    Filme(string nome, int clas, string gen,string urli, string urlt, float duracao, int ano);
    int getDuracao();
    void setDuracao(int duracao);
    int getAnoLancamento();
    void setAnoLancamento(int anoLancamento);
    void imprimeInfoProduto();

    void imprimeNoArquivo(ofstream &outfile);
    void carregaArquivo(ifstream &infile);

};

#endif
