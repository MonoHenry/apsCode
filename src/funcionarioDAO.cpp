#include "funcionarioDAO.hpp"

Funcionario* FuncionarioDAO::create(){
  return new Funcionario();
}

void FuncionarioDAO::update(Funcionario* f1){

  this->listaFuncionario[this->storePos++] = *f1;

}


