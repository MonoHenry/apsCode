#pragma once
class Funcionario{
private:
  int idFuncionario;
  char cpf[11];
  char nome[100];
  char endereco[100];
  int cargo;
public:
  void setIdFuncionario(int);
  void setCpf(char*);
  void setNome(char*);
  void setEndereco(char*);
  void setCargo(int);
};
