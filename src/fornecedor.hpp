#pragma once

class Fornecedor{
private:
  int id;
  char cnpj[14];
  char razaoSocial[100];
  char endereco[100];
  char nomeDeContato[100];
  char telefoneDeContato[100];
public:
  void setId(int);
  void setCnpj(char*);
  void setRazaoSocial(char*);
  void setEndereco(char*);
  void setNomeDeContato(char*);
  void setTelefoneDeContato(char*);
 
  int getId();
  char* getCnpj();
  char* getRazaoSocial();
  char* getEndereco();
  char* getNomeDeContato();
  char* getTelefoneDeContato();
};
