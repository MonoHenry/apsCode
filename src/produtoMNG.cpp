#include "produtoMNG.hpp"

Produto* ProdutoMNG::listarProdutos(char* nome){
  Produto* lp1 = this->produtoDAO->queryByNome(nome);
  return lp1;
}
