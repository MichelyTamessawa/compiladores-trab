#include "semantic.hh"
#include "arvore.hh"
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
#include <llvm-13/llvm/IR/Use.h>
#include <string.h>
using namespace AST;

namespace semantic {

void insereSimbolosPadroes(S_table tabelaSimbolos) {

  std::string inteiroStr = "inteiro";
  std::string realStr = "real";
  std::string cadeiaStr = "cadeia";

  S_symbol inteiroSim = S_Symbol(inteiroStr);
  S_symbol realSim = S_Symbol(realStr);
  S_symbol cadeiaSim = S_Symbol(cadeiaStr);

  S_enter(tabelaSimbolos, inteiroSim, &inteiroStr[0]);
  S_enter(tabelaSimbolos, realSim, &realStr[0]);
  S_enter(tabelaSimbolos, cadeiaSim, &cadeiaStr[0]);
}

bool analiseDeclaracaoTipo(declaracaoTipoVetor tipos, S_table tabelaSimbolos) {
  if (!tipos->head.validar(tabelaSimbolos))
    return false;

  declaracaoTipoVetor aux = tipos->tail;
  while (aux != NULL) {
    if (!aux->head.validar(tabelaSimbolos))
      return false;

    aux = aux->tail;
  }

  return true;
}

bool analiseDeclaracaoGlobal(declaracaoVarVetor variaveis) { return true; }
bool analiseDeclaracaoFuncao(declaracaoFuncVetor funcoes) { return true; }

bool analiseDeclaracoes(Declaracoes declaracoes, S_table tabelaSimbolos) {

  if (!analiseDeclaracaoTipo(declaracoes.declaracoesTipo, tabelaSimbolos)) {
    printf("Erro na semântica de declarações de tipo\n");
    return false;
  }

  if (!analiseDeclaracaoGlobal(declaracoes.declaracoesGlobais)) {
    printf("Erro na semântica de declarações de tipo\n");
    return false;
  }

  if (!analiseDeclaracaoFuncao(declaracoes.declaracoesFuncao)) {
    printf("Erro na semântica de declarações de tipo\n");
    return false;
  }

  return true;
}

bool analiseAcoes(comandosVetor acoes) {

  if (std::strcmp(acoes->head.type.c_str(), "atribuicao") == 0) {
    printf("Sim\n");
    ComandoAtribuicao *comando =
        dynamic_cast<ComandoAtribuicao *>(&acoes->head);

    printf("Deu bom\n");

    if (comando == NULL)
      printf("aiai em\n");
  }

  return true;
}

bool Inicializar(Programa *root) {
  printf("Inicializando análise semântica...\n");

  S_table _tabelaSimbolos = S_empty();

  // Inicialização das variáveis do LLVM
  TheContext = std::make_unique<llvm::LLVMContext>();
  TheModule = std::make_unique<llvm::Module>("my cool jit", *TheContext);
  Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);

  // Inserindo símbolos padrões na tabela de simbolos
  insereSimbolosPadroes(_tabelaSimbolos);

  bool declaracoresCerta =
      analiseDeclaracoes(root->declaracoes, _tabelaSimbolos);
  if (!declaracoresCerta) {
    return false;
  }

  bool acoesCerta = analiseAcoes(root->acao);
  if (!acoesCerta) {
    return false;
  }

  printf("Análise semântica realizada com sucesso\n");

  return true;
}

} // namespace semantic
