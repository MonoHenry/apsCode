#pragma once
#include "fornecedorDAO.hpp"

class FornecedorMNG{
private:
public:
  Fornecedor* listarFornecedores(char*);
  FornecedorDAO* fornecedorDAO = new FornecedorDAO();
};
