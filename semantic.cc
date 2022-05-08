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

void insereSimbolosPadroes(S_table tabelaSimbolosFunc,
                           S_table tabelaSimbolosTipo) {
  std::string inteiroStr = "inteiro";
  std::string realStr = "real";
  std::string cadeiaStr = "cadeia";
  std::string imprimeiFunc = "imprimei";
  std::string imprimerFunc = "imprimer";
  std::string gereIntFunc = "gere_inteiro";
  std::string inverterFunc = "inverter";

  S_symbol inteiroSim = S_Symbol(inteiroStr);
  S_symbol realSim = S_Symbol(realStr);
  S_symbol cadeiaSim = S_Symbol(cadeiaStr);
  S_symbol imprimeiSim = S_Symbol(imprimeiFunc);
  S_symbol imprimerSim = S_Symbol(imprimerFunc);
  S_symbol gereIntSim = S_Symbol(gereIntFunc);
  S_symbol inverterSim = S_Symbol(inverterFunc);

  S_enter(tabelaSimbolosTipo, inteiroSim, &inteiroStr[0]);
  S_enter(tabelaSimbolosTipo, realSim, &realStr[0]);
  S_enter(tabelaSimbolosTipo, cadeiaSim, &cadeiaStr[0]);
  S_enter(tabelaSimbolosFunc, imprimeiSim, &imprimeiFunc[0]);
  S_enter(tabelaSimbolosFunc, imprimerSim, &imprimerFunc[0]);
  S_enter(tabelaSimbolosFunc, gereIntSim, &gereIntFunc[0]);
  S_enter(tabelaSimbolosFunc, inverterSim, &inverterFunc[0]);
}

bool analiseDeclaracaoTipo(declaracaoTipoVetor tipos, S_table tabelaSimbolos) {
  // Valida a primeira declaração de tipo
  if (tipos == NULL)
    return true;

  if (!tipos->head->validar(tabelaSimbolos))
    return false;

  declaracaoTipoVetor aux = tipos->tail;

  // Valida o restante das declarações de tipo
  while (aux != NULL) {
    if (!aux->head->validar(tabelaSimbolos))
      return false;

    aux = aux->tail;
  }

  return true;
}

bool analiseDeclaracaoGlobal(declaracaoVarVetor variaveis,
                             S_table tabelaSimbolosTipo,
                             S_table tabelaSimbolosVar) {
  if (variaveis == NULL)
    return true;

  // Analisa a primeira declaração de global
  if (!variaveis->head->validar(tabelaSimbolosVar, tabelaSimbolosTipo))
    return false;
  else
    variaveis->head->traduzir(tabelaSimbolosVar);

  declaracaoVarVetor aux = variaveis->tail;

  // Analisa o restante das declarações globais
  while (aux != NULL) {
    if (!aux->head->validar(tabelaSimbolosVar, tabelaSimbolosTipo))
      return false;
    else
      aux->head->traduzir(tabelaSimbolosVar);

    aux = aux->tail;
  }

  return true;
}

bool analiseDeclaracaoFuncao(declaracaoFuncVetor funcoes) { return true; }

bool analiseDeclaracoes(declaracaoFuncVetor funcVetor,
                        declaracaoTipoVetor tipoVetor,
                        declaracaoVarVetor varVetor, S_table tabelaSimbolosTipo,
                        S_table tabelaSimbolosVar) {

  // Valida as declações de tipo
  if (!analiseDeclaracaoTipo(tipoVetor, tabelaSimbolosTipo)) {
    std::cout << "Erro na semântica de declarações de tipo" << std::endl;
    return false;
  }

  // Valida as declarações de variáveis globais
  if (!analiseDeclaracaoGlobal(varVetor, tabelaSimbolosTipo,
                               tabelaSimbolosVar)) {
    std::cout << "Erro na semântica de declarações de globais" << std::endl;
    return false;
  }

  // Valida as declações de função (Não foi implementado)
  if (!analiseDeclaracaoFuncao(funcVetor)) {
    std::cout << "Erro na semântica de declarações de funcoes" << std::endl;
    return false;
  }

  return true;
}

bool validaTraduzAcoes(Comando *comando, S_table tabelaVar,
                       S_table tabelaFunc) {

  if (comando->comandoAtribuicao != NULL) {
    comando->comandoAtribuicao->validar(tabelaVar);
    comando->comandoAtribuicao->traduzir(tabelaVar);
  }

  else if (comando->nodeCallFunc != NULL) {
    comando->nodeCallFunc->validar(tabelaFunc);
    comando->nodeCallFunc->traduzir(tabelaVar);
  } else {
    std::cout << "Comando não implementado!\n";
    return false;
  }

  return true;
}

void createImprimeIFunction(std::shared_ptr<Module> TheModule,
                            std::shared_ptr<LLVMContext> TheContext) {
  std::vector<Type *> params;
  params.push_back(Type::getInt32Ty(*TheContext));
  FunctionType *type =
      FunctionType::get(Type::getVoidTy(*TheContext), params, false);

  Function::Create(type, Function::ExternalLinkage, "imprimei",
                   TheModule.get());
}

