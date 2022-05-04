
#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include "symbol.hh"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <llvm-13/llvm/IR/Value.h>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

using namespace llvm;

namespace AST {

static std::unique_ptr<LLVMContext> TheContext;
static std::unique_ptr<IRBuilder<>> Builder;
static std::unique_ptr<Module> TheModule;
static std::map<std::string, Value *> NamedValues;

typedef struct declaracaoTipoVetor_ *declaracaoTipoVetor;
typedef struct declaracaoVarVetor_ *declaracaoVarVetor;
typedef struct declaracaoFuncVetor_ *declaracaoFuncVetor;
typedef struct comandosVetor_ *comandosVetor;
typedef struct argRegistroVetor_ *argRegistroVetor;
typedef struct exprVetor_ *exprVetor;
typedef struct tipoConstantes_ *tipoConstantes;
typedef struct tipoCamposVetor_ *tipoCamposVetor;
typedef struct argFuncVetor_ *argFuncVetor;

class ArgFunc {
public:
  std::string modificador;
  std::string identificador;
  std::string tipo;
  ArgFunc(std::string modificador, std::string identificador, std::string tipo)
      : modificador(modificador), identificador(identificador), tipo(tipo) {}
};

class DescritorTipo {

public:
  std::string identificador; // tipo identificador
  tipoCamposVetor campos;    // tipo registro
  tipoConstantes constantes; // tipo vetor
  std::string tipoVetor;     // tipo vetor

  std::string type;

  DescritorTipo(std::string identificador, tipoCamposVetor campos,
                tipoConstantes constantes, std::string tipoVetor,
                std::string type)
      : identificador(identificador), campos(campos), constantes(constantes),
        tipoVetor(tipoVetor), type(type) {}
};

class TipoCampos {
public:
  std::string identificador;
  std::string tipo;

  TipoCampos(std::string identificador, std::string tipo)
      : identificador(identificador), tipo(tipo) {}
};

// Expressões

class ListArgRegistro {
public:
  argRegistroVetor args;

  ListArgRegistro(argRegistroVetor args) : args(args) {}
};

class Literal {
public:
  std::string type;

  int inteiro;
  std::string cadeia;
  double real;

  Literal(std::string type, int inteiro, std::string cadeia, double real)
      : type(type), inteiro(inteiro), cadeia(cadeia), real(real) {}

  Value* traduzir () {
    return ConstantInt::get(*TheContext, APInt(32, inteiro, true));
  }
};

class NodeVar {
public:
  std::string name;

  NodeVar(const std::string name) : name(name) {}
};

class NodeCallFunc {
public:
  std::string nameFunc;
  exprVetor params;

  NodeCallFunc(const std::string nameFunc, exprVetor params)
      : nameFunc(nameFunc), params(params) {}
};

class NodeCriacaoRegistro {
public:
  argRegistroVetor args;

  NodeCriacaoRegistro(argRegistroVetor args) : args(args) {}
};

class LocalIdentificador {
public:
  std::string identificador;

  LocalIdentificador(std::string identificador)
      : identificador(identificador) {}
};

class LocalRegistro {
public:
  std::string propriedade;

  LocalRegistro(std::string propriedade) : propriedade(propriedade) {}
};

class LocalVetor {
public:
  exprVetor lista_expr;

  LocalVetor(exprVetor lista_expr) : lista_expr(lista_expr) {}
};

class LocalArmazenamento {
public:
  LocalArmazenamento *localArmazenamento;
  LocalRegistro *localRegistro;
  LocalVetor *localVetor;
  LocalIdentificador *localIdentificador;

  std::string type;

  LocalArmazenamento(LocalArmazenamento *localArmazenamento,
                     LocalRegistro *localRegistro, LocalVetor *localVetor,
                     LocalIdentificador *localIdentificador, std::string type)
      : localArmazenamento(localArmazenamento), localRegistro(localRegistro),
        localVetor(localVetor), localIdentificador(localIdentificador),
        type(type) {}

  void validar(S_table tabelaSimbolos) {
    if (localIdentificador != NULL) {
      S_symbol idSymbol = S_Symbol(localIdentificador->identificador);
      if (S_look(tabelaSimbolos, idSymbol) == NULL) {
        std::cout << "Nao achou local armazenamento" << std::endl;
        // Lançar um erro
      }
    }
  }
};

class NodeExpr {
public:
  std::string type;
  ListArgRegistro *listArgRe;
  Literal *literal;
  NodeVar *nodeVar;
  NodeExpr *exprEsq;
  std::string Op;
  NodeExpr *exprDir;
  NodeExpr *exprComParen;
  LocalArmazenamento *localArmazenamento;
  NodeCallFunc *nodeCallFunc;
  NodeCriacaoRegistro *nodeCriacaoRegistro;

