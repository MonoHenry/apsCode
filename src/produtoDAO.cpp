#include "produtoDAO.hpp"
#include "produto.hpp"
#include <cstring>
#include <cstdlib>

Produto ProdutoDAO::retrieve(int idProduto){
	for(int i = 0; i < MAX_PROD; i++){
		if(idProduto == listaProdutos[i].getId()){
			return listaProdutos[i];
		}
	}
	return nullProduto;
}

Produto* ProdutoDAO::queryByNome(char* nome){

	int pos = 0;
	Produto* listaProdutosConsultados = new Produto[100];

	for(int i = 0; i < MAX_PROD; i++){

		if(strcmp(nome,(this->listaProdutos+i)->getNome()) == 0){
			*(listaProdutosConsultados + pos++) = this->listaProdutos[i];
		}

	}
	return listaProdutosConsultados;

}

Produto* ProdutoDAO::queryAll(){

	int pos = 0;
	Produto* listaProdutosConsultados = new Produto[100];

	for(int i = 0; i < MAX_PROD; i++){

		if((this->listaProdutos+i)->getId() != 0){
			*(listaProdutosConsultados + pos++) = this->listaProdutos[i];
		}

	}
	return listaProdutosConsultados;

}

void ProdutoDAO::update(Produto p1){
	for(int i = 0; i < MAX_PROD; i++){
		if(p1.getId() == (this->listaProdutos+i)->getId()){
			*(this->listaProdutos+i) = p1;
		}
	}
}
