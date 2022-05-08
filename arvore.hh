
#ifndef ARVORE_H
#define ARVORE_H

#include "biblioteca.hh"
#include "symbol.hh"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <llvm-13/llvm/IR/Instructions.h>
#include <llvm-13/llvm/IR/Value.h>
#include <llvm-13/llvm/Support/Casting.h>
#include <map>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

using namespace llvm;

namespace AST {

static std::shared_ptr<LLVMContext> TheContext;
static std::shared_ptr<IRBuilder<>> Builder;
static std::shared_ptr<Module> TheModule;
static std::map<std::string, AllocaInst *> NamedValues;
static std::unique_ptr<legacy::FunctionPassManager> TheFPM;

typedef struct declaracaoTipoVetor_ *declaracaoTipoVetor;
typedef struct declaracaoVarVetor_ *declaracaoVarVetor;
typedef struct declaracaoFuncVetor_ *declaracaoFuncVetor;
typedef struct comandosVetor_ *comandosVetor;
typedef struct argRegistroVetor_ *argRegistroVetor;
typedef struct exprVetor_ *exprVetor;
typedef struct tipoConstantes_ *tipoConstantes;
typedef struct tipoCamposVetor_ *tipoCamposVetor;
typedef struct argFuncVetor_ *argFuncVetor;

static AllocaInst *CreateEntryBlockIntAlloca(Function *TheFunction,
                                             const std::string &VarName) {
  IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
                   TheFunction->getEntryBlock().begin());
  return TmpB.CreateAlloca(Type::getInt32Ty(*TheContext), 0, VarName.c_str());
}

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

  Value *traduzir() {
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
  bool validar(S_table tabelaDeSimbolos) {
    S_symbol nameFuncSim = S_Symbol(nameFunc);

    if (S_look(tabelaDeSimbolos, nameFuncSim) == NULL) {
      std::cout << "Função não declarada" << std::endl;
      return false;
    }

    // validar parametros
    return true;
  }

  void traduzir(S_table tabelaDeSimbolos);
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

  AllocaInst *traduzir() { return NamedValues[identificador]; }
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

  bool validar(S_table tabelaSimbolos) {

    if (localIdentificador != NULL) {
      S_symbol idSymbol = S_Symbol(localIdentificador->identificador);
      if (S_look(tabelaSimbolos, idSymbol) == NULL) {
        std::cout << "Variável não definida." << std::endl;
        return false;
      }
    }

    return true;
  }

  AllocaInst *traduzir() {
    if (localIdentificador != NULL)
      return localIdentificador->traduzir();

    throw;
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

  bool validar() {
    // ver se o tipo do literal é o mesmo da variável
    return true;
  }

  inline Value *traduzir(S_table tabelaDeSimbolos);
};

inline Value *traduzirOpBinaria(NodeExpr *esq, std::string op, NodeExpr *dir,
                                S_table tabelaDeSimbolos) {
  Value *vEsq = esq->traduzir(tabelaDeSimbolos);
  Value *vDir = dir->traduzir(tabelaDeSimbolos);

  if (!vEsq || !vDir) {
    std::cout << "Operação binária falhou" << std::endl;
    throw;
  }

  if (op.compare("+") == 0) {
    return Builder->CreateAdd(vEsq, vDir);
  } else if (op.compare("-") == 0) {
    return Builder->CreateSub(vEsq, vDir);
  } else if (op.compare("*") == 0) {
    return Builder->CreateMul(vEsq, vDir);
  }

  std::cout << "Operador binário não reconhecido" << std::endl;
  throw;
}

Value *NodeExpr::traduzir(S_table tabelaDeSimbolos) {
  if (literal != NULL)
    return literal->traduzir();

  if (localArmazenamento != NULL) {
    Value *aux = (Value *)S_look(
        tabelaDeSimbolos,
        S_Symbol(localArmazenamento->localIdentificador->identificador));
    return aux;
  }
  if (exprEsq != NULL && exprDir != NULL) {
    return traduzirOpBinaria(exprEsq, Op, exprDir, tabelaDeSimbolos);
  }
  throw;
}

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

  bool validar(S_table tabelaSimbolos) {
    if (!identificador->validar(tabelaSimbolos))
      return false;
    if (!valorExpr->validar())
      return false;

    return true;
  }

  void traduzir(S_table tabelaDeSimbolos) {
    Function *TheFunction = Builder->GetInsertBlock()->getParent();

    Value *var = identificador->traduzir();
    Value *valor = valorExpr->traduzir(tabelaDeSimbolos);

    S_enter(tabelaDeSimbolos,
            S_Symbol(identificador->localIdentificador->identificador), valor);

    Builder->CreateStore(valor, var);
    verifyFunction(*TheFunction);
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

  bool validar(S_table tabelaDeSimbolos) {
    S_symbol symbol = S_Symbol(identificador);

    if (S_look(tabelaDeSimbolos, symbol) == NULL) {
      S_enter(tabelaDeSimbolos, symbol, &identificador[0]);
    } else {
      std::cout << "Variável já declarada!" << std::endl;
      return false;
    }

    S_symbol tipoSymbol = S_Symbol(tipo);

    if (S_look(tabelaDeSimbolos, tipoSymbol) == NULL) {
      std::cout << "Tipo da variável não declarado!" << std::endl;
      return false;
    }

    return true;
  }

  void traduzir(S_table tabelaDeSimbolos) {
    Function *TheFunction = Builder->GetInsertBlock()->getParent();
    AllocaInst *Alloca = CreateEntryBlockIntAlloca(TheFunction, identificador);
    NamedValues[identificador] = Alloca;
    AllocaInst *aux = NamedValues[identificador];

    Builder->CreateLoad(Type::getInt32Ty(*TheContext), aux,
                        identificador.c_str());

    Value *auxValor = valor.traduzir(tabelaDeSimbolos);

    S_enter(tabelaDeSimbolos, S_Symbol(identificador), auxValor);

    Builder->CreateStore(auxValor, Alloca);
  }
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
      std::cout << "\nErro: Tipo" << identificador << "já foi declarado."
                << std::endl;
      return false;
    }

    S_symbol tipoSymbol = S_Symbol(tipo.identificador);

    if (S_look(tabelaSimbolos, tipoSymbol) == NULL) {
      std::cout << "\nErro: Não foi possível encontrar o tipo"
                << tipo.identificador << std::endl;
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

inline void NodeCallFunc::traduzir(S_table tabelaDeSimbolos) {

  if (nameFunc.compare("imprimei") == 0) {

    NodeExpr *expr = params->head;

    if (expr->literal != NULL) {
      int valor = 0;

      valor = expr->literal->inteiro;
      SimplesBiblioteca::imprimei(valor, TheModule, TheContext, Builder);
    } else if (expr->localArmazenamento != NULL) {
      std::string identificador =
          expr->localArmazenamento->localIdentificador->identificador;
      Value *aux = (Value *)S_look(tabelaDeSimbolos, S_Symbol(identificador));
      SimplesBiblioteca::imprimei(aux, TheModule, TheContext, Builder);
    }
  }
}

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
