#include <cstring>
#include "funcionario.hpp"

void Funcionario::setIdFuncionario(int id){
  this->idFuncionario = id;
}

void Funcionario::setCpf(char* cpf){  
  std::strcpy(this->cpf, cpf);
}

void Funcionario::setNome(char* nome){
  std::strcpy(this->nome, nome);
}

void Funcionario::setEndereco(char* endereco){
  std::strcpy(this->endereco, endereco);
}

void Funcionario::setCargo(int cargo){
  this->cargo = cargo;
}

