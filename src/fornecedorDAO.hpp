#pragma once
#include "fornecedor.hpp"
#define MAX_FORNECEDOR 100
#include <cstring>

class FornecedorDAO{
private:
  Fornecedor nullFornecedor;
  Fornecedor listaFornecedores[MAX_FORNECEDOR] = {nullFornecedor};

public:
  FornecedorDAO()
  {
    this->nullFornecedor.setId(0);
    this->listaFornecedores[0].setId(12);
    this->listaFornecedores[0].setCnpj("12345678910100");
    this->listaFornecedores[0].setEndereco("Peri Alto");
    this->listaFornecedores[0].setRazaoSocial("YoungSP");
    this->listaFornecedores[0].setNomeDeContato("Rob Dillan");
    this->listaFornecedores[0].setTelefoneDeContato("11994990876");
  }
  Fornecedor* queryByRazaoSocial(char*);
  Fornecedor retrieve(int);
  Fornecedor* queryAllFornecedores();
};
