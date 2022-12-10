#include "Produtor.h"

Produtor::Produtor() {}

Produtor::Produtor(string nome)
{

    this->nome=nome;

}

void Produtor::criarProduto()
{

    string nomeP, genero, urlI, urlT;
    int classificacao, i, duracaof, anof, qtdtemps;

    cout << endl;
    cout << "    +------------------------------+ " << endl;
    cout << "    |         CRIAR PRODUTO        |  " << endl;
    cout << "    +------------------------------+ " << endl;
    cout << "     1. Filme " << endl;
    cout << "     2. Serie " << endl;
    cout << "    +------------------------------+ " << endl;
    cout << "    (?) Criar um filme ou serie: ";
    do
    {

        cin >> i;
        if (i != 1 && i != 2)
        {

            cout << " (!) Digite uma opcao valida por favor!!!" << endl;


        };
        cout << endl;

    }
    while(i != 1 && i != 2);

    system("cls||clear");

    if(i == 1)
    {

        cout << endl;
        cout << "    +------------------------------+ " << endl;
        cout << "    |         CRIAR FILME          |  " << endl;
        cout << "    +------------------------------+ " << endl;

    }
    else
    {

        cout << endl;
        cout << "    +------------------------------+ " << endl;
        cout << "    |         CRIAR SERIE          |  " << endl;
        cout << "    +------------------------------+ " << endl;
    };

    cout << "    Digite as informacoes sobre o produto" << endl << endl;
    cout << "    Nome do produto: ";
    cin  >> nomeP;
    cout << "    Classificacao indicativa: ";
    cin >> classificacao;
    cout << "    Genero: ";
    cin >> genero;
    cout << "    Url Imagem: ";
    cin >> urlI;
    cout << "    Url Trailer: ";
    cin >> urlT;

    ProdutoAV *pav;

    if(i == 1)
    {

        cout << "    Duracao do filme(em minutos): ";
        cin  >> duracaof;
        cout << "    Ano de lancamento: ";
        cin >> anof;

        pav = new Filme(nomeP, classificacao, genero, urlI, urlT, duracaof, anof);
        produtosDesenvolvidos.push_back(pav);

    }
    if(i == 2)
    {

        cout << "    Quantidade de temporadas: ";
        cin  >> qtdtemps;

        pav = new Serie(nomeP, classificacao, genero, urlI, urlT, qtdtemps);
        produtosDesenvolvidos.push_back(pav);

    }

    cout << endl;
    cout << "    (!) O produto foi criado com sucesso." << endl;

    ProdutoAV::qtdProdutos++;

}

void Produtor::imprimeProdutosDesenvolvidos()
{

    int i;

    if(produtosDesenvolvidos.size() == 0)
    {
        cout << endl;
        cout << endl;
        cout << "   (!) Nao existem produtos deste produtor no sistema !!!" << endl;
    }
    else
    {
        cout << endl;
        cout << "    +------------------------------+ " << endl;
        cout << "    |       LISTA DE PRODUTOS      |  " << endl;
        cout << "    +------------------------------+ " << endl;
        for (i=0; i < produtosDesenvolvidos.size(); i++)
        {


            cout << "                PRODUTO " << i << endl;
            produtosDesenvolvidos [i]->imprimeInfoProduto();
            cout << "    -------------------------------- " << endl;


        };
    };

}

string Produtor::getNome()
{

    return this->nome;

}

void Produtor::setNome(string nome)
{

    this->nome = nome;

}

vector <ProdutoAV*> Produtor::getProdutosDesenvolvidos()
{

    return this->produtosDesenvolvidos;

}

void Produtor::imprimeNoArquivo(ofstream &outfile)
{
    int i;

    outfile << this->nome << endl;
    outfile << this->produtosDesenvolvidos.size() << endl;
    for(i=0; i<produtosDesenvolvidos.size(); i++)
    {
        this->produtosDesenvolvidos[i]->imprimeNoArquivo(outfile);
    }

    cout << " (!) Produtor " << this->nome << " salvo com sucesso!" << endl;
}

void Produtor::carregaArquivo(ifstream &infile)
{
    string tipo;
    int qtd, i;
    infile.ignore(1, '\n');
    getline(infile, this->nome);
    infile >> qtd;

    for(i=0; i < qtd; i++)
    {
        infile >> tipo;
        if(tipo=="Filme")
        {
            Filme *f;
            f = new Filme();
            f->carregaArquivo(infile);
            this->produtosDesenvolvidos.push_back(f);
        }
        else
        {
            Serie *s;
            s = new Serie();
            s->carregaArquivo(infile);
            this->produtosDesenvolvidos.push_back(s);
        }
    }

    ProdutoAV::qtdProdutos += qtd;
    cout << " (!) Produtor " << this->nome << " carregado com sucesso!" << endl;

}
