#pragma once
#include "movimentacao.hpp"

#define MAX_PROD 100

class MovimentacaoDAO{
private:
  Movimentacao* movimentacao;
  Movimentacao listaProdutos[MAX_PROD];
  int storePos = 0;

public:
  Movimentacao* create();
  void store(Movimentacao m1);

};
