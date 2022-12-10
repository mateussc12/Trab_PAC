#ifndef _ASSINANTE_H
#define _ASSINANTE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "ProdutoAV.h"
#include "Filme.h"
#include "Serie.h"


using namespace std;

class Assinante
{
private:

    string nome;
    vector <ProdutoAV*> favoritos;

public:

    Assinante();
    Assinante(string nome);
    ~Assinante();
    void imprimeFavoritos();
    void inserirFavorito(ProdutoAV* favorito);
    void removerFavorito();
    string getNome();
    void setNome(string nome);
    vector <ProdutoAV*> getFavoritos();

    void imprimeNoArquivo(ofstream &outfile);
    void carregaArquivo(ifstream &infile);

};

#endif
