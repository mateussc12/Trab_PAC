#include <stdlib.h>
#include <unistd.h>
//#include <windows.h>

#include "Produtor.h"
#include "Plataforma.h"

using namespace std;

void Menu( string plat)
{

    system("cls||clear");
    cout << endl;
    cout << "     -----------------------------------------------------------------  " << endl;
    cout << "                               " << plat << "                                " << endl;
    cout << "   | ----------------------------------------------------------------- | " << endl;
    cout << "   | 1.  Criar Produto (PRODUTOR)                                      |" << endl;
    cout << "   | 2.  Imprimir Produtos Desenvolvidos (PRODUTOR)                    |" << endl;
    cout << "   | 3.  Inserir Assinante (PLATAFORMA)                                |" << endl;
    cout << "   | 4.  Remover Assinante (PLATAFORMA)                                |" << endl;
    cout << "   | 5.  Imprimir Assinantes (PLATAFORMA)                              |" << endl;
    cout << "   | 6.  Inserir Produto (PLATAFORMA)                                  |" << endl;
    cout << "   | 7.  Colocar Produto em Destaque (PLATAFORMA)                      |" << endl;
    cout << "   | 8.  Remover Produto do Destaque (PLATAFORMA)                      |" << endl;
    cout << "   | 9.  Imprimir Produtos Cadastrados (PLATAFORMA)                    |" << endl;
    cout << "   | 10. Imprimir Produtos em Destaque (PLATAFORMA)                    |" << endl;
    cout << "   | 11. Imprimir Produtos Originais (PLATAFORMA)                      |" << endl;
    cout << "   | 12. Imprimir Produtos Cadastrados por Genero (PLATAFORMA)         |" << endl;
    cout << "   | 13. Imprimir Produtos Favoritos (ASSINANTE)                       |" << endl;
    cout << "   | 14. Inserir Produto aos Favoritos (ASSINANTE)                     |" << endl;
    cout << "   | 15. Remover Produto dos Favoritos (ASSINANTE)                     |" << endl;
    cout << "   | 16. Imprimir quantidade de produtos cadastrados geral (SISTEMA)   |" << endl;
    cout << "   | 17. Salvar Dados (SISTEMA)                                        |" << endl;
    cout << "   | 18. Carregar Dados (SISTEMA)                                      |" << endl;
    cout << "   | 19. Exportar Biblioteca (PLATAFORMA)                              |" << endl;
    cout << "   | 20. Sair                                                          |" << endl;
    cout << "    ------------------------------------------------------------------- " << endl;
    cout << "   (?) Selecionar menu: ";

}

void Continua()
{

    string y;

    do
    {
        cout << endl << "   (?) Digite (c) ou (C) para continuar: ";
        cin >>y;
    }
    while(y != "c" && y != "C");

}

int SelecionaProdutor( vector <Produtor*> prod )
{

    int prod_esc,i;

    cout << endl;
    cout << "    +------------------------------+ " << endl;
    cout << "    |           PRODUTORES         |  " << endl;
    cout << "    +------------------------------+ " << endl;
    for(i=0; i < prod.size(); i++)
    {


        cout << "      " << i << ". " << prod[i]->nome << endl;


    };
    cout << "    +------------------------------+ " << endl;
    cout << "    (?) Escolha um produtor: ";
    do
    {

        cin >> prod_esc;
        if ( prod_esc >= prod.size()|| prod_esc < 0)
        {

            cout << "  (!) Digite uma opcao valida por favor!!!" << endl;

        };

    }
    while ( prod_esc >= prod.size() ||  prod_esc < 0);

    system("cls||clear");

    return(prod_esc);
}

void salvarDadosProdutores(vector <Produtor*> produtores)
{
int i;
    ofstream outfile;
    outfile.open("Produtores.txt");

    outfile << produtores.size() << endl;

    for( i=0; i<produtores.size(); i++)
    {
        produtores[i]->imprimeNoArquivo(outfile);

    };

    outfile.close();
    cout << " (!) Arquivo com os produtores foi criado com sucesso!" << endl;

}

void salvarDadosPlataforma(Plataforma *plataforma)
{

    ofstream outfile;
    outfile.open("Plataforma.txt");

    plataforma->imprimeNoArquivo(outfile);

    outfile.close();
    cout << " (!) Arquivo com a plataforma foi criado com sucesso!" << endl;

}

vector <Produtor*> carregarDadosProdutores(ifstream &arqProd)
{
    int qtdProd;
    vector <Produtor*> produtores;

    arqProd >> qtdProd;
    ProdutoAV::qtdProdutos = 0;
    for (int i=0; i<qtdProd; i++)
    {
        Produtor* prod;
        prod = new Produtor();
        prod->carregaArquivo(arqProd);
        produtores.push_back(prod);
    }
    arqProd.close();
    cout << " (!) Todos Produtores carregados com sucesso! " << endl;
    return(produtores);
}

