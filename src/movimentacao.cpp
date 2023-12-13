#include "movimentacao.hpp"
#include <cstring>

void Movimentacao::setProduto(Produto p1){
  this->produto = p1;
}

void Movimentacao::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}

void Movimentacao::setLote(int lote){
  this->lote = lote;
}

void Movimentacao::setDescricao(char* movimentacao){
  strcpy(this->descricaoMovimentacao, movimentacao);
}


void Movimentacao::setMovimentacaoTipo(int tipo){
  this->tipoDeMovimento = tipo;
}
void Movimentacao::setFornecedor(Fornecedor f1){
  this->fornecedor = f1;
}

void Movimentacao::setPreco(float preco){
  this->preco = preco;
}

void Movimentacao::setNotaFiscal(char* codigoNotaFiscal){
  strcpy(this->codigoNotaFiscal, codigoNotaFiscal);
}

Produto Movimentacao::getProduto(){
  return this->produto;
}

int Movimentacao::getQuantidade(){
  return this->quantidade;
}

int Movimentacao::getLote(){
  return this->lote;
}

char* Movimentacao::getDescricao(){
  return this->descricaoMovimentacao;
}


int Movimentacao::getMovimentacaoTipo(){
  return this->tipoDeMovimento;
}
Fornecedor Movimentacao::getFornecedor(){
  return this->fornecedor;
}

float Movimentacao::getPreco(){
  return this->preco;
}

char* Movimentacao::getNotaFiscal(){
  return this->codigoNotaFiscal;
}
