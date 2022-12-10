#include "Plataforma.h"

Plataforma::Plataforma() {}

Plataforma::Plataforma(string nome)
{

    this->nome = nome;

}

void Plataforma::imprimeProdutosCadastrados()
{

    int i;

    if(produtosCadastrados.size() == 0)
    {

        cout << "    (!) Nao existem produtos cadastrados !!!" << endl;
    }
    else
    {

        cout << endl;
        cout << "    +-------------------------------+ " << endl;
        cout << "    | LISTA DE PRODUTOS CADASTRADOS |  " << endl;
        cout << "    +-------------------------------+ " << endl;
        for (i=0; i<produtosCadastrados.size(); i++)
        {

            cout << "    ------------------------------------" << endl;
            cout << "    Produto " << i << endl;
            cout << "    Produzido por: " << this->nome << endl;
            produtosCadastrados[i]->imprimeInfoProduto();
        };
    };

}

void Plataforma::imprimeProdutosDestaque()
{

    int i, c=0;

    if(produtosCadastrados.size() == 0)
    {

        cout << "    (!) Nao existem produtos em destaque !!! " << endl;

    }
    else
    {

        cout << endl;
        cout << "    +-------------------------------+ " << endl;
        cout << "    | LISTA DE PRODUTOS EM DESTAQUE |  " << endl;
        cout << "    +-------------------------------+ " << endl;
        for (i=0; i<produtosCadastrados.size(); i++)
        {

            if(produtosCadastrados[i]->getEmDestaque() == true)
            {
                c++;
                cout << "    ------------------------------------" << endl;
                cout << "    Produto " << i << endl;
                produtosCadastrados[i]->imprimeInfoProduto();

            };
        };

        if(c==0)
        {
            cout << "    (!) Nao existem produtos em destaque " << endl;

        }
    };

}

void Plataforma::imprimeProdutosOriginais()
{

    int i;

    if(produtosOriginais.size() == 0)
    {

        cout << "    (!) Nao existem produtos originais cadastrados !!! " << endl;
    }
    else
    {

        cout << endl;
        cout << "    +-------------------------------+ " << endl;
        cout << "    |  LISTA DE PRODUTOS ORIGINAIS  |  " << endl;
        cout << "    +-------------------------------+ " << endl;
        for (i=0; i<produtosOriginais.size(); i++)
        {

            cout << "    ------------------------------------" << endl;
            cout << "    Produto " << i << endl;
            produtosOriginais[i]->imprimeInfoProduto();
        };
    };

}


void Plataforma::imprimeProdutos(string genero)
{

    int i;

    if(produtosCadastrados.size() == 0)
    {

        cout << "    (!) Nao existem produtos cadastrados por este genero !!! " << endl;
    }
    else
    {

        cout << endl;
        for (i=0; i<produtosCadastrados.size(); i++)
        {

            if(produtosCadastrados[i]->getGenero()->getNome() == genero)
            {

                cout << "    -------------------------------- " << endl;
                produtosCadastrados[i]->imprimeInfoProduto();

            }
            else
            {

                cout << "    (!) Nao existem produtos cadastrados por este genero !!! " << endl;

            };
        };
    };

}
void Plataforma::imprimeAssinantes()
{

    int i;

    if(assinantes.size() == 0)
    {

        cout << endl << "    (!) Nao existem assinantes cadastrados no sistema !!! " << endl;

    }
    else
    {
        cout << endl;
        cout << "    +---------------------------------------------------+ " << endl;
        cout << "    |                     ASSINANTES                    |  " << endl;
        cout << "    +---------------------------------------------------+ " << endl;
        for (i=0; i<assinantes.size(); i++)
        {


            cout <<"    " << i << " - " << assinantes[i]->getNome()<< endl;
            cout << "    ----------------------------------------------------- " << endl;
        };
    };

}

void Plataforma::inserirAssinante()
{

    Assinante* ass;
    string nome;
    cout << endl;
    cout << "    +---------------------------------------------------+ " << endl;
    cout << "    |                  INSERIR ASSINANTE                |  " << endl;
    cout << "    +---------------------------------------------------+ " << endl;
    cout << "   (?) Digite o nome pelo qual gostaria de ser chamado: ";
    cin >> nome;

    ass = new Assinante(nome);
    assinantes.push_back(ass);

    cout << endl;
    cout << "   (!) Assinante inserido com sucesso !!!" << endl;

}

