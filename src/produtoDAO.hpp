#pragma once
#include "produto.hpp"
#include <cstddef>
#define MAX_PROD 100

class ProdutoDAO{
private:
  Produto nullProduto;
  Produto listaProdutos[MAX_PROD] = {nullProduto};

public:
  Produto* retrieve(int);
  Produto* queryByNome(char*);
  Produto* queryAll();
  void update(Produto*);
  ProdutoDAO()
  {
    this->nullProduto.setId(0);
    this->listaProdutos[0].setId(1);
    this->listaProdutos[0].setQuantidade(10);
    this->listaProdutos[0].setNome("arroz");
    this->listaProdutos[0].setStatus(0);
    this->listaProdutos[0].setQuantidadeMinima(5);
  }


};
