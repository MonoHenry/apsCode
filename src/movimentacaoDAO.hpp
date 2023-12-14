#pragma once
#include "movimentacao.hpp"

#define MAX_PROD 100

class MovimentacaoDAO{
private:

  Movimentacao* movimentacao;
  Movimentacao listaProdutos[100];
  int storePos = 0;

public:
  Movimentacao* create();
  void update(Movimentacao m1);

};
