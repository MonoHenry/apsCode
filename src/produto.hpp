#pragma once
class Produto{
private:
  int id;
  int quantidade;
  char nome[50];
  int status;
  int quantidadeMinima;
public:
  void setId(int);
  void setQuantidade(int);
  void setNome(const char*);
  void setStatus(int);
  void setQuantidadeMinima(int);
  
  int getId();
  int getQuantidade();
  char* getNome();
  int getStatus();
  int getQuantidadeMinima();



};
