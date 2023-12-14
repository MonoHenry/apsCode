#pragma once

class Fornecedor{
private:
  int id;
  char cnpj[15];
  char razaoSocial[100];
  char endereco[100];
  char nomeDeContato[100];
  char telefoneDeContato[11];
public:
  void setId(int);
  void setRazaoSocial(const char*);
  void setEndereco(const char*);
  void setNomeDeContato(const char*);
  void setTelefoneDeContato(const char*);
  void setCnpj(const char*);

  int getId();
  char* getCnpj();
  char* getRazaoSocial();
  char* getEndereco();
  char* getNomeDeContato();
  char* getTelefoneDeContato();
};
