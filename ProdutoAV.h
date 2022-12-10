#ifndef _PRODUTOAV_H
#define _PRODUTOAV_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class ProdutoAV
{
protected:

    string nome;
    bool emDestaque;
    int classificacaoIndicativa;
    string urlImagem;
    string urlTrailer;

    class Genero
    {
    private:

        string nome;

    public:

        Genero();
        Genero(string nome);
        string getNome();
        void setNome(string nome);

    };

    Genero* g;

    public:

    static int qtdProdutos;
    static void imprimeQtdProdutos();

    ProdutoAV();
    ProdutoAV(string nome, int classificacaoIndicativa, string genero, string urlI,string urlT);
    virtual void imprimeInfoProduto() = 0;
    string getNome();
    void setNome(string nome);
    ProdutoAV::Genero* getGenero();
    void setGenero(Genero* g);
    int getClassificacaoIndicativa();
    void setClassificacaoIndicativa(int classificacao);
    bool getEmDestaque();
    void setEmDestaque(bool EmDestaque);


    string getUrlImagem();
    void setUrlImagem( string url);
    string getUrlTrailer();
    void setUrlTrailer(string url);

    virtual void imprimeNoArquivo(ofstream &outfile) = 0;
    virtual void carregaArquivo(ifstream &infile) = 0;


    friend void Menu( string plat);



};

#endif