Plataforma* carregarDadosPlataforma(ifstream &arqPlat)
{
    Plataforma* pla;
    pla = new Plataforma();
    pla->carregaArquivo(arqPlat);
    arqPlat.close();
    cout << " (!) A Plataforma foi carregada com sucesso !" << endl;

    return(pla);

}

int ProdutoAV::qtdProdutos = 0;

int main()
{

    int x, prod_esc, prod_sele;
    string gen_fil;
    ifstream outfileProdu;
    ifstream outfilePla;

    vector <Produtor*> prod;
    prod.push_back(new Produtor("Netflix"));
    prod.push_back(new Produtor("Marvel"));
    prod.push_back(new Produtor("Warner"));


    Plataforma* pla;
    pla = new Plataforma("Netflix");


    ifstream arqProd;
    arqProd.open("Produtores.txt", ios::in );

    do
    {

        Menu(pla->getNome());
        cin >> x;

        switch(x)
        {

        case 1:
            system("cls||clear");

            prod_esc = SelecionaProdutor( prod );

            prod[prod_esc]->criarProduto();
            if (pla->getNome() == prod[prod_esc]->getNome())
            {

                cout << endl << "   (!) Produto cadastrado nas lista de originais !!!" << endl;
            }

            break;

        case 2:
            system("cls||clear");

            prod_esc = SelecionaProdutor( prod );

            prod[prod_esc]->imprimeProdutosDesenvolvidos();

            break;

        case 3:
            system("cls||clear");

            pla->inserirAssinante();

            break;

        case 4:
            system("cls||clear");

            pla->removerAssinate();

            break;

        case 5:
            system("cls||clear");

            pla->imprimeAssinantes();

            break;

        case 6:
            system("cls||clear");

            prod_esc = SelecionaProdutor( prod );

            prod[prod_esc]->imprimeProdutosDesenvolvidos();

            if(!prod[prod_esc]->getProdutosDesenvolvidos().empty())
            {

                cout << "    (?) Digite a posicao do produto: ";
                cin >> prod_sele;

                pla->inserirProduto(prod[prod_esc]->getProdutosDesenvolvidos()[prod_sele], prod[prod_esc]->getNome());
            };

            break;

        case 7:
            system("cls||clear");

            pla->colocarProdutoDestaque();

            break;

        case 8:
            system("cls||clear");

            pla->removerProdutoDestaque();

            break;

        case 9:
            system("cls||clear");

            pla->imprimeProdutosCadastrados();

            break;

        case 10:
            system("cls||clear");

            pla->imprimeProdutosDestaque();

            break;

        case 11:
            system("cls||clear");

            pla->imprimeProdutosOriginais();

            break;

        case 12:
            system("cls||clear");
            cout << endl;
            cout << "    (?) Digite o genero pelo qual dejesa filtrar os produtos: ";
            cin >> gen_fil;

            pla->imprimeProdutos(gen_fil);

            break;

        case 13:
            system("cls||clear");

            int assi;

            assi = pla->selecionaAssinante();

            if(assi != -1)
            {

                pla->getAssinantes()[assi]->imprimeFavoritos();

            };

            break;

        case 14:
            system("cls||clear");

            pla->inserirProdutoAssinante();

            break;


        case 15:
            system("cls||clear");

            if(pla->getProdutosCadastrados().size() == 0)
            {

                cout << " (!) Nao existem produtos cadastrados  " << endl;

            }
            else
            {

                assi = pla->selecionaAssinante();

                if(assi != -1)
                {

                    pla->getAssinantes()[assi]->removerFavorito();

                };
            };

            break;

        case 16:
            system("cls||clear");

            ProdutoAV::imprimeQtdProdutos();

            break;

        case 17:
            system("cls||clear");

            salvarDadosProdutores(prod);

            salvarDadosPlataforma(pla);

            break;


        case 18:
            system("cls||clear");

            outfileProdu.open("Produtores.txt");

            if(!outfileProdu.is_open())
            {
                cout << "Erro ao abrir o arquivo" << endl;
                break;

            };

            outfilePla.open("Plataforma.txt");


            if(!outfilePla.is_open())
            {
                cout << "Erro ao abrir o arquivo" << endl;
                break;

            };

            prod.clear();
            delete pla;

            prod = carregarDadosProdutores(outfileProdu);
            pla = carregarDadosPlataforma(outfilePla);

            break;


        case 19:
            system("cls||clear");

            pla->exportarBiblioteca();

            break;


        case 20:

            delete pla;
            prod.clear();


            return (0);
            break;

        default:

            break;

        }

        Continua();

    }
    while(true);


    return(0);
}
