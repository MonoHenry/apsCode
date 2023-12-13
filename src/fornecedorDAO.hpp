#include "fornecedor.hpp"
#pragma once
#define MAX_FORNECEDOR 100

class FornecedorDAO{
private:
  Fornecedor nullFornecedor;
  Fornecedor listaFornecedor[MAX_FORNECEDOR] = {nullFornecedor};

public:
  FornecedorDAO()
  {
    nullFornecedor.setId(0);
  }

  Fornecedor retrieve(int);
};
