#include "movimentacaoMNG.hpp"
#include "movimentacaoDAO.hpp"
#include "interfaceMNG.hpp"
#include "fornecedorDAO.hpp"
#include "produtoMNG.hpp"
#include "fornecedorMNG.hpp"
#include "produtoDAO.hpp"
#include <iostream>
#include <memory>
#include <cstddef>
int main(){

  FornecedorDAO* fornecedorDAO = new FornecedorDAO();
  ProdutoDAO* produtoDAO = new ProdutoDAO;
  MovimentacaoDAO* movimentacaoDAO = new MovimentacaoDAO();
  auto interfaceMNG = std::make_unique<InterfaceMNG>();
  auto movimentacaoMNG = std::make_unique<MovimentacaoMNG>();
  auto fornecedorMNG = std::make_unique<FornecedorMNG>();
  auto produtoMNG = std::make_unique<ProdutoMNG>();
  movimentacaoMNG->setFornecedorDao(fornecedorDAO);
  movimentacaoMNG->setProdutoDao(produtoDAO);
  movimentacaoMNG->setMovimentacaoDao(movimentacaoDAO);
  fornecedorMNG->setFornecedorDao(fornecedorDAO);
  produtoMNG->setProdutoDao(produtoDAO);

  int choice;
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
	      Produto* listaProd = produtoDAO->queryByNome(nome);
	      interfaceMNG->produtosConsultadosMenu(listaProd);
	      break;
	    }
	    case 2:
	      {

		Produto* listaProd = produtoDAO->queryAll(); 
		interfaceMNG->produtosConsultadosMenu(listaProd);
		break;
	    }
	    case 3:
	      {
		break;
	    }
	    case 4:
	      {

		char nome[100];
		int id;
		char descricao[100];
		int quantidade;
		int teste;

		movimentacaoMNG->iniciarRegistroSaida();
		std::cout << "Digite o nome do produto" << std::endl;
		std::cin >> nome;
		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Digite o nome do produto" << std::endl;
		  std::cin >> nome;

		}

		Produto* lista = produtoMNG->listarProdutos(nome);
		teste = interfaceMNG->produtosConsultadosMenu(lista);

		if(teste == 0){
		  std::cout << "Não existe tal produto" << std::endl;
		  int choice1;
		  std::cout << "Gostaria de cadastrar tal produto? Digite 0 para não, 1 para sim";
		  std::cin >> choice1;

		  while(std::cin.fail()){
		    std::cin.clear();
		    std::cin.ignore(100, '\n');
		    std::cout << "Gostaria de cadastrar tal produto? Digite 0 para não, 1 para sim" << std::endl;
		    std::cin >> choice1;
		  }

		  switch (choice1) {
		    case 0:
		      {

			std::cout << "NÃO IMPLEMENTADO" << std::endl;
			break;
		      }
		    case 1:
		      {
			std::cout << "NÃO IMPLEMENTADO" << std::endl;
			break;
		      }
		  }

		}

		std::cout << "Qual produto? Digite o ID" << std::endl;
		std::cin >> id;

		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Qual produto? Digite o ID, apenas números" << std::endl;
		  std::cin >> id;
		}
		Produto p1 = produtoDAO->retrieve(id);
		std::cout << "Qual a quantidade?" << std::endl;
		std::cin >> quantidade;

		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Qual a quantidade? Digite apenas números" << std::endl;
		  std::cin >> quantidade;
		}

		std::cout << "Quan a descrição?" << std::endl;
		std::cin >> descricao;

		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Quan a descrição?" << std::endl;
		  std::cin >> descricao;
		}

		movimentacaoMNG->registrarSaidaProduto(p1,quantidade,descricao);
		movimentacaoMNG->concluirMovimentacao();
		break;
	    }
	    case 5:
	      {

		char nome[100];
		char razaoSocial[100];
		int idProd;
		int idFornecedor;
		float preco;
		int quantidade;
		int lote;
		char codigoNotaFiscal[100];
		int testando;

		movimentacaoMNG->iniciarRegistroEntrada();

		std::cout << "Digite o nome do produto" << std::endl;
		std::cin >> nome;



		Produto* lista = produtoMNG->listarProdutos(nome);
		testando = interfaceMNG->produtosConsultadosMenu(lista);

		if(testando == 0){
		  std::cout << "Não existe tal produto" << std::endl;
		  int choice2;
		  std::cout << "Gostaria de cadastrar tal produto? Digite 0 para não, 1 para sim";
		  std::cin >> choice2;

		  while(std::cin.fail()){
		    std::cin.clear();
		    std::cin.ignore(100, '\n');
		    std::cout << "Gostaria de cadastrar tal produto? Digite 0 para não, 1 para sim" << std::endl;
		    std::cin >> choice2;
		  }


		  switch (choice2) {
		    case 0:
		      {

			std::cout << "NÃO IMPLEMENTADO" << std::endl;
			break;
		      }
		    case 1:
		      {
			std::cout << "NÃO IMPLEMENTADO" << std::endl;
			break;
		      }
		  }

		}
		std::cout << "Qual o nome do fornecedor?" << std::endl;
		std::cin >> razaoSocial;
		Fornecedor* lista2 = fornecedorMNG->listarFornecedores(razaoSocial);
		int teste2 = interfaceMNG->fornecedoresConsultadosMenu(lista2);

		if(teste2 == 0){
		  std::cout << "Não existe tal fornecedor" << std::endl;
		  int choice2;
		  std::cout << "Gostaria de cadastrar tal fornecedor? Digite 0 para não, 1 para sim";
		  std::cin >> choice2;

		  while(std::cin.fail()){
		    std::cin.clear();
		    std::cin.ignore(100, '\n');
		    std::cout << "Gostaria de cadastrar tal fornecedor? Digite 0 para não, 1 para sim" << std::endl;
		    std::cin >> choice2;
		  }


		  switch (choice2) {
		    case 0:
		      {

			std::cout << "NÃO IMPLEMENTADO" << std::endl;
			break;
		      }
		    case 1:
		      {
			std::cout << "NÃO IMPLEMENTADO" << std::endl;
			break;
		      }
		  }

		}

		std::cout << "Qual o produto? Digite o ID" << std::endl;
		std::cin >> idProd;
		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Qual produto? Digite o ID, apenas números" << std::endl;
		  std::cin >> idProd;
		}
		Produto p1  = produtoDAO->retrieve(idProd);

		std::cout << "Quem é o fornecedor? Digite o ID" << std::endl;
		std::cin >> idFornecedor;
		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Qual produto? Digite o ID, apenas números" << std::endl;
		  std::cin >> idFornecedor;
		}
		Fornecedor f1 = fornecedorDAO->retrieve(idFornecedor);

		std::cout << "Qual o preço?" << std::endl;
		std::cin >> preco;
		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Qual preco? Apenas números" << std::endl;
		  std::cin >> preco;
		}

		std::cout << "Qual a quantidade?" << std::endl;
		std::cin >> quantidade;
		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Qual a quantidade? Apenas números" << std::endl;
		  std::cin >> quantidade;
		}

		std::cout << "Qual o lote?" << std::endl;
		std::cin >> lote;
		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Qual o lote? Apenas números" << std::endl;
		  std::cin >> lote;
		}

		std::cout << "Qual o código da nota fiscal?" << std::endl;
		std::cin >> codigoNotaFiscal;
		while(std::cin.fail()){
		  std::cin.clear();
		  std::cin.ignore(100, '\n');
		  std::cout << "Qual o código da nota fiscal? Apenas números" << std::endl;
		  std::cin >> codigoNotaFiscal;
		}

		movimentacaoMNG->registrarEntradaProduto(p1, f1, preco, quantidade, lote, codigoNotaFiscal);

		movimentacaoMNG->concluirMovimentacao();
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
		Fornecedor* listaFornecedor = fornecedorMNG->listarFornecedores(razaoSocial);
		interfaceMNG->fornecedoresConsultadosMenu(listaFornecedor);
		break;
	    }
	    case 2:
	      {
		Fornecedor* listaFornecedor = fornecedorMNG->queryAllFornecedores();
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
