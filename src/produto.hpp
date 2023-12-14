#pragma once
class Produto{
private:
  int id;
  char nome[50];
  int status;
  int quantidade;
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