  NodeExpr(std::string type, ListArgRegistro *listArgRe, Literal *literal,
           NodeVar *nodeVar, NodeExpr *exprEsq, std::string Op,
           NodeExpr *exprDir, NodeExpr *exprComParen,
           LocalArmazenamento *localArmazenamento, NodeCallFunc *nodeCallFunc,
           NodeCriacaoRegistro *nodeCriacaoRegistro)
      : type(type), listArgRe(listArgRe), literal(literal), nodeVar(nodeVar),
        exprEsq(exprEsq), Op(Op), exprDir(exprDir), exprComParen(exprComParen),
        localArmazenamento(localArmazenamento), nodeCallFunc(nodeCallFunc),
        nodeCriacaoRegistro(nodeCriacaoRegistro) {}

  void validar() {
    if (literal != NULL) {
      std::cout << "Validando node expr" << std::endl;
    }
  }

  Value* traduzir () {
    return literal->traduzir();
  }
};  

class ArgRegistro {
public:
  std::string identificador;
  NodeExpr expr;

  ArgRegistro(std::string identificador, NodeExpr expr)
      : identificador(identificador), expr(expr) {}
};

class ComandoAtribuicao {
public:
  LocalArmazenamento *identificador;
  NodeExpr *valorExpr;

  ComandoAtribuicao(LocalArmazenamento *identificador, NodeExpr *valorExpr)
      : identificador(identificador), valorExpr(valorExpr) {}

  void validar(S_table tabelaSimbolos) {
    identificador->validar(tabelaSimbolos);
    valorExpr->validar();
  }

  Value* traduzir() {
    return valorExpr->traduzir();
  }
};

class ComandoIf {
public:
  NodeExpr expr;
  comandosVetor comandos;

  ComandoIf(NodeExpr expr, comandosVetor comandos)
      : expr(expr), comandos(comandos) {}
};

class ComandoIfElse {
public:
  NodeExpr expr;
  comandosVetor comandos;
  comandosVetor comandosElse;
  ComandoIfElse(NodeExpr expr, comandosVetor comandos,
                comandosVetor comandosElse)
      : expr(expr), comandos(comandos), comandosElse(comandosElse) {}
};

class ComandoFor {
public:
  std::string identificador;
  NodeExpr exprInicio;
  NodeExpr exprLimite;
  comandosVetor comandos;
  ComandoFor(std::string identificador, NodeExpr exprInicio,
             NodeExpr exprLimite, comandosVetor comandos)
      : identificador(identificador), exprInicio(exprInicio),
        exprLimite(exprLimite), comandos(comandos) {}
};

class ComandoWhile {
public:
  NodeExpr expr;
  comandosVetor comandos;
  ComandoWhile(NodeExpr expr, comandosVetor comandos)
      : expr(expr), comandos(comandos) {}
};

class ComandoPare {
public:
  ComandoPare() {}
};

class ComandoContinue {
public:
  ComandoContinue() {}
};

class ComandoRetorne {
public:
  NodeExpr valorRetorno;

  ComandoRetorne(NodeExpr valorRetorno) : valorRetorno(valorRetorno) {}
};

class Comando {
public:
  ComandoAtribuicao *comandoAtribuicao;
  ComandoIf *comandoIf;
  ComandoIfElse *comandoIfElse;
  ComandoFor *comandoFor;
  ComandoWhile *comandoWhile;
  ComandoPare *comandoPare;
  ComandoContinue *comandoContinue;
  ComandoRetorne *comandoRetorne;
  NodeCallFunc *nodeCallFunc;

  std::string type;

  Comando(ComandoAtribuicao *comandoAtribuicao, ComandoIf *comandoIf,
          ComandoIfElse *comandoIfElse, ComandoFor *comandoFor,
          ComandoWhile *comandoWhile, ComandoPare *comandoPare,
          ComandoContinue *comandoContinue, ComandoRetorne *comandoRetorne,
          NodeCallFunc *nodeCallFunc, std::string type)
      : comandoAtribuicao(comandoAtribuicao), comandoIf(comandoIf),
        comandoIfElse(comandoIfElse), comandoFor(comandoFor),
        comandoWhile(comandoWhile), comandoPare(comandoPare),
        comandoContinue(comandoContinue), comandoRetorne(comandoRetorne),
        nodeCallFunc(nodeCallFunc), type(type) {}
};

class DeclaracaoVar {
public:
  std::string identificador;
  std::string tipo;
  NodeExpr valor;
  DeclaracaoVar(std::string identificador, std::string tipo, NodeExpr valor)
      : identificador(identificador), tipo(tipo), valor(valor) {}
};

class Corpo {
public:
  declaracaoVarVetor declaracoes;
  comandosVetor comandos;

