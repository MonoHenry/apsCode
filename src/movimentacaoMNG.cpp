#include "movimentacaoMNG.hpp"
#include "interfaceMNG.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define MAX_PROD 100

Produto* MovimentacaoMNG::queryByNome(char* nome){
  Produto* lista = this->produtoMNG->listarProdutos(nome);
  return lista;
}

Fornecedor* MovimentacaoMNG::queryByRazaoSocial(char* razaoSocial){
  Fornecedor* lista = this->fornecedorMNG->listarFornecedores(razaoSocial);
  return lista;
}

void MovimentacaoMNG::setProdutoAtual(Produto* p1){
  this->produto = p1;
}

Produto* MovimentacaoMNG::getProdutoAtual(){
  return this->produto;
}

void MovimentacaoMNG::setMovimentacaoAtual(Movimentacao* m1){
  this->movimentacao = m1;
}

Movimentacao* MovimentacaoMNG::getMovimentacaoAtual(){
  return this->movimentacao;
}

void MovimentacaoMNG::iniciarRegistroSaida(){

  Movimentacao* m1  = this->movimentacaoDAO->create();
  m1->setMovimentacaoTipo(SAIDA);
  this->setMovimentacaoAtual(m1);
}

void MovimentacaoMNG::iniciarRegistroEntrada(){

  Movimentacao* m1  = this->movimentacaoDAO->create();
  m1->setMovimentacaoTipo(ENTRADA);
  this->setMovimentacaoAtual(m1);
}

void MovimentacaoMNG::registrarSaidaProduto(Produto p1,int quantidade,char* descricao){
  Movimentacao* m1 = getMovimentacaoAtual(); 
  int qtde = p1.getQuantidade();
  p1.setQuantidade(qtde - quantidade);
  m1->setProduto(p1);
  m1->setQuantidade(quantidade);
  m1->setDescricao(descricao);
}

void MovimentacaoMNG::concluirMovimentacao(){
  Movimentacao* m1 = getMovimentacaoAtual();
  Produto p1 = m1->getProduto();
  this->produtoDAO->update(p1);
  this->movimentacaoDAO->update(*m1);

}

void MovimentacaoMNG::registrarEntradaProduto(Produto p1,Fornecedor f1,float preco,int quantidade,int lote,char* codigoNotaFiscal){

  Movimentacao* m1 = getMovimentacaoAtual();

  int qtde = p1.getQuantidade();
  p1.setQuantidade(qtde + quantidade);
  m1->setProduto(p1);
  m1->setFornecedor(f1);
  m1->setPreco(preco);
  m1->setQuantidade(quantidade);
  m1->setLote(lote);
  m1->setNotaFiscal(codigoNotaFiscal);

}



void MovimentacaoMNG::registrarSaida(){
  char nome[100];
  int id;
  char descricao[100];
  int quantidade;
  int teste;

  iniciarRegistroSaida();
  std::cout << "Digite o nome do produto" << std::endl;
  std::cin >> nome;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Digite o nome do produto" << std::endl;
    std::cin >> nome;

  }

  Produto* lista = this->produtoMNG->listarProdutos(nome);
  teste = this->interfaceMNG->produtosConsultadosMenu(lista);

  if(teste == 0){
    std::cout << "Não existe tal produto" << std::endl;
    int choice1;
    std::cout << "Gostaria de cadastrar tal produto? Digite 0 para não, 1 para sim";
    std::cin >> choice1;

    while(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(100, '\n');
      std::cout << "Gostaria de cadastrar tal produto? Digite 0 para não, 1 para sim" << std::endl;
      std::cin >> choice1;
    }

    switch (choice1) {
      case 0:
        {

          std::cout << "NÃO IMPLEMENTADO" << std::endl;
          return;
          break;
        }
      case 1:
        {
          std::cout << "NÃO IMPLEMENTADO" << std::endl;
          return;
          break;
        }
    }

  }

  std::cout << "Qual produto? Digite o ID" << std::endl;
  std::cin >> id;

  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual produto? Digite o ID, apenas números" << std::endl;
    std::cin >> id;
  }
  Produto p1 = this->produtoDAO->retrieve(id);
  std::cout << "Qual a quantidade?" << std::endl;
  std::cin >> quantidade;

  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual a quantidade? Digite apenas números" << std::endl;
    std::cin >> quantidade;
  }

  std::cout << "Quan a descrição?" << std::endl;
  std::cin >> descricao;

  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Quan a descrição?" << std::endl;
    std::cin >> descricao;
  }

  registrarSaidaProduto(p1,quantidade,descricao);
  concluirMovimentacao();
}

