#pragma once
#include "produto.hpp"
#define MAX_PROD 100
class InterfaceMNG{
public:
  void inicialMenu();
  void produtosMenu();
  int produtosConsultadosMenu(Produto*);
  void funcionariosMenu();

};
