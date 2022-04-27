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
// VAMOS FAZER TODO O COMPILADOR PARA A DECLARAÇÕES DE TIPO
// VALIDAR
// TRADUZIR (LLVM)

using namespace AST;

namespace semantic {
bool Inicializar(Programa root) {
  TheContext = std::make_unique<llvm::LLVMContext>();
  TheModule = std::make_unique<llvm::Module>("my cool jit", *TheContext);
  Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);

  insereSimbolosPadroes();
  declaracaoTipoVetor aux = root.declaracoes.declaracoesTipo->tail;
  root.declaracoes.declaracoesTipo->head.validar();
  while (aux != NULL) {

    bool validado = aux->head.validar();

    if (!validado) {
      printf("Erro na análise semântica\n");
      return false; // Lançar um erro
    }

    Value *traduzido = aux->head.traduzir();

    if (traduzido == NULL) {
      printf("Erro: Não foi possível traduzir para código intermediário\n");
      return false;
    }

    aux = aux->tail;
  }

  return true;
}
} // namespace semantic