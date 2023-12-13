#pragma once
#include "produto.hpp"
#include "movimentacao.hpp"
#include <cstddef>
#define MAX_PROD 100

class ProdutoDAO{
private:
  Produto nullProduto;
  Produto listaProdutos[MAX_PROD] = {nullProduto};
public:
  Produto retrieve(int);
  Produto* consultarProdutos(char* nome);
  void update(Movimentacao m1);
  ProdutoDAO()
  {
    this->nullProduto.setId(1);
    this->listaProdutos[0].setId(1);
    this->listaProdutos[0].setQuantidade(10);
    this->listaProdutos[0].setNome("arroz");
    this->listaProdutos[0].setStatus(0);
    this->listaProdutos[0].setQuantidadeMinima(5);
  }


};
