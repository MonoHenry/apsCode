#pragma once
#include "produtoDAO.hpp"
#include "fornecedor.hpp"
class ProdutoMNG{
private:
public:
  Produto* listarProdutos(char*);
  Produto* queryAll();
  ProdutoDAO* produtoDAO = new ProdutoDAO();
};
