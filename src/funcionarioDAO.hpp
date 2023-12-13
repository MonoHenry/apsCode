#pragma once
#include "funcionario.hpp"
#define MAX_FUNCIONARIO 100

class FuncionarioDAO{
private:
  Funcionario listaFuncionario[MAX_FUNCIONARIO];
  int storePos = 0;

public: 
  Funcionario create();
  void store(Funcionario);
};
