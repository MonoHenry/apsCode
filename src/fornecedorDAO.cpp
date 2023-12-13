#define MAX_FORNECEDOR 100
#include "fornecedorDAO.hpp"

Fornecedor FornecedorDAO::retrieve(int idFornecedor){
  for(int i = 0; i < MAX_FORNECEDOR; i++){
    if(idFornecedor == this->listaFornecedor[i].getId()){
      return this->listaFornecedor[i];
    }
  }
  return nullFornecedor;
}
