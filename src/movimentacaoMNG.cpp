#include "movimentacaoMNG.hpp"
#include "interfaceMNG.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define MAX_PROD 100

void MovimentacaoMNG::setProdutoDao(ProdutoDAO* pDAO){
  this->produtoDAO = pDAO;
}

void MovimentacaoMNG::setMovimentacaoDao(MovimentacaoDAO* mDAO){
  this->movimentacaoDAO = mDAO;
}

void MovimentacaoMNG::setFornecedorDao(FornecedorDAO* fDAO){
  this->fornecedorDAO = fDAO;
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