void createImprimeRFunction(std::shared_ptr<Module> TheModule,
                            std::shared_ptr<LLVMContext> TheContext) {
  std::vector<Type *> params;
  params.push_back(Type::getFloatTy(*TheContext));
  FunctionType *type =
      FunctionType::get(Type::getVoidTy(*TheContext), params, false);

  Function::Create(type, Function::ExternalLinkage, "imprimer",
                   TheModule.get());
}

void createGeraIntFunction(std::shared_ptr<Module> TheModule,
                           std::shared_ptr<LLVMContext> TheContext) {
  std::vector<Type *> params;
  FunctionType *type =
      FunctionType::get(Type::getInt32Ty(*TheContext), params, false);

  Function::Create(type, Function::ExternalLinkage, "gere_inteiro",
                   TheModule.get());
}

void createInverterFunction(std::shared_ptr<Module> TheModule,
                            std::shared_ptr<LLVMContext> TheContext) {
  std::vector<Type *> params;
  params.push_back(Type::getInt32Ty(*TheContext));
  FunctionType *type =
      FunctionType::get(Type::getInt32Ty(*TheContext), params, false);

  Function::Create(type, Function::ExternalLinkage, "inverter",
                   TheModule.get());
}

void createFunctions(std::shared_ptr<Module> TheModule,
                     std::shared_ptr<LLVMContext> TheContext,
                     std::shared_ptr<IRBuilder<>> Builder) {

  // Criação do imprimei
  createImprimeIFunction(TheModule, TheContext);

  // Criação do imprimer
  createImprimeRFunction(TheModule, TheContext);

  // Criação do gere_inteiro
  createGeraIntFunction(TheModule, TheContext);

  // Criação do inverter
  createInverterFunction(TheModule, TheContext);

  // Criação da Main
  FunctionType *FT = FunctionType::get(Type::getVoidTy(*TheContext), false);
  Function *mainFunction = Function::Create(FT, GlobalValue::ExternalLinkage,
                                            "main", TheModule.get());

  // Inserção do bloco básico
  BasicBlock *BB = BasicBlock::Create(*TheContext, "main", mainFunction);
  Builder->SetInsertPoint(BB);
}

bool analiseAcoes(comandosVetor acoes, S_table tabelaVar, S_table tabelaFunc) {
  // Faz a validação e tradução para a primeira ação
  validaTraduzAcoes(acoes->head, tabelaVar, tabelaFunc);

  comandosVetor aux = acoes->tail;

  // Faz a validação e tradução para o restante das ações
  while (aux != NULL) {
    bool validado = validaTraduzAcoes(aux->head, tabelaVar, tabelaFunc);

    if (!validado)
      return false;

    aux = aux->tail;
  }
  return true;
}

bool Inicializar(Programa *root, std::string filename,
                 bool imprimeIntermediario) {
  std::cout << "- Inicializando análise semântica..." << std::endl;

  // Inicializa a tabela de símbolos
  S_table _tabelaSimbolosVar = S_empty();
  S_table _tabelaSimbolosTipo = S_empty();
  S_table _tabelaSimbolosFunc = S_empty();

  // Inicialização das variáveis do LLVM
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();
  InitializeNativeTargetAsmParser();

  TheContext = std::make_shared<llvm::LLVMContext>();
  TheModule = std::make_shared<llvm::Module>(filename + ".s", *TheContext);
  Builder = std::make_shared<llvm::IRBuilder<>>(*TheContext);

  // Inserindo símbolos padrões na tabela de simbolos
  insereSimbolosPadroes(_tabelaSimbolosFunc, _tabelaSimbolosTipo);

  // Criação das funções principais do programa
  createFunctions(TheModule, TheContext, Builder);

  // Análise semântica das declarações -> Validações e traduções
  bool declaracoresCerta = analiseDeclaracoes(
      root->declaracoesFuncao, root->declaracoesTipo, root->declaracoesGlobais,
      _tabelaSimbolosTipo, _tabelaSimbolosVar);
  if (!declaracoresCerta) {
    return false;
  }

  // Análise semântica das ações -> Validações e traduções
  bool acoesCerta =
      analiseAcoes(root->acao, _tabelaSimbolosVar, _tabelaSimbolosFunc);
  if (!acoesCerta) {
    return false;
  }

  std::cout << "- Análise semântica realizada com sucesso!\n" << std::endl;

  // Adicionando um retorno void para a main. Necessário para não dar
  // segmentation fault.
  Builder->CreateRetVoid();

  std::cout << "- Inicializando geração de arquivos...\n" << std::endl;

  // Realiza a geração do arquivo objeto
  inicializarCodeObject(TheModule, filename);

  // Impressão do código intermediário
  if (imprimeIntermediario) {
    std::error_code error;
    llvm::raw_fd_ostream file(StringRef(filename + ".ll"), error);
    TheModule->print(file, nullptr);
    std::cout << "- Código intermediário salvo no arquivo: " + filename + ".ll"
              << std::endl;
  }

  return true;
}

} // namespace semantic