  Corpo(declaracaoVarVetor declaracoes, comandosVetor comandos)
      : declaracoes(declaracoes), comandos(comandos) {}
};

class DeclaracaoTipo {
public:
  std::string identificador;
  DescritorTipo tipo;

  bool validar(S_table tabelaSimbolos) {

    S_symbol idSymbol = S_Symbol(identificador);

    if (S_look(tabelaSimbolos, idSymbol) == NULL) {
      S_enter(tabelaSimbolos, idSymbol, &identificador[0]);

    } else {
      std::cout << "\nErro: Tipo" << identificador << "já foi declarado." << std::endl; 
      return false;
    }

    S_symbol tipoSymbol = S_Symbol(tipo.identificador);

    if (S_look(tabelaSimbolos, tipoSymbol) == NULL) {
      std::cout << "\nErro: Não foi possível encontrar o tipo" << tipo.identificador << std::endl;
      return false;
    }

    return true;
  };

  DeclaracaoTipo(std::string identificador, DescritorTipo tipo)
      : identificador(identificador), tipo(tipo) {}
};

class AbstractDeclacaoFuncao {
public:
  // Declaracao funcao e procedimento
  std::string nome;
  argFuncVetor args;
  std::string identificador; // Somente função
  Corpo *corpo;

  std::string type;

  AbstractDeclacaoFuncao(std::string nome, argFuncVetor args,
                         std::string identificador, Corpo *corpo,
                         std::string type)
      : nome(nome), args(args), identificador(identificador), corpo(corpo),
        type(type) {}
};

struct declaracaoTipoVetor_ {
  DeclaracaoTipo *head;
  declaracaoTipoVetor tail;
};

struct declaracaoVarVetor_ {
  DeclaracaoVar *head;
  declaracaoVarVetor tail;
};

struct declaracaoFuncVetor_ {
  AbstractDeclacaoFuncao *head;
  declaracaoFuncVetor tail;
};

struct comandosVetor_ {
  Comando *head;
  comandosVetor tail;
};

struct argRegistroVetor_ {
  ArgRegistro *head;
  argRegistroVetor tail;
};

struct exprVetor_ {
  NodeExpr *head;
  exprVetor tail;
};

struct tipoConstantes_ {
  int head;
  tipoConstantes tail;
};

struct tipoCamposVetor_ {
  TipoCampos *head;
  tipoCamposVetor tail;
};

struct argFuncVetor_ {
  ArgFunc *head;
  argFuncVetor tail;
};

// programa
class Programa {
public:
  declaracaoTipoVetor declaracoesTipo;
  declaracaoVarVetor declaracoesGlobais;
  declaracaoFuncVetor declaracoesFuncao;
  comandosVetor acao;

  Programa(declaracaoTipoVetor declaracoesTipo,
           declaracaoVarVetor declaracoesGlobais,
           declaracaoFuncVetor declaracoesFuncao, comandosVetor acao)
      : declaracoesTipo(declaracoesTipo),
        declaracoesGlobais(declaracoesGlobais),
        declaracoesFuncao(declaracoesFuncao), acao(acao) {}
};

/* function prototypes */
extern declaracaoVarVetor DeclaracaoVarVetor(DeclaracaoVar head,
                                             declaracaoVarVetor tail);
extern declaracaoFuncVetor DeclaracaoFuncVetor(AbstractDeclacaoFuncao head,
                                               declaracaoFuncVetor tail);
extern comandosVetor ComandosVetor(Comando head, comandosVetor tail);
extern exprVetor ExprVetor(NodeExpr head, exprVetor tail);
extern declaracaoTipoVetor DeclaracaoTipoVetor(DeclaracaoTipo head,
                                               declaracaoTipoVetor tail);
extern tipoConstantes TipoConstantes(int head, tipoConstantes tail);
extern tipoCamposVetor TipoCamposVetor(TipoCampos head, tipoCamposVetor tail);
extern argFuncVetor ArgFuncVetor(ArgFunc head, argFuncVetor tail);
extern argRegistroVetor ArgRegistroVetor(ArgRegistro head,
                                         argRegistroVetor tail);

extern Programa *ast_root;
} // namespace AST

#endif // MYCOMPILER_ABSYNTREE_H
