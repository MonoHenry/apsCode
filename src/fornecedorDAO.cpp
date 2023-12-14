#define MAX_FORNECEDOR 100
#include "fornecedorDAO.hpp"

Fornecedor* FornecedorDAO::retrieve(int idFornecedor){
  for(int i = 0; i < MAX_FORNECEDOR; i++){
    if(idFornecedor == this->listaFornecedores[i].getId()){
      return this->listaFornecedores+i;
    }
  }
  return &nullFornecedor;
}


Fornecedor* FornecedorDAO::queryByRazaoSocial(char* razaoSocial){

	int pos = 0;
	Fornecedor* listaFornecedoresConsultados = new Fornecedor[100];

	for(int i = 0; i < MAX_FORNECEDOR; i++){

		if(strcmp(razaoSocial,(this->listaFornecedores+i)->getRazaoSocial()) == 0){
			*(listaFornecedoresConsultados + pos++) = this->listaFornecedores[i];
		}

	}
	return listaFornecedoresConsultados;

}

Fornecedor* FornecedorDAO::queryAllFornecedores(){

	int pos = 0;
	Fornecedor* listaFornecedoresConsultados = new Fornecedor[100];

	for(int i = 0; i < MAX_FORNECEDOR; i++){

		if((this->listaFornecedores+i)->getId() != 0){
			*(listaFornecedoresConsultados + pos++) = this->listaFornecedores[i];
		}

	}
	return listaFornecedoresConsultados;

}
