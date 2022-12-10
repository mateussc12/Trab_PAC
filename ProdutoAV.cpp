#include "ProdutoAV.h"

void ProdutoAV::imprimeQtdProdutos()
{
if(qtdProdutos == 0)
            {
                cout << endl;
                cout << "    (!) Nao existem produtos no sistema !!! " << endl;

            }
            else if(qtdProdutos == 1)
            {
                cout << endl;
                cout << "   (!) Existe apenas 1 produto no sistema !!!" << endl;

            }
            else
            {
                cout << endl;
                cout << "    (!) Existem " << qtdProdutos << " produtos no sistema !!!" << endl;

            };

}

ProdutoAV::ProdutoAV()
{
    emDestaque = false;
    this->g = new Genero();
    /*string s;

    cout << "Digite o nome do produto:" << endl;
    cin >> this->nome;
    cout << "Digite o genero do produto:" << endl;
    cin >> s;
    this->g = new Genero(s);
    cout << "Digite a classificacao indicativa do produto:" << endl;
    cin >> this->classificacaoIndicativa;
    cout << "Insira a url da imagem" << endl;
    cin >> this->urlImagem;
    cout << "Insira a url do trailer" << endl;
    cin >> this->urlTrailer;*/

}

ProdutoAV::ProdutoAV(string nome, int classificacaoIndicativa, string genero, string urlI,string urlT)
{

    this->nome = nome;
    this->classificacaoIndicativa = classificacaoIndicativa;
    emDestaque = false;
    this->g = new Genero(genero);
    this->urlImagem = urlI;
    this->urlTrailer = urlT;


}

void ProdutoAV::imprimeInfoProduto()
{

    cout << "    Nome do produto: "<< nome << endl;
    cout << "    Genero: " << g->getNome() << endl;
    cout << "    Classificacao indicativa: " << classificacaoIndicativa << endl;
}

string ProdutoAV::getNome()
{

    return this->nome;
}

void ProdutoAV::setNome(string nome)
{

    this->nome = nome;
}

ProdutoAV::Genero* ProdutoAV::getGenero()
{

    return this->g;

}

void ProdutoAV::setGenero(Genero* g)
{

    this->g = g;

}

int ProdutoAV::getClassificacaoIndicativa()
{

    return this->classificacaoIndicativa;
}

void ProdutoAV::setClassificacaoIndicativa(int classificacao)
{

    this->classificacaoIndicativa = classificacao;

}

bool ProdutoAV::getEmDestaque()
{

    return this->emDestaque;

}

void ProdutoAV::setEmDestaque(bool EmDestaque)
{

    this->emDestaque = EmDestaque;

}

ProdutoAV::Genero::Genero() {}

ProdutoAV::Genero::Genero(string nome)
{

    this->nome=nome;

}

string ProdutoAV::Genero::getNome()
{

    return this-> nome;

}

void ProdutoAV::Genero::setNome(string nome)
{

    this->nome = nome;

}

string ProdutoAV::getUrlImagem()
{

    return this->urlImagem;

}

string ProdutoAV::getUrlTrailer()
{

    return this->urlTrailer;

}

void ProdutoAV::setUrlImagem( string url)
{

    this->urlImagem=url;

}

void ProdutoAV::setUrlTrailer(string url)
{


    this->urlTrailer=url;

}
