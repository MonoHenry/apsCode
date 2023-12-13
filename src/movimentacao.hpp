#pragma once
#include <time.h>
#include "produto.hpp"
#include "fornecedor.hpp"

class Movimentacao{
private:
  int id = 0;
  time_t data;
  float preco;
  int tipoDeMovimento;
  int lote;
  int quantidade;
  char codigoNotaFiscal[100];
  char descricaoMovimentacao[100];
  Produto produto;
  Fornecedor fornecedor;
public:
  void setProduto(Produto);
  void setQuantidade(int);
  void setDescricao(char*);
  void setMovimentacaoTipo(int);
  void setFornecedor(Fornecedor);
  void setPreco(float);
  void setLote(int);
  void setNotaFiscal(char*);

  Produto getProduto();
  int getQuantidade();
  char* getDescricao();
  int getMovimentacaoTipo();
  Fornecedor getFornecedor();
  float getPreco();
  int getLote();
  char* getNotaFiscal();
};
