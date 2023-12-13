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

Produto* ProdutoDAO::consultarProdutos(char* nome){

	int pos = 0;
	Produto* listaProdutosConsultados = new Produto[100];

	for(int i = 0; i < MAX_PROD; i++){

		if(strcmp(nome,(this->listaProdutos+i)->getNome()) == 0){
			*(listaProdutosConsultados + pos++) = this->listaProdutos[i];
		}

	}
	return listaProdutosConsultados;

}

void ProdutoDAO::update(Movimentacao m1){
  for(int i = 0; (this->listaProdutos+i)->getId() != 0; i++){
    if(m1.getProduto().getId() == (this->listaProdutos+i)->getId()){
      if(m1.getMovimentacaoTipo() == 0){

	int quantidade = (this->listaProdutos+i)->getQuantidade() + m1.getQuantidade();
        (this->listaProdutos+i)->setQuantidade(quantidade);
	break;

      }else{

	int quantidade = (this->listaProdutos+i)->getQuantidade() - m1.getQuantidade();
	(this->listaProdutos+i)->setQuantidade(quantidade);
	break;
				
      }
    }
  }
}
