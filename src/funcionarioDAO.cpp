#include "funcionarioDAO.hpp"

Funcionario FuncionarioDAO::create(){
  return *(new Funcionario());
}

void FuncionarioDAO::store(Funcionario f1){

  this->listaFuncionario[this->storePos++] = f1;

}


