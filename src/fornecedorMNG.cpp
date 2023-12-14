#include "fornecedorMNG.hpp"

Fornecedor* FornecedorMNG::listarFornecedores(char* razaoSocial){
  Fornecedor* lista = this->fornecedorDAO->queryByRazaoSocial(razaoSocial);
  return lista;
}

Fornecedor* FornecedorMNG::queryAllFornecedores(){
  Fornecedor* lf1 = this->fornecedorDAO->queryAllFornecedores();
  return lf1;
}

void FornecedorMNG::setFornecedorDao(FornecedorDAO* fDAO){
  this->fornecedorDAO = fDAO;
}
