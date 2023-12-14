#pragma once
#include "movimentacaoDAO.hpp"
#include "fornecedor.hpp"
#include "produtoMNG.hpp"
#include "movimentacao.hpp"
#include "fornecedorDAO.hpp"
#include "interfaceMNG.hpp"
#include "produtoDAO.hpp"
#include "fornecedorMNG.hpp"

class MovimentacaoMNG{
private:
  InterfaceMNG* interfaceMNG = new InterfaceMNG();
  MovimentacaoDAO* movimentacaoDAO = new MovimentacaoDAO();  
  Movimentacao* movimentacao = new Movimentacao(); 
  Produto* produto = new Produto();
  Fornecedor* fornecedor = new Fornecedor();
  FornecedorMNG* fornecedorMNG = new FornecedorMNG();
  FornecedorDAO* &fornecedorDAO = this->fornecedorMNG->fornecedorDAO;
  ProdutoMNG* produtoMNG = new ProdutoMNG();
  ProdutoDAO* &produtoDAO = this->produtoMNG->produtoDAO;

  void setMovimentacaoAtual(Movimentacao*);
  Movimentacao* getMovimentacaoAtual();
  void iniciarRegistroSaida();
  void registrarSaidaProduto(Produto, int, char*);
  void concluirMovimentacao();
  void iniciarRegistroEntrada();
  void registrarSaidaProdutos();
  void registrarEntradaProduto(Produto, Fornecedor, float, int, int, char*);
  void setProdutoAtual(Produto*);
  Produto* getProdutoAtual();
public:

  Produto* queryByNome(char*);
  Fornecedor* queryByRazaoSocial(char*);
  void registrarSaida();
  void registrarEntrada();


};