void Plataforma::removerAssinate()
{

    int x;

    this->imprimeAssinantes();
    cout << endl;
    if(assinantes.size() > 0 )
    {

        cout << "   (?) Selecione o assinante que voce dejesa remover: ";

        do
        {

            cin >> x;
            if (assinantes.size() <= x || x<0)
            {

                cout << "    (!) Digite uma posicao valida por favor !!! " << endl;

            };

        }
        while (assinantes.size() <= x || x<0);

        assinantes.erase(assinantes.begin() + x);
        cout << endl << "   (!) Assinante removido com sucesso !!!" << endl;
    };
}

int Plataforma::inserirProduto(ProdutoAV* novoProduto, string nomeProdutor)
{

    int i;

    for(i = 0; i < produtosCadastrados.size(); i++)
    {

        if(novoProduto->getNome() == produtosCadastrados[i]->getNome())
        {

            cout << "    (!) Este produto ja foi cadastrado" << endl;
            return (0);

        };
    };

    produtosCadastrados.push_back(novoProduto);

    if(nomeProdutor == this->nome)
    {

        produtosOriginais.push_back(novoProduto);

    };
    cout << endl;
    cout << "    (!) Produto inserido com sucesso !!! " << endl;

}

void Plataforma::colocarProdutoDestaque()
{

    int i, prod_sele,cont=0;
    for(i = 0; i < produtosCadastrados.size(); i++)
    {

        if(produtosCadastrados[i]->getEmDestaque() == false)
        {
            cout << endl;
            cout << "    --------------------------------------" << endl;
            cout << "    PRODUTO " << i << endl;
            cout << "    Nome: " << produtosCadastrados[i]->getNome() << endl;

        };

        if(produtosCadastrados[i]->getEmDestaque() == true)
        {

            cont++;

        };

    }

    if(cont == produtosCadastrados.size())
    {

        if(cont == 0)
        {

            cout << "    (!) Nao existem produtos cadastrados !!! " << endl;

        }
        else
        {

            cout << "    (!) Todos os produtos cadastrados ja estao em Destaque !!!" << endl;

        };

    }
    else
    {

        cout << endl << "    (?) Digite a posicao do produto que voce dejesa colocar em destaque: ";
        do
        {
            cin >> prod_sele;
            if( prod_sele < 0 )
            {
                cout << "    (!) Digite uma posicao valida !!!" << endl;
            }
        }
        while (prod_sele < 0);
        produtosCadastrados[prod_sele]->setEmDestaque(true);

        cout << endl;
        cout << "    (!) O produto esta em destaque !!!" << endl;

    };
}

void Plataforma::removerProdutoDestaque()
{

    int i, prod_sele,cont=0;
    for(i = 0; i < produtosCadastrados.size(); i++)
    {

        if(produtosCadastrados[i]->getEmDestaque() == true)
        {
            cout << endl;
            cout << "    --------------------------------------" << endl;
            cout << "    PRODUTO " << i << endl;
            cout << "    Nome: " << produtosCadastrados[i]->getNome() << endl;
        }

        if(produtosCadastrados[i]->getEmDestaque() == false)
        {

            cont++;

        };


    }

    if(cont == produtosCadastrados.size())
    {

        cout << "    (!) Nenhum produto cadastrado esta em Destaque !!!" << endl;

    }
    else
    {

        cout << endl << "    (?) Digite a posicao do produto que voce dejesa remover do destaque: ";
        do
        {
            cin >> prod_sele;
            if( prod_sele < 0 )
            {
                cout << "    (!) Digite uma posicao valida !!!" << endl;
            }
        }
        while (prod_sele < 0);

        produtosCadastrados[prod_sele]->setEmDestaque(false);

        cout << endl;
        cout << "    (!) O produto nao esta mais em destaque !!!" << endl;

    };
}

