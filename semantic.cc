#include "semantic.hh"
#include "arvore.hh"
#include "codeobject.hh"
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
#include "llvm/Support/FileSystem.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Utils.h"
#include <bits/types/FILE.h>
#include <fstream>
#include <llvm-13/llvm/ADT/StringRef.h>
#include <llvm-13/llvm/IR/GlobalValue.h>
#include <llvm-13/llvm/IR/Use.h>
#include <llvm-13/llvm/Support/raw_ostream.h>
#include <ostream>
#include <string.h>
#include <system_error>

using namespace AST;
using namespace codeobject;
using namespace llvm::sys;

namespace semantic {

void insereSimbolosPadroes(S_table tabelaSimbolos) {
  std::string inteiroStr = "inteiro";
  std::string realStr = "real";
  std::string cadeiaStr = "cadeia";
  std::string imprimeiFunc = "imprimei";

  S_symbol inteiroSim = S_Symbol(inteiroStr);
  S_symbol realSim = S_Symbol(realStr);
  S_symbol cadeiaSim = S_Symbol(cadeiaStr);
  S_symbol imprimeiSim = S_Symbol(imprimeiFunc);

  S_enter(tabelaSimbolos, inteiroSim, &inteiroStr[0]);
  S_enter(tabelaSimbolos, realSim, &realStr[0]);
  S_enter(tabelaSimbolos, cadeiaSim, &cadeiaStr[0]);
  S_enter(tabelaSimbolos, imprimeiSim, &imprimeiFunc[0]);
}

bool analiseDeclaracaoTipo(declaracaoTipoVetor tipos, S_table tabelaSimbolos) {
  if (!tipos->head->validar(tabelaSimbolos))
    return false;

  declaracaoTipoVetor aux = tipos->tail;
  while (aux != NULL) {
    if (!aux->head->validar(tabelaSimbolos))
      return false;

    aux = aux->tail;
  }

  return true;
}

bool analiseDeclaracaoGlobal(declaracaoVarVetor variaveis,
                             S_table tabelaSimbolos) {
  if (!variaveis->head->validar(tabelaSimbolos))
    return false;
  else {
    variaveis->head->traduzir(tabelaSimbolos);
  }

  declaracaoVarVetor aux = variaveis->tail;
  while (aux != NULL) {
    if (!aux->head->validar(tabelaSimbolos))
      return false;
    else {
      aux->head->traduzir(tabelaSimbolos);
    }

    aux = aux->tail;
  }

  return true;
}
bool analiseDeclaracaoFuncao(declaracaoFuncVetor funcoes) { return true; }

bool analiseDeclaracoes(declaracaoFuncVetor funcVetor,
                        declaracaoTipoVetor tipoVetor,
                        declaracaoVarVetor varVetor, S_table tabelaSimbolos) {

  if (!analiseDeclaracaoTipo(tipoVetor, tabelaSimbolos)) {
    std::cout << "Erro na semântica de declarações de tipo" << std::endl;
    return false;
  }

  if (!analiseDeclaracaoGlobal(varVetor, tabelaSimbolos)) {
    std::cout << "Erro na semântica de declarações de globais" << std::endl;
    return false;
  }

  if (!analiseDeclaracaoFuncao(funcVetor)) {
    std::cout << "Erro na semântica de declarações de funcoes" << std::endl;
    return false;
  }

  return true;
}

bool validacoesAcoes(Comando *comando, S_table tabelaSimbolos) {

  if (comando->comandoAtribuicao != NULL) {
    comando->comandoAtribuicao->validar(tabelaSimbolos);
    comando->comandoAtribuicao->traduzir(tabelaSimbolos);
  }

  else if (comando->nodeCallFunc != NULL) {
    comando->nodeCallFunc->validar(tabelaSimbolos);
    comando->nodeCallFunc->traduzir(tabelaSimbolos);
  } else {
    std::cout << "Comando não implementado!\n";
    return false;
  }

  return true;
}

void createMainFunction(std::shared_ptr<Module> TheModule,
                        std::shared_ptr<LLVMContext> TheContext,
                        std::shared_ptr<IRBuilder<>> Builder) {

  FunctionType *FT = FunctionType::get(Type::getVoidTy(*TheContext), false);

  Function *mainFunction = Function::Create(FT, GlobalValue::ExternalLinkage,
                                            "main", TheModule.get());

  std::vector<Type *> params;
  params.push_back(Type::getInt32Ty(*TheContext));
  FunctionType *type =
      FunctionType::get(Type::getVoidTy(*TheContext), params, false);

  Function::Create(type, Function::ExternalLinkage, "imprimei",
                   TheModule.get());

  BasicBlock *BB = BasicBlock::Create(*TheContext, "main", mainFunction);
  Builder->SetInsertPoint(BB);
}

bool analiseAcoes(comandosVetor acoes, S_table tabelaSimbolos) {
  validacoesAcoes(acoes->head, tabelaSimbolos);

  comandosVetor aux = acoes->tail;

  while (aux != NULL) {
    bool validado = validacoesAcoes(aux->head, tabelaSimbolos);

    if (!validado)
      return false;

    aux = aux->tail;
  }
  return true;
}

bool Inicializar(Programa *root, std::string filename,
                 bool imprimeIntermediario) {
  std::cout << "Inicializando análise semântica...\n" << std::endl;

  S_table _tabelaSimbolos = S_empty();

  // Inicialização das variáveis do LLVM
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();
  InitializeNativeTargetAsmParser();

  TheContext = std::make_shared<llvm::LLVMContext>();
  TheModule = std::make_shared<llvm::Module>(filename + ".s", *TheContext);
  Builder = std::make_shared<llvm::IRBuilder<>>(*TheContext);

  // Inserindo símbolos padrões na tabela de simbolos
  insereSimbolosPadroes(_tabelaSimbolos);

  createMainFunction(TheModule, TheContext, Builder);

  bool declaracoresCerta =
      analiseDeclaracoes(root->declaracoesFuncao, root->declaracoesTipo,
                         root->declaracoesGlobais, _tabelaSimbolos);
  if (!declaracoresCerta) {
    return false;
  }

  bool acoesCerta = analiseAcoes(root->acao, _tabelaSimbolos);
  if (!acoesCerta) {
    return false;
  }

  std::cout << "Análise semântica realizada com sucesso!\n" << std::endl;

  Builder->CreateRetVoid();

  inicializarCodeObject(TheModule, filename);

  if (imprimeIntermediario) {
    std::error_code error;
    llvm::raw_fd_ostream file(StringRef(filename + ".ll"), error);
    TheModule->print(file, nullptr);
    std::cout << "Código intermediário salvo no arquvo: " + filename + ".ll"
              << std::endl;
  }

  return true;
}

} // namespace semantic
