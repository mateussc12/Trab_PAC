#include "Assinante.h"

Assinante::Assinante() {};

Assinante::Assinante(string nome)
{

    this->nome = nome;

};

Assinante::~Assinante()
{

    cout << endl;
    cout << "Assinante apagado." << endl;

};

void Assinante::imprimeFavoritos()
{

    int i;

    if(favoritos.size() == 0)
    {

        cout << "    (!) Nao existem produtos favoritados !!! " << endl;
    }
    else
    {
        cout << endl;
        cout << "    +-------------------------------+ " << endl;
        cout << "    |       LISTA DE FAVORITOS      |  " << endl;
        cout << "    +-------------------------------+ " << endl;
        for (i=0; i<favoritos.size(); i++)
        {

            cout << "    -------------------------------------" << endl;
            cout << "    Produto " << i << endl;
            favoritos[i]->imprimeInfoProduto();

        };
    };
};

void Assinante::inserirFavorito(ProdutoAV* favorito)
{

    int i;
    bool b = true;

    for(i=0; i < favoritos.size(); i++)
    {

        if(favorito->getNome() == favoritos[i]->getNome())
        {
            cout << "    (!) Produto ja esta favoritado !!! "<< endl;
            b = false;
            break;

        };
    };

    if(b == true)
    {

        this->favoritos.push_back(favorito);
        cout << endl;
        cout << "    (!) Produto inserido na lista de favoritos " << endl;

    };
};

void Assinante::removerFavorito()
{

    int prod_sele;

    imprimeFavoritos();

    if(getFavoritos().size() != 0)
    {

        cout << endl;
        cout << "    (?) Selecione a posicao do produto que voce dejesa remover da lista ";

        do
        {

            cin >> prod_sele;
            if( prod_sele < 0 || prod_sele >= favoritos.size() )
            {

                cout << "    (!) Por favor, selecione uma opcao valida !!! " << endl;

            };

        }
        while( prod_sele < 0 || prod_sele >= favoritos.size() );

        favoritos.erase(favoritos.begin() + prod_sele);

        cout << endl;
        cout << "    (!) O produto foi removido da lista de favoritos !!!" << endl;

    };
}

string Assinante::getNome()
{

    return this->nome;

}

void Assinante::setNome(string nome)
{

    this->nome = nome;

}

vector <ProdutoAV*> Assinante::getFavoritos()
{

    return this->favoritos;

}

void Assinante::imprimeNoArquivo(ofstream &outfile)
{
    int i;
    outfile << this->nome << endl;
    outfile << this->favoritos.size() << endl;
    for(i=0; i<favoritos.size(); i++)
    {
        this->favoritos[i]->imprimeNoArquivo(outfile);
    }
}

void Assinante::carregaArquivo(ifstream &infile)
{
    string tipo;
    int qtd;
    infile.ignore(1, '\n');
    getline(infile, this->nome);
    infile >> qtd;
    for(int i=0; i < qtd; i++)
    {
        infile >> tipo;
        if(tipo=="Filme")
        {
            Filme *f;
            f = new Filme();
            f->carregaArquivo(infile);
            this->favoritos.push_back(f);
        }
        else
        {
            Serie *s;
            s = new Serie();
            s->carregaArquivo(infile);
            this->favoritos.push_back(s);

        }
    }

}
