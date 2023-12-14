#include "movimentacaoMNG.hpp"
#include <iostream>
#include <memory>
#include <cstddef>
int main(){
  int choice;
  auto interfaceMNG = std::make_unique<InterfaceMNG>();
  auto movimentacaoMNG = std::make_unique<MovimentacaoMNG>();
  do {
    interfaceMNG->inicialMenu();
    std::cin >> choice;

    switch(choice){
      case 1:
	{
	  int choice2;
	  interfaceMNG->produtosMenu();
	  std::cin >> choice2;
	  switch (choice2) {
	    case 1:{

	      char nome[100];
	      std::cout << "Digite o nome do produto" << std::endl;
	      std::cin >> nome;
	      Produto* listaProd = movimentacaoMNG->queryByNome(nome);
	      interfaceMNG->produtosConsultadosMenu(listaProd);
	      break;
	    }
	    case 2:
	      {

		Produto* listaProd = movimentacaoMNG->queryAll(); 
		interfaceMNG->produtosConsultadosMenu(listaProd);
		break;
	    }
	    case 3:
	      {
		break;
	    }
	    case 4:
	      {
		movimentacaoMNG->registrarSaida();
		break;
	    }
	    case 5:
	      {
		movimentacaoMNG->registrarEntrada();
		break;
	    }

	    case 0:
	      {
		break;
	    }
	  }

	  break;
      }
      case 2:
	{
	  int choice2;
	  interfaceMNG->fornecedoresMenu();
	  std::cin >> choice2;

	  switch(choice2)
	  {
	    case 1:
	      {
		char razaoSocial[100];
		std::cout << "Digite o nome do fornecedor" << std::endl;
		std::cin >> razaoSocial;
		Fornecedor* listaFornecedor = movimentacaoMNG->queryByRazaoSocial(razaoSocial);
		interfaceMNG->fornecedoresConsultadosMenu(listaFornecedor);
		break;
	    }
	    case 2:
	      {
		Fornecedor* listaFornecedor = movimentacaoMNG->queryAllFornecedores();
		interfaceMNG->fornecedoresConsultadosMenu(listaFornecedor);
		break;
	    }
	    case 3:
	      {
		std::cout << "NÃO IMPLEMENTADO" << std::endl;
		break;
	    }

	    case 0:
	      {
		break;
	    }
	  }
	  break;
      }
    }


  }while(choice != 0);  


  return 0;
}
