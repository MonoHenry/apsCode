#pragma once
#include "produto.hpp"
#include "fornecedor.hpp"
#define MAX_PROD 100
class InterfaceMNG{
public:
  void inicialMenu();
  void produtosMenu();
  int produtosConsultadosMenu(Produto*);
  void funcionariosMenu();
  int fornecedoresConsultadosMenu(Fornecedor*);
};
