#include "movimentacaoMNG.hpp"
#include "interfaceMNG.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define MAX_PROD 100

Produto* MovimentacaoMNG::consultarProdutos(char* nome){
  Produto* lista = this->produtoDAO->consultarProdutos(nome);
  return lista;
}

void MovimentacaoMNG::setMovimentacaoAtual(Movimentacao m1){
  this->movimentacao = m1;
}

Movimentacao MovimentacaoMNG::getMovimentacaoAtual(){
  return this->movimentacao;
}

void MovimentacaoMNG::iniciarRegistroSaida(){

  Movimentacao* m1  = this->movimentacaoDAO->create();
  m1->setMovimentacaoTipo(1);
  this->setMovimentacaoAtual(*m1);
}

void MovimentacaoMNG::iniciarRegistroEntrada(){

  Movimentacao* m1  = this->movimentacaoDAO->create();
  m1->setMovimentacaoTipo(0);
  this->setMovimentacaoAtual(*m1);
}

void MovimentacaoMNG::registrarSaidaProduto(int idProduto,int quantidade,char* descricao){
  Movimentacao m1 = getMovimentacaoAtual(); 
  Produto p1  = this->produtoDAO->retrieve(idProduto);
  m1.setProduto(p1);
  m1.setQuantidade(quantidade);
  m1.setDescricao(descricao);
  setMovimentacaoAtual(m1);
}

void MovimentacaoMNG::concluirMovimentacao(){

  Movimentacao m1 = getMovimentacaoAtual();
  this->movimentacaoDAO->store(m1);
  this->produtoDAO->update(m1);

}




void MovimentacaoMNG::registrarEntradaProduto(int idProduto,int idFornecedor,float preco,int quantidade,int lote,char* codigoNotaFiscal){

  Movimentacao m1 = getMovimentacaoAtual();
  Produto p1 = this->produtoDAO->retrieve(idProduto);
  Fornecedor f1 = this->fornecedorDAO->retrieve(idFornecedor);

  m1.setProduto(p1);
  m1.setFornecedor(f1);
  m1.setPreco(preco);
  m1.setQuantidade(quantidade);
  m1.setLote(lote);
  m1.setNotaFiscal(codigoNotaFiscal);
  setMovimentacaoAtual(m1);

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

  Produto* lista = this->produtoDAO->consultarProdutos(nome);
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
          return;
          break;
        }
      case 1:
        {
          exit(0);
          //TODO
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

  registrarSaidaProduto(id,quantidade,descricao);
  concluirMovimentacao();
}

void MovimentacaoMNG::registrarEntrada(){
  char nome[100];
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



  Produto* lista = this->produtoDAO->consultarProdutos(nome);
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
          return;
          break;
        }
      case 1:
        {
          exit(0);
          //TODO
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


  std::cout << "Quem é o fornecedor? Digite o ID" << std::endl;
  std::cin >> idFornecedor;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Qual produto? Digite o ID, apenas números" << std::endl;
    std::cin >> idFornecedor;
  }

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

  registrarEntradaProduto(idProd, idFornecedor, preco, quantidade, lote, codigoNotaFiscal);

  concluirMovimentacao();

}



