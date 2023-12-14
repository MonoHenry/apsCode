#pragma once
#include "produtoDAO.hpp"
class ProdutoMNG{
private:
public:
  Produto* listarProdutos(char*);
  ProdutoDAO* produtoDAO = new ProdutoDAO();
};
