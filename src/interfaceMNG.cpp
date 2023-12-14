#include "interfaceMNG.hpp"
#include <iostream>
#include <cstring>
#define MAX_PROD 100
void InterfaceMNG::inicialMenu(){
  std::cout << "+========================================+" << std::endl;
  std::cout << "| Escolha uma opção:                     |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|1. Produtos.                            |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|2. Fornecedores.                        |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|3. Funcionários.                        |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|0. Sair.                                |" << std::endl;
  std::cout << "+========================================+" << std::endl;
}

void InterfaceMNG::produtosMenu(){
  std::cout << "+========================================+" << std::endl;
  std::cout << "|Escolha uma opção para Produtos:        |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|1. Consultar Produto.                   |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|2. Consultar Estoque de Produtos.       |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|3. Cadastrar Produtos.                  |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|4. Registrar Saída de Produtos.         |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|5. Registrar Entrada de Produtos.       |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|0. Retornar.                            |" << std::endl;
  std::cout << "+========================================+" << std::endl;


}

void InterfaceMNG::fornecedoresMenu(){
  std::cout << "+========================================+" << std::endl;
  std::cout << "| Escolha uma opção.                     |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|1. Consultar Fornecedor.                |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|2. Consultar Todos os Fornecedores.     |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|3. Cadastrar Fornecedores.              |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|4. Deletar Funcionários.                |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|0. Retornar.                            |" << std::endl;
  std::cout << "+========================================+" << std::endl;
}



int InterfaceMNG::produtosConsultadosMenu(Produto* lista){
  int nums = 0;
  for(int i = 0; i < MAX_PROD; i++){
    if(lista[i].getId() != 0){
    nums++;
    std::cout << "Id: " << lista[i].getId() << std::endl;
    std::cout << "Quantidade: "<< lista[i].getQuantidade() << std::endl;
    std::cout << "Nome: "<< lista[i].getNome() << std::endl;
    std::cout << "Status: "<< lista[i].getStatus() << std::endl;
    std::cout << "Quantidade mínima:"<< lista[i].getQuantidadeMinima() << std::endl;
    std::cout << std::endl;}
  }
  return nums;
  
}

void InterfaceMNG::funcionariosMenu(){
  std::cout << "+========================================+" << std::endl;
  std::cout << "|Escolha uma opção para Produtos:        |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|1. Consultar Funcionários:              |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|2. Cadastrar Funcionários:              |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|3. Atualizar Funcionário:               |" << std::endl;
  std::cout << "+========================================+" << std::endl;
  std::cout << "|4. Deletar Funcionário:                 |" << std::endl;
  std::cout << "+========================================+" << std::endl;
}

int InterfaceMNG::fornecedoresConsultadosMenu(Fornecedor* lista){
  int nums = 0;
  for(int i = 0; i < MAX_PROD; i++){
    if(lista[i].getId() != 0){
    nums++;
    std::cout << "Id: " << lista[i].getId() << std::endl;
    std::cout << "CNPJ: "<< lista[i].getCnpj() << std::endl;
    std::cout << "Razao Social: "<< lista[i].getRazaoSocial() << std::endl;
    std::cout << "Endereço: "<< lista[i].getEndereco() << std::endl;
    std::cout << "Nome de contato:"<< lista[i].getNomeDeContato() << std::endl;
    std::cout << "Telefone de contato:"<< lista[i].getTelefoneDeContato() << std::endl;
    std::cout << std::endl;}
  }
  return nums;
  
}
