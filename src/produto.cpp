#include "produto.hpp"
#include <cstring>

void Produto::setId(int id){
  this->id = id;
}

void Produto::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}

void Produto::setNome(const char* nome){
  std::strcpy(this->nome, nome);  
}

void Produto::setStatus(int status){
  this->status = status;
}

void Produto::setQuantidadeMinima(int quantidadeMinima){
  this->quantidadeMinima = quantidadeMinima;
}

int Produto::getId(){
  return this->id;
}

int Produto::getQuantidade(){
  return this->quantidade;
}

char* Produto::getNome(){
  return this->nome;  
}

int Produto::getStatus(){
  return this->status;
}

int Produto::getQuantidadeMinima(){
  return this->quantidadeMinima;
}
