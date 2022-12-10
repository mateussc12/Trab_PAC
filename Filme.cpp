#include "Filme.h"

Filme::Filme():ProdutoAV() {}

Filme::Filme(string nome, int clas, string gen,string urli, string urlt, float duracao, int ano): ProdutoAV(nome, clas, gen, urli, urlt)
{

    this->duracao = duracao;
    this->anoLancamento = ano;

}

void Filme::formataDuracao()
{

    int minutos,horas;

    minutos = getDuracao();
    horas = minutos/60;
    minutos = minutos % 60;
    if( minutos%60 == 0)
    {
        cout << "    Tempo de duracao: " << horas << " horas" << endl;
    }
    else if(horas == 0)
    {
        cout << "    Tempo de duracao: " << minutos << " minutos" << endl;
    }
    else
    {
        cout << "    Tempo de duracao: " << horas << " horas e  " << minutos << " minutos" << endl;
    }
}

int Filme::getDuracao()
{

    return this->duracao;

}

void Filme::setDuracao(int duracao)
{

    this->duracao = duracao;

}

int Filme::getAnoLancamento()
{

    return this->anoLancamento;

}

void Filme::setAnoLancamento(int anoLancamento)
{

    this->anoLancamento = anoLancamento;

}

void Filme::imprimeInfoProduto()
{

    cout << "    Nome do filme: "<< this->nome << endl;
    cout << "    Genero: " << this->g->getNome() << endl;
    cout << "    Classificacao indicativa: " << this->classificacaoIndicativa << endl;
    formataDuracao();
    cout << "    Ano de lancamento: " << getAnoLancamento() << endl;

}

void Filme::imprimeNoArquivo(ofstream &outfile)
{
    outfile << "Filme" << endl;
    outfile << this->nome << endl;
    outfile << this->g->getNome() << endl;
    outfile << this->classificacaoIndicativa << endl;
    outfile << this->urlImagem << endl;
    outfile << this->urlTrailer << endl;
    outfile << this->emDestaque << endl;
    outfile << this->duracao << endl;
    outfile << this->anoLancamento << endl;
}

void Filme::carregaArquivo(ifstream &infile)
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
    infile >> this->duracao;
    infile >> this->anoLancamento;

}
