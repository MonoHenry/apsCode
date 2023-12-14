#include "movimentacaoDAO.hpp"

Movimentacao* MovimentacaoDAO::create(){
  return new Movimentacao();
}

void MovimentacaoDAO::update(Movimentacao m1){
  this->listaProdutos[storePos] = m1;
  storePos++;
}


