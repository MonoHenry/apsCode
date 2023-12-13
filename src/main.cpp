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
	    Produto* listaProd = movimentacaoMNG->consultarProdutos(nome);
	    interfaceMNG->produtosConsultadosMenu(listaProd);
	    break;
		}
	  case 3:
		{
	    movimentacaoMNG->registrarSaida();
	    break;
		}
	  case 4:
		{
	    movimentacaoMNG->registrarEntrada();
	    break;
		}
      	}
	
	break;
      }
      case 2:
      {
	int choice2;
	interfaceMNG->funcionariosMenu();
      
	break;
      }
    }


  }while(choice != 0);  


  return 0;
}