int Plataforma::selecionaAssinante()
{

    int assi_sele;

    if(assinantes.size() == 0)
    {
        cout << endl;
        cout << "    (!) Nao existem assinantes cadastrados !!!" << endl;
        return (-1);

    }
    else
    {

        this->imprimeAssinantes();
        cout << endl << "    (?) Digite a posicao do assinante que voce dejesa selecionar: ";

        do
        {
            cin >> assi_sele;
            if (assi_sele >= assinantes.size() || assi_sele<0)
            {

                cout << "    (!) Digite uma posicao valida por favor !!!" << endl;

            };

        }
        while (assi_sele >= assinantes.size() || assi_sele<0);

        cout << endl;
        cout << "    (!) Assinante selecionado " << endl << endl;
        return (assi_sele);

    };


}

void Plataforma::inserirProdutoAssinante()
{

    if(produtosCadastrados.size() == 0)
    {

        cout << "    (!) Nao existem produtos cadastrados" << endl;

    }
    else if(getAssinantes().size() == 0 )
    {

        cout << "    (!) Nao existem assinantes cadastrados" << endl;

    }
    else
    {

        int assi_sele, prod_sele;

        assi_sele = this->selecionaAssinante();

        this->imprimeProdutosCadastrados();
        cout << endl << "    (?) Digite a posicao do produto que voce dejesa selecionar: ";

        do
        {
            cin >> prod_sele;
        }
        while(prod_sele < 0 || prod_sele > produtosCadastrados.size());

        this->assinantes[assi_sele]->inserirFavorito(this->produtosCadastrados[prod_sele]);


    };
}

string Plataforma::getNome()
{

    return this->nome;

}

void Plataforma::setNome(string nome)
{

    this->nome = nome;

}

vector <ProdutoAV*> Plataforma::getProdutosCadastrados()
{

    return this->produtosCadastrados;

}

vector <ProdutoAV*> Plataforma::getProdutosOriginais()
{

    return this->produtosOriginais;

}

vector <Assinante*> Plataforma::getAssinantes()
{

    return this->assinantes;

}

void Plataforma::imprimeNoArquivo(ofstream &outfile)
{
    int i;
    outfile << this->nome << endl;
    outfile << this->produtosCadastrados.size() << endl;
    for(i=0; i<produtosCadastrados.size(); i++)
    {
        this->produtosCadastrados[i]->imprimeNoArquivo(outfile);
    }

    outfile << this->produtosOriginais.size() << endl;
    for(i=0; i<produtosOriginais.size(); i++)
    {
        this->produtosOriginais[i]->imprimeNoArquivo(outfile);
    }

    outfile << this->assinantes.size() << endl;
    for(i=0; i<assinantes.size(); i++)
    {
        this->assinantes[i]->imprimeNoArquivo(outfile);
    }

    cout << " (!) Plataforma " << this->nome << " salva com sucesso!" << endl;

}

void Plataforma::carregaArquivo(ifstream &infile)
{

    string tipo;
    int qtd,i;

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
            this->produtosCadastrados.push_back(f);
        }
        else
        {
            Serie *s;
            s = new Serie();
            s->carregaArquivo(infile);
            this->produtosCadastrados.push_back(s);
        }
    }

    infile >> qtd;
    for(i=0; i < qtd; i++)
    {
        infile >> tipo;
        if(tipo=="Filme")
        {
            Filme *f;
            f = new Filme();
            f->carregaArquivo(infile);
            this->produtosOriginais.push_back(f);
        }
        else
        {
            Serie *s;
            s = new Serie();
            s->carregaArquivo(infile);
            this->produtosOriginais.push_back(s);

        }
    }

    infile >> qtd;
    for(int i=0; i < qtd; i++)
    {
        Assinante *a;
        a = new Assinante();
        a->carregaArquivo(infile);
        this->assinantes.push_back(a);
    }

    cout << " (!) Plataforma " << this->nome << " carregada com sucesso!" << endl;

}

