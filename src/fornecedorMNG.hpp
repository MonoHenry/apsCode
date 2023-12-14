#pragma once
#include "fornecedorDAO.hpp"

class FornecedorMNG{
private:
public:
  Fornecedor* listarFornecedores(char*);
  Fornecedor* queryAllFornecedores();
  FornecedorDAO* fornecedorDAO = new FornecedorDAO();
};
