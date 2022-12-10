#ifndef _PLATAFORMA_H
#define _PLATAFORMA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Produtor.h"
#include "Assinante.h"

using namespace std;

class Plataforma
{
private:

    string nome;
    vector <ProdutoAV*> produtosCadastrados;
    vector <ProdutoAV*> produtosOriginais;
    vector <Assinante*> assinantes;

public:

    Plataforma();
    Plataforma(string nome);
    void imprimeProdutosCadastrados();
    void imprimeProdutosDestaque();
    void imprimeProdutosOriginais();
    void imprimeProdutos(string genero);
    void imprimeAssinantes();
    void inserirAssinante();
    void removerAssinate();
    int inserirProduto(ProdutoAV* novoProduto, string nomeProdutor);
    void colocarProdutoDestaque();
    void removerProdutoDestaque();
    int selecionaAssinante();
    void inserirProdutoAssinante();
    string getNome();
    void setNome(string nome);
    vector <ProdutoAV*> getProdutosCadastrados();
    vector <ProdutoAV*> getProdutosOriginais();
    vector <Assinante*> getAssinantes();


    void imprimeNoArquivo(ofstream &outfile);
    void carregaArquivo(ifstream &infile);
    void exportarBiblioteca();

};


#endif