void Plataforma::exportarBiblioteca()
{

    ofstream outfile;
    outfile.open("Netflix.html");


    outfile << "<html>" << endl;
    outfile << "<head> " << endl;
    outfile << "<meta charset=\"UTF-8\">" << endl;
    outfile << "<style>" << endl;
    outfile << "body {" << endl;
    outfile << "background-color: black;" << endl;
    outfile << "font-family: 'Roboto', sans-serif;" << endl;
    outfile << "}" << endl;
    outfile << "img {" << endl;
    outfile << "margin: auto;" << endl;
    outfile << "}" << endl;
    outfile << "h2 {" << endl;
    outfile << "margin: 30px auto;" << endl;
    outfile << "color: white;" << endl;
    outfile << "}" << endl;
    outfile << "h3 {" << endl;
    outfile << "float: left;" << endl;
    outfile << "color: white;" << endl;
    outfile << "}" << endl;
    outfile << "h4 {" << endl;
    outfile << "color:#333;" << endl;
    outfile << "margin: 5px;" << endl;
    outfile << "}" << endl;
    outfile << "label {" << endl;
    outfile << "color:white;" << endl;
    outfile << "margin: 20px auto;" << endl;
    outfile << "font-style:italic;" << endl;
    outfile << "text-decoration: underline;" << endl;
    outfile << "}" << endl;
    outfile << "#filmes img {" << endl;
    outfile << "height: 250px;" << endl;
    outfile << "width: 200px;" << endl;
    outfile << "}" << endl;
    outfile << "#filmes {" << endl;
    outfile << "text-align: center;" << endl;
    outfile << "}" << endl;
    outfile << ".row {" << endl;
    outfile << "width: 100%;" << endl;
    outfile << "display: flex;" << endl;
    outfile << "flex-wrap: wrap;" << endl;
    outfile << "margin-left: -15px;" << endl;
    outfile << "margin-right: -15px;" << endl;
    outfile << "}" << endl;
    outfile << ".card {" << endl;
    outfile << "border: 1px solid red;" << endl;
    outfile << "}" << endl;
    outfile << ".col-item {" << endl;
    outfile << "padding-left: 15px;" << endl;
    outfile << "padding-right: 15px;" << endl;
    outfile << "}" << endl;
    outfile << ".col-12 {" << endl;
    outfile << "width: 100%;" << endl;
    outfile << "padding-left: 15px;" << endl;
    outfile << "padding-right: 15px;" << endl;
    outfile << "}" << endl;
    outfile << ".item {" << endl;
    outfile << "padding: 0 20px 30px 20px;" << endl;
    outfile << "}" << endl;
    outfile << ".item .bg-img {" << endl;
    outfile << "background-position: center;" << endl;
    outfile << "background-size: cover;" << endl;
    outfile << "background-repeat: no-repeat;" << endl;
    outfile << "}" << endl;
    outfile << ".item .bg-img img {" << endl;
    outfile << "border-top-left-radius: 10px;" << endl;
    outfile << "border-top-right-radius: 10px;" << endl;
    outfile << "cursor: pointer;" << endl;
    outfile << "box-shadow: 0px -3px 15px 3px rgb(75, 75, 75);" << endl;
    outfile << "-webkit-box-shadow: 0px -3px 15px 3px rgb(75, 75, 75);" << endl;
    outfile << "border-radius: 0px -3px 15px 3px rgb(75, 75, 75);" << endl;
    outfile << "-moz-border-radius: 0px -3px 15px 3px rgb(75, 75, 75);" << endl;
    outfile << "margin-top: 20px;" << endl;
    outfile << "}" << endl;
    outfile << ".item .info {" << endl;
    outfile << "background-color: rgb(241, 241, 241);" << endl;
    outfile << "padding: 20px 0px 10px 10px;" << endl;
    outfile << "height: 80px;" << endl;
    outfile << "text-align: center;" << endl;
    outfile << "font-family: 'OpenSansBold';" << endl;
    outfile << "cursor: pointer;" << endl;
    outfile << "box-shadow: 0px 2px 15px 6px rgb(75, 75, 75);" << endl;
    outfile << "-webkit-box-shadow: 0px 2px 15px 6px rgb(75, 75, 75);" << endl;
    outfile << "border-radius: 0px 2px 15px 6px rgb(75, 75, 75);" << endl;
    outfile << "-moz-border-radius: 0px 2px 15px 6px rgb(75, 75, 75);" << endl;
    outfile << "border-top: none;" << endl;
    outfile << "border-bottom-left-radius: 10px;" << endl;
    outfile << "border-bottom-right-radius: 10px;" << endl;
    outfile << "}" << endl;
    outfile << "@media (min-width:1351px) {" << endl;
    outfile << ".col-item {" << endl;
    outfile << "width: calc(20% - 40px);" << endl;
    outfile << "}" << endl;
    outfile << "}" << endl;
    outfile << "@media (min-width:1101px) and (max-width: 1350px) {" << endl;
    outfile << ".col-item {" << endl;
    outfile << "width: calc(25% - 40px);" << endl;
    outfile << "}" << endl;
    outfile << "}" << endl;
    outfile << "@media (min-width:901px) and (max-width: 1100px) {" << endl;
    outfile << ".col-item {" << endl;
    outfile << "width: calc(33% - 40px);" << endl;
    outfile << "}" << endl;
    outfile << "}" << endl;
    outfile << "@media (min-width:601px) and (max-width: 900px) {" << endl;
    outfile << ".col-item {" << endl;
    outfile << "width: calc(50% - 40px);" << endl;
    outfile << "}" << endl;
    outfile << "}" << endl;
    outfile << "@media (max-width: 600px) {" << endl;
    outfile << ".col-item {" << endl;
    outfile << "width: 100%;" << endl;
    outfile << "}" << endl;
    outfile << ".img-logo {" << endl;
    outfile << "width: 200px;" << endl;
    outfile << "height: 100px;" << endl;
    outfile << "}" << endl;
    outfile << "}" << endl;
    outfile << "</style>" << endl;

    outfile << "<title>Netflix</title>" << endl;
    outfile << "</head>" << endl;
    outfile << "<body>" << endl;
    outfile << "<div style=\"margin: 0 30px;\">" << endl;
    outfile << "<div class=\"row\">" << endl;
    outfile << "<img width=\"300\" height=\"150\" src=\"https://pmcvariety.files.wordpress.com/2017/07/netflix-logo.jpg?w=732&h=412&crop=1\"/>" << endl;
    outfile << "</div>" << endl;
    outfile << "<div id=\"filmes\" class=\"row\">" << endl;
    outfile << "<div class=\"col-12\">" << endl;


    outfile << "<h2>PRODUTOS</h2>" << endl;
    outfile << "</div>" << endl;


    if(!this->produtosCadastrados.empty())
    {
                outfile << "<div class=\"col-12\">" << endl;
                outfile << "<h3>Em Destaque</h3>" << endl;
                outfile << "</div>" << endl;

        for(int i=0; i<this->produtosCadastrados.size(); i++)
        {
            if(produtosCadastrados[i]->getEmDestaque() == true)
            {

                outfile << "<div class=\"col-item item\">" << endl;
                outfile << "<a target=\"_blank\" href=\"" << this->produtosCadastrados[i]->getUrlTrailer() << "\">" << endl;
                outfile << "<div class=\"bg-img\">" << endl;
                outfile << "<img src=\"" << this->produtosCadastrados[i]->getUrlImagem() << "\" style=\"width: 100%;\" />" << endl;
                outfile << "</div>" << endl;
                outfile << "<div class=\"info\">" << endl;
                outfile << "<h4>"<< produtosCadastrados[i]->getNome() << "</label>" << endl;
                outfile << "<h4>"<< produtosCadastrados[i]->getGenero()->getNome() << "</label>" << endl;
                outfile << "<h4>"<< produtosCadastrados[i]->getClassificacaoIndicativa() << "</label>" << endl;
                outfile << "</div>" << endl;
                outfile << "</a>" << endl;
                outfile << "</div>" << endl;
            };

        }
        outfile << "<div class=\"col-12\">" << endl;
        outfile << "<h3>Produtos Cadastrados</h3>" << endl;
        outfile << "</div>" << endl;


        for(int i=0; i<this->produtosCadastrados.size(); i++)
        {
            outfile << "<div class=\"col-item item\">" << endl;
            outfile << "<a target=\"_blank\" href=\"" << this->produtosCadastrados[i]->getUrlTrailer() << "\">" << endl;
            outfile << "<div class=\"bg-img\">" << endl;
            outfile << "<img src=\"" << this->produtosCadastrados[i]->getUrlImagem() << "\" style=\"width: 100%;\" />" << endl;
            outfile << "</div>" << endl;
            outfile << "<div class=\"info\">" << endl;
            outfile << "<h4>"<< produtosCadastrados[i]->getNome() << "</label>" << endl;
            outfile << "<h4>"<< produtosCadastrados[i]->getGenero()->getNome() << "</label>" << endl;
            outfile << "<h4>"<< produtosCadastrados[i]->getClassificacaoIndicativa() << "</label>" << endl;
            outfile << "</div>" << endl;
            outfile << "</a>" << endl;
            outfile << "</div>" << endl;
        }


        outfile << "<div class=\"col-12\">" << endl;
        outfile << "<h3>Originais</h3>" << endl;
        outfile << "</div>" << endl;

        for(int i=0; i<this->produtosOriginais.size(); i++)
        {

            if(produtosOriginais.size() == 0)
            {

                outfile << "<label> Nenhum Produto Original!</label>\n";
            }
            else
            {
                outfile << "<div class=\"col-item item\">" << endl;
                outfile << "<a target=\"_blank\" href=\"" << this->produtosOriginais[i]->getUrlTrailer() << "\">" << endl;
                outfile << "<div class=\"bg-img\">" << endl;
                outfile << "<img src=\"" << this->produtosOriginais[i]->getUrlImagem() << "\" style=\"width: 100%;\" />" << endl;
                outfile << "</div>" << endl;
                outfile << "<div class=\"info\">" << endl;
                outfile << "<h4>"<< produtosOriginais[i]->getNome() << "</label>" << endl;
                outfile << "<h4>"<< produtosOriginais[i]->getGenero()->getNome() << "</label>" << endl;
                outfile << "<h4>"<< produtosOriginais[i]->getClassificacaoIndicativa() << "</label>" << endl;
                outfile << "</div>" << endl;
                outfile << "</a>" << endl;
                outfile << "</div>" << endl;
            }
        }


    }
    else
    {
        outfile << "<label> Nenhum Produto Cadastrado!</label>\n";
    }


    outfile << "<div class=\"col-12\">" << endl;
    outfile << "<h2>ASSINANTES (FAVORITOS)</h2>" << endl;
    outfile << "</div>" << endl;

    if(assinantes.size() == 0)
    {
        outfile << "<label> Nenhum Assinante Cadastrado!</label>\n";

    }
    else
    {


        for(int i=0; i<this->assinantes.size(); i++)
        {

            outfile << "<div class=\"col-12\">" << endl;
            outfile << "<h3>" << assinantes[i]->getNome() << "</h3>" << endl;
            outfile << "</div>" << endl;

            if(assinantes[i]->getFavoritos().size() == 0)
            {
                outfile << "<label> Nenhum Produto Favoritado!</label>\n";

            }
            else
            {
                for(int j=0; j<this->assinantes[i]->getFavoritos().size(); j++)
                {
                    outfile << "<div class=\"col-item item\">" << endl;
                    outfile << "<a target=\"_blank\" href=\"" << this->assinantes[i]->getFavoritos()[j]->getUrlTrailer() << "\">" << endl;
                    outfile << "<div class=\"bg-img\">" << endl;
                    outfile << "<img src=\"" << this->assinantes[i]->getFavoritos()[j]->getUrlImagem() << "\" style=\"width: 100%;\" />" << endl;
                    outfile << "</div>" << endl;
                    outfile << "<div class=\"info\">" << endl;
                    outfile << "<h4>"<< assinantes[i]->getFavoritos()[j]->getNome() << "</label>" << endl;
                    outfile << "<h4>"<< assinantes[i]->getFavoritos()[j]->getGenero()->getNome() << "</label>" << endl;
                    outfile << "<h4>"<< assinantes[i]->getFavoritos()[j]->getClassificacaoIndicativa() << "</label>" << endl;
                    outfile << "</div>" << endl;
                    outfile << "</a>" << endl;
                    outfile << "</div>" << endl;
                }
            }
        }
    }
    outfile << "</div>" << endl;
    outfile << "</div>" << endl;
    outfile << "</body>" << endl;
    outfile << "</html>" << endl;

cout << "Plataforma " << this->nome << " foi exportada com sucesso!" << endl;
}



