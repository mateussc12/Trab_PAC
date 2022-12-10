#ifndef _PRODUTOR_H
#define _PRODUTOR_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "ProdutoAV.h"
#include "Filme.h"
#include "Serie.h"

using namespace std;

class Produtor
{
private:

    string nome;
    vector <ProdutoAV*> produtosDesenvolvidos;

public:

    Produtor();
    Produtor(string nome);
    void criarProduto();
    void imprimeProdutosDesenvolvidos();
    string getNome();
    void setNome(string nome);
    vector <ProdutoAV*> getProdutosDesenvolvidos();

    friend int SelecionaProdutor( vector <Produtor*> prod );

    void imprimeNoArquivo(ofstream &outfile);
    void carregaArquivo(ifstream &infile);

};

#endif
