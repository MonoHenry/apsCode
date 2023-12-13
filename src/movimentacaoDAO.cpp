#include "movimentacaoDAO.hpp"

Movimentacao* MovimentacaoDAO::create(){
  return new Movimentacao();
}

void MovimentacaoDAO::store(Movimentacao m1){
  this->listaProdutos[storePos] = m1;
  storePos++;
}


