#include "fornecedor.hpp"
#include <cstring>

void Fornecedor::setId(int id){
  this->id = id;
}

void Fornecedor::setCnpj(char* cnpj){
  std::strcpy(this->cnpj, cnpj);  
}

void Fornecedor::setRazaoSocial(char* razaoSocial){
  std::strcpy(this->razaoSocial, razaoSocial);
}

void Fornecedor::setEndereco(char* endereco){
  std::strcpy(this->endereco, endereco);
}

void Fornecedor::setNomeDeContato(char* nomeDeContato){
  std::strcpy(this->nomeDeContato, nomeDeContato);
}

void Fornecedor::setTelefoneDeContato(char* telefoneDeContato){
  std::strcpy(this->telefoneDeContato, telefoneDeContato);
}

int Fornecedor::getId(){
  return this->id;
}

char* Fornecedor::getCnpj(){
  return this->cnpj;  
}

char* Fornecedor::getRazaoSocial(){
  return this->razaoSocial;
}

char* Fornecedor::getEndereco(){
  return this->endereco;
}

char* Fornecedor::getNomeDeContato(){
  return this->nomeDeContato;
}

char* Fornecedor::getTelefoneDeContato(){
  return this->telefoneDeContato;
}
