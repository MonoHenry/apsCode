#include "produtoMNG.hpp"

Produto* ProdutoMNG::listarProdutos(char* nome){
  Produto* lp1 = this->produtoDAO->queryByNome(nome);
  return lp1;
}

Produto* ProdutoMNG::queryAll(){
  Produto* lp1 = this->produtoDAO->queryAll();
  return lp1;
}


