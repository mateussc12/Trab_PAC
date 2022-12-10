#ifndef _SERIE_H
#define _SERIE_H

#include <stdlib.h>
#include <fstream>
#include <cstdlib>

#include "Temporada.h"
#include "ProdutoAV.h"

class Serie:public ProdutoAV
{

private:

    int qtdTemporadas;

    void cadastrarTemporada(int num);
    vector <Temporada*> Temporadas;


public:

    Serie();
    Serie(string nome, int clas, string gen, string urli, string urlt, int qtdTemp);
    vector <Temporada*> getTemporadas();
    int getQtdTemporadas();
    void setQtdTemporadas(int qtdTemporadas);
    void imprimirTemporadas();
    void imprimeInfoProduto();

    void imprimeNoArquivo(ofstream &outfile);
    void carregaArquivo(ifstream &infile);

};

#endif
