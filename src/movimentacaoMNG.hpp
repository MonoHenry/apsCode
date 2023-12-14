#pragma once
#include "movimentacaoDAO.hpp"
#include "fornecedor.hpp"
#include "movimentacao.hpp"
#include "fornecedorDAO.hpp"
#include "interfaceMNG.hpp"
#include "produtoDAO.hpp"

class MovimentacaoMNG{
private:
  InterfaceMNG* interfaceMNG;
  MovimentacaoDAO* movimentacaoDAO;  
  Movimentacao* movimentacaoAtual; 
  Produto* produto;
  Fornecedor* fornecedor;
  FornecedorDAO* fornecedorDAO;
  ProdutoDAO* produtoDAO;

public:
  void setFornecedorDao(FornecedorDAO*);
  void setProdutoDao(ProdutoDAO*);
  void setMovimentacaoDao(MovimentacaoDAO*);
  void setMovimentacaoAtual(Movimentacao*);
  Movimentacao* getMovimentacaoAtual();
  void iniciarRegistroSaida();
  void registrarSaidaProduto(Produto*, int, char*);
  void concluirMovimentacao();
  void iniciarRegistroEntrada();
  void registrarSaidaProdutos();
  void registrarEntradaProduto(Produto*, Fornecedor*, float, int, int, char*);
  void setProdutoAtual(Produto*);
  Produto* getProdutoAtual();



};
