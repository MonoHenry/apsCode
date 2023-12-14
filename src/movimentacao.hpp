#pragma once
#include <time.h>
#include "produto.hpp"
#include "fornecedor.hpp"
#include "funcionario.hpp"
#include "enum.hpp"
class Movimentacao{
private:
  int id = 0;
  Funcionario* funcionario;
  Produto* produto;
  TipoDeMovimento tipoDeMovimento;
  Fornecedor* fornecedor;
  time_t data;
  float preco;
  int quantidade;
  int lote;
  char codigoNotaFiscal[100];
  char descricaoMovimentacao[100];
public:
  void setProduto(Produto*);
  void setQuantidade(int);
  void setDescricao(char*);
  void setMovimentacaoTipo(TipoDeMovimento);
  void setFornecedor(Fornecedor*);
  void setPreco(float);
  void setLote(int);
  void setNotaFiscal(char*);

  Produto* getProduto();
  int getQuantidade();
  char* getDescricao();
  int getMovimentacaoTipo();
  Fornecedor* getFornecedor();
  float getPreco();
  int getLote();
  char* getNotaFiscal();
};