void MovimentacaoMNG::registrarEntrada(){
  char nome[100];
  char razaoSocial[100];
  int idProd;
  int idFornecedor;
  float preco;
  int quantidade;
  int lote;
  char codigoNotaFiscal[100];
  int testando;

  iniciarRegistroEntrada();

  std::cout << "Digite o nome do produto" << std::endl;
  std::cin >> nome;



  Produto* lista = this->produtoMNG->listarProdutos(nome);
  testando = this->interfaceMNG->produtosConsultadosMenu(lista);

  if(testando == 0){
    std::cout << "Não existe tal produto" << std::endl;
    int choice2;
    std::cout << "Gostaria de cadastrar tal produto? Digite 0 para não, 1 para sim";
    std::cin >> choice2;

    while(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(100, '\n');
      std::cout << "Gostaria de cadastrar tal produto? Digite 0 para não, 1 para sim" << std::endl;
      std::cin >> choice2;
    }


    switch (choice2) {
      case 0:
        {

          std::cout << "NÃO IMPLEMENTADO" << std::endl;
          return;
          break;
        }
      case 1:
        {
          std::cout << "NÃO IMPLEMENTADO" << std::endl;
          return;
          break;
        }
    }

  }
  std::cout << "Qual o nome do fornecedor?" << std::endl;
  std::cin >> razaoSocial;
  Fornecedor* lista2 = this->fornecedorMNG->listarFornecedores(razaoSocial);
  int teste2 = this->interfaceMNG->fornecedoresConsultadosMenu(lista2);
  
  if(teste2 == 0){
    std::cout << "Não existe tal fornecedor" << std::endl;
    int choice2;
    std::cout << "Gostaria de cadastrar tal fornecedor? Digite 0 para não, 1 para sim";
    std::cin >> choice2;

    while(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(100, '\n');
      std::cout << "Gostaria de cadastrar tal fornecedor? Digite 0 para não, 1 para sim" << std::endl;
      std::cin >> choice2;
    }


    switch (choice2) {
      case 0:
        {

          std::cout << "NÃO IMPLEMENTADO" << std::endl;
          return;
          break;
        }
      case 1:
        {
          std::cout << "NÃO IMPLEMENTADO" << std::endl;
          return;
          break;
        }
    }

  }
 
  std::cout << "Qual o produto? Digite o ID" << std::endl;
  std::cin >> idProd;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual produto? Digite o ID, apenas números" << std::endl;
    std::cin >> idProd;
  }
  Produto p1  = this->produtoDAO->retrieve(idProd);

  std::cout << "Quem é o fornecedor? Digite o ID" << std::endl;
  std::cin >> idFornecedor;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual produto? Digite o ID, apenas números" << std::endl;
    std::cin >> idFornecedor;
  }
  Fornecedor f1 = this->fornecedorDAO->retrieve(idFornecedor);

  std::cout << "Qual o preço?" << std::endl;
  std::cin >> preco;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual preco? Apenas números" << std::endl;
    std::cin >> preco;
  }

  std::cout << "Qual a quantidade?" << std::endl;
  std::cin >> quantidade;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual a quantidade? Apenas números" << std::endl;
    std::cin >> quantidade;
  }

  std::cout << "Qual o lote?" << std::endl;
  std::cin >> lote;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual o lote? Apenas números" << std::endl;
    std::cin >> lote;
  }

  std::cout << "Qual o código da nota fiscal?" << std::endl;
  std::cin >> codigoNotaFiscal;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual o código da nota fiscal? Apenas números" << std::endl;
    std::cin >> codigoNotaFiscal;
  }

  registrarEntradaProduto(p1, f1, preco, quantidade, lote, codigoNotaFiscal);

  concluirMovimentacao();

}



