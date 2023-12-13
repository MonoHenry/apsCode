#pragma once
#include "movimentacaoDAO.hpp"
#include "fornecedor.hpp"
#include "produtoDAO.hpp"
#include "movimentacao.hpp"
#include "fornecedorDAO.hpp"
#include "interfaceMNG.hpp"

class MovimentacaoMNG{
private:
  InterfaceMNG* interfaceMNG = new InterfaceMNG();
  MovimentacaoDAO* movimentacaoDAO = new MovimentacaoDAO();  
  Movimentacao movimentacao; 
  Produto* produto = new Produto();
  Fornecedor* fornecedor = new Fornecedor();
  FornecedorDAO* fornecedorDAO = new FornecedorDAO();
  ProdutoDAO* produtoDAO = new ProdutoDAO();

  void setMovimentacaoAtual(Movimentacao m1);
  Movimentacao getMovimentacaoAtual();
  void iniciarRegistroSaida();
  void registrarSaidaProduto(int, int, char*);
  void concluirMovimentacao();
  void iniciarRegistroEntrada();
  void registrarSaidaProdutos();
  void registrarEntradaProduto(int , int, float, int, int, char*);
public:

  Produto* consultarProdutos(char*);
  void registrarSaida();
  void registrarEntrada();


};
