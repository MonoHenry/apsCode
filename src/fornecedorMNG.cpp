#include "fornecedorMNG.hpp"

Fornecedor* FornecedorMNG::listarFornecedores(char* razaoSocial){
  Fornecedor* lista = this->fornecedorDAO->queryByRazaoSocial(razaoSocial);
  return lista;
}
