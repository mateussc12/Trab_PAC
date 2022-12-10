#include "Serie.h"

#include "Temporada.h"

void Serie::cadastrarTemporada(int num)
{

    Temporada* t;
    int qtdEps, duracaoMediaEps, ano;

    cout <<endl;
    cout << "    ------------------ " << " TEMPORADA " << num << " --------------------- " << endl;
    cout << "    Digite o numero de episodios da temporada: ";
    cin >> qtdEps;
    cout << "    Digite a duracao media dos episodios(em minutos): ";
    cin >> duracaoMediaEps;
    cout << "    Digite o ano de lancamento da temporada: ";
    cin >> ano;

    t = new Temporada(num, qtdEps, duracaoMediaEps, ano);
    Temporadas.push_back(t);

}

Serie::Serie():ProdutoAV() {}

Serie::Serie(string nome, int clas, string gen, string urli, string urlt, int qtdTemp): ProdutoAV(nome, clas, gen, urli, urlt)
{

    this->qtdTemporadas = qtdTemp;
    int i;

    for(i=1 ; i<=qtdTemp; i++)
    {

        cadastrarTemporada(i);

    };
}

int Serie::getQtdTemporadas()
{

    return this->qtdTemporadas;

}

void Serie::setQtdTemporadas(int qtdTemporadas)
{

    this->qtdTemporadas = qtdTemporadas;

}

vector <Temporada*> Serie::getTemporadas()
{

    return this->Temporadas;

}

void Serie::imprimirTemporadas()
{

    int i;

    if(getTemporadas().size() == 0)
    {

        cout << "    (!) Nao existem temporadas cadastradas !!!" << endl;
    }
    else
    {

        cout << endl;
        cout << "    +------------------------------+ " << endl;
        cout << "    |      LISTA DE TEMPORADAS     |  " << endl;
        cout << "    +------------------------------+ " << endl;
        for (i = 0; i < getTemporadas().size(); i++)
        {


            cout << "    Temporada: " << i+1 << endl;
            Temporadas[i]->imprimeInfoTemporada();
            cout << "    ------------------------------------- " << endl;
        };
    };
}

void Serie::imprimeInfoProduto()
{

    cout << "    Nome da serie: "<< this->nome << endl;
    cout << "    Genero: " << this->g->getNome() << endl;
    cout << "    Classificacao indicativa: " << this->classificacaoIndicativa << endl;
    cout << "    Numero de temporadas da serie: " << this->getQtdTemporadas() << endl;
    this->imprimirTemporadas();
    cout << endl;

}

void Serie::imprimeNoArquivo(ofstream &outfile)
{
    outfile << "Serie" << endl;
    outfile << this->nome << endl;
    outfile << this->g->getNome() << endl;
    outfile << this->classificacaoIndicativa << endl;
    outfile << this->urlImagem << endl;
    outfile << this->urlTrailer << endl;
    outfile << this->emDestaque << endl;
    outfile << this->qtdTemporadas << endl;
    int i;
    for(i=0; i<Temporadas.size(); i++)
    {
        this->Temporadas[i]->imprimeNoArquivo(outfile);
    }
}

void Serie::carregaArquivo(ifstream &infile)
{
    string g;
    infile.ignore();
    getline(infile, this->nome);
    getline(infile, g);
    this->g->setNome(g);
    infile >> this->classificacaoIndicativa;
    infile.ignore();
    getline(infile, this->urlImagem);
    getline(infile,this->urlTrailer);
    infile >> this->emDestaque;
    infile >> this->qtdTemporadas;
    for(int i=0; i < this->qtdTemporadas; i++)
    {
        Temporada *t;
        t = new Temporada();
        t->carregaArquivo(infile);
        this->Temporadas.push_back(t);
    }
}
